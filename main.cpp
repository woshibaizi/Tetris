#pragma region ͷ�ļ�

using namespace std;
#include<easyx.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <vector>
#pragma comment(lib,"winmm.lib")

#pragma endregion

#pragma region ��Դ����
#define IDC_MYICON                      2
#define IDD_DEMO_DIALOG                 102
#define IDS_APP_TITLE                   103
#define IDD_ABOUTBOX                    103
#define IDM_ABOUT                       104
#define IDM_EXIT                        105
#define IDI_DEMO                        107
#define IDI_SMALL                       108
#define IDC_DEMO                        109
#define IDR_MAINFRAME                   128
#define IDB_BITMAP_START                135
#define IDB_BITMAP_ROCK                 137
#define IDB_BITMAP_BRICK                138
#define IDB_BITMAP_HELP                 145
#define IDB_BITMAP_JINGDIAN             146
#define IDB_BITMAP_KUANGBAO             147
#define IDB_BITMAP_TITLE                148
#define IDB_BITMAP_BACKGROUND           149
#define IDB_BITMAP_OPEN                 150
#define IDB_BITMAP_STUDY                151
#define IDB_BITMAP_TITLES               152
#define IDB_BITMAP__START               153
#define IDB_BITMAP__HELP                154
#define IDB_BITMAP_BACKGROUND2          155
#define IDB_BITMAP_BACK                 156
#define IDB_BITMAP_shuoming             157
#define IDB_BITMAP_CONTINUE             158
#define IDB_BITMAP_RESTART              159
#define IDB_BITMAP_BACKTO               160
#define IDB_BITMAP_END                  161
#define IDB_BITMAP_EXPLAIN              162
#define IDB_BITMAP_SHEZHI               163
#define IDB_BITMAP_SLOW                 164
#define IDB_BITMAP_MEDIUM               165
#define IDB_BITMAP_FAST                 166
#define IDB_BITMAP_1                    167
#define IDB_BITMAP_10                   168
#define IDB_BITMAP_TEN                  169
#define IDB_BITMAP_100                  170
#define IDB_BITMAP_EXPLAINED            171
#define IDB_BITMAP_BACKGROUND3          172
#define IDB_BITMAP_BACKGROUND4          173
#define IDB_BITMAP_CHALLENGE            174
#define IDB_BITMAP_PERFECT              175
#define IDB_BITMAP_GREAT                176
#define IDB_BITMAP_REGRETFUL            177
#define IDB_BITMAP_6                    178
#define IDB_BITMAP_666                  179
#define IDB_BITMAP_FAIL                 180
#define IDB_BITMAP_GIFT                 181
#define IDB_BITMAP_fubao                182
#define IDB_PNG1                        183
#define IDB_BITMAP_BARRIER              184
#define IDB_BITMAP1                     185
#define IDB_BITMAP_RROCK                185
#define IDB_BITMAP2                     186
#define IDB_BITMAP_TOHELP               186
#define IDC_STATIC                      -1

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NO_MFC                     1
#define _APS_NEXT_RESOURCE_VALUE        187
#define _APS_NEXT_COMMAND_VALUE         32771
#define _APS_NEXT_CONTROL_VALUE         1000
#define _APS_NEXT_SYMED_VALUE           110
#endif
#endif

#pragma endregion

#pragma region ����Ķ���
const int shape_T[4][4] = {
    {0,1,0,0},
    {1,1,1,0},
    {0,0,0,0},
    {0,0,0,0}
};
const int shape_O[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
const int shape_I[4][4] = {
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0},
    {0,1,0,0}
};
const int shape_S[4][4] = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
const int shape_Z[4][4] = {
    {1,1,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,0,0,0}
};
const int shape_L[4][4] = {
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,0,0,0}
};
const int shape_J[4][4] = {
    {0,1,0,0},
    {0,1,0,0},
    {1,1,0,0},
    {0,0,0,0}
};

#pragma endregion

#pragma region �궨��

// ����
#define WINDOW_TITLEBARHEIGHT 32 // �������߶�
#define WINDOW_WIDTH 1215        // ��Ϸ���ڿ��
#define WINDOW_HEIGHT 824        // ��Ϸ���ڸ߶�

// ��ʱ��
#define TIMER_GAMETIMER 1          // ��Ϸ��Ĭ�ϼ�ʱ��ID
#define TIMER_GAMETIMER_ELAPSE 70  // Ĭ�ϼ�ʱ��ˢ�¼���ĺ�����
#define TIMER_PAINTTIMER 2         
#define TIMER_PAINTTIMER_ELAPSE 20 

#define TIMER_ADJUST1 5
#define TIMER_ADJUST2 10
#define TIMER_ADJUST3 2

#define TIMER_SCORE1 1
#define TIMER_SCORE2 10
#define TIMER_SCORE3 100

// ��Ϸ�׶�
#define STAGE_START 0 // ��ʼ�����ID
#define STAGE_GAME 1  // ��һ����Ϸ������ID
#define STAGE_HELP 2
#define STAGE_BACK 3
#define STAGE_ESC 4
#define STAGE_END 5
#define STAGE_RESTART 6
#define STAGE_SHEZHI 7
#define STAGE_SHEZHI2 8
#define STAGE_CHALLENGE 9
#define STAGE_CHALLENGEEND 10
#define STAGE_BARRIEREND 11

// ����
#define BG_CELL_WIDTH 50                      // ����������
#define BG_CELL_HEIGHT 50                      // ��������߶�
#define BG_COLUMNS WINDOW_WIDTH / BG_CELL_WIDTH // ������X����ĵ�Ԫ����
#define BG_ROWS WINDOW_HEIGHT / BG_CELL_HEIGHT  // ������Y����ĵ�Ԫ����

// ש��
#define BLOCK_CELL_WIDTH 50                       // ש�鵥����
#define BLOCK_CELL_HEIGHT 50                        // ש�鵥��߶�
#define BLOCK_COLUMNS (WINDOW_WIDTH / BLOCK_CELL_WIDTH)*3/4 // ש����X����ĵ�Ԫ����
#define BLOCK_ROWS (WINDOW_HEIGHT / BLOCK_CELL_HEIGHT)  // ש����Y����ĵ�Ԫ����
#define BLOCK_FRAME_SIZE 4                            // ש�鶯��֡���еĴ�С
#define BLOCK_WIDTH   BLOCK_CELL_WIDTH* BLOCK_COLUMNS                    // ש����
#define BLOCK_HEIGHT BLOCK_CELL_HEIGHT*BLOCK_ROWS                        // ש��߶�

// ��ʼ��Ϸ��ť
#define BUTTON_STARTGAME_ID 1001                                              // ��ʼ��Ϸ��ťID
#define BUTTON_STARTGAME_WIDTH 257                                          // ��ʼ��Ϸ��ť���
#define BUTTON_STARTGAME_HEIGHT 102                                           // ��ʼ��Ϸ��ť�߶�
#define BUTTON_STARTGAME_X  800  // ��ʼ��Ϸ��ťX����
#define BUTTON_STARTGAME_Y   400// ��ʼ��Ϸ��ťY����

#define BUTTON_HELP_ID 13                                      
#define BUTTON_HELP_WIDTH 236                                       
#define BUTTON_HELP_HEIGHT 120
#define BUTTON_HELP_X  840  
#define BUTTON_HELP_Y 500

#define BUTTON_TITLE_ID 14
#define BUTTON_TITLE_WIDTH 900                                          
#define BUTTON_TITLE_HEIGHT 200                                       
#define BUTTON_TITLE_X  300 
#define BUTTON_TITLE_Y 30

#define BUTTON_BACKGROUND_ID 15
#define BUTTON_OPEN_ID 16
#define BUTTON_STUDY_ID 17
#define BUTTON_TITLES_ID 18
#define BUTTON_BACKGROUND2_ID 19

#define BUTTON_BACK_ID 20
#define BUTTON_BACK_WIDTH 262                                       
#define BUTTON_BACK_HEIGHT 636
#define BUTTON_BACK_X  840  
#define BUTTON_BACK_Y 50

#define BUTTON_SHUOMING_ID 21

#define BUTTON_CONTINUE_ID 22
#define BUTTON_CONTINUE_WIDTH 174                                       
#define BUTTON_CONTINUE_HEIGHT 105                                        
#define BUTTON_CONTINUE_X  750
#define BUTTON_CONTINUE_Y  350

#define BUTTON_RESTART_ID 23
#define BUTTON_RESTART_WIDTH 162                                       // ��ʼ��Ϸ��ť���
#define BUTTON_RESTART_HEIGHT 114                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_RESTART_X  800  // ��ʼ��Ϸ��ťX����
#define BUTTON_RESTART_Y  500

#define BUTTON_BACKTO_ID 24
#define BUTTON_BACKTO_WIDTH 158                                       // ��ʼ��Ϸ��ť���
#define BUTTON_BACKTO_HEIGHT 111                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_BACKTO_X  850  // ��ʼ��Ϸ��ťX����
#define BUTTON_BACKTO_Y  650

#define BUTTON_END_ID 25
#define BUTTON_EXPLAIN_ID 26

#define BUTTON_SHEZHI_ID 27
#define BUTTON_SHEZHI_WIDTH 208                                       // ��ʼ��Ϸ��ť���
#define BUTTON_SHEZHI_HEIGHT 205                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_SHEZHI_X  10  // ��ʼ��Ϸ��ťX����
#define BUTTON_SHEZHI_Y  600

#define BUTTON_SLOW_ID 28
#define BUTTON_SLOW_WIDTH 187                                       // ��ʼ��Ϸ��ť���
#define BUTTON_SLOW_HEIGHT 132                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_SLOW_X  650  // ��ʼ��Ϸ��ťX����
#define BUTTON_SLOW_Y  150

#define BUTTON_MEDIUM_ID 29
#define BUTTON_MEDIUM_WIDTH 178                                       // ��ʼ��Ϸ��ť���
#define BUTTON_MEDIUM_HEIGHT 134                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_MEDIUM_X  800  // ��ʼ��Ϸ��ťX����
#define BUTTON_MEDIUM_Y  300

#define BUTTON_FAST_ID 30
#define BUTTON_FAST_WIDTH 184                                       // ��ʼ��Ϸ��ť���
#define BUTTON_FAST_HEIGHT 128                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_FAST_X  650 // ��ʼ��Ϸ��ťX����
#define BUTTON_FAST_Y  450

#define BUTTON_1_ID 31
#define BUTTON_1_WIDTH 181                                       // ��ʼ��Ϸ��ť���
#define BUTTON_1_HEIGHT 125                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_1_X  650 // ��ʼ��Ϸ��ťX����
#define BUTTON_1_Y  150

#define BUTTON_10_ID 32
#define BUTTON_10_WIDTH 175                                     // ��ʼ��Ϸ��ť���
#define BUTTON_10_HEIGHT 123                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_10_X  800 // ��ʼ��Ϸ��ťX����
#define BUTTON_10_Y  300

#define BUTTON_100_ID 33
#define BUTTON_100_WIDTH 182                                    // ��ʼ��Ϸ��ť���
#define BUTTON_100_HEIGHT 120                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_100_X  650 // ��ʼ��Ϸ��ťX����
#define BUTTON_100_Y  450

#define BUTTON_EXPLAINED_ID  34
#define BUTTON_BACKGROUND4_ID  35

#define BUTTON_CHALLENGE_ID 36
#define BUTTON_CHALLENGE_WIDTH 453                                    // ��ʼ��Ϸ��ť���
#define BUTTON_CHALLENGE_HEIGHT 70                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_CHALLENGE_X  10 // ��ʼ��Ϸ��ťX����
#define BUTTON_CHALLENGE_Y  400

#define BUTTON_PERFECT_ID 37
#define BUTTON_666_ID 38
#define BUTTON_FAIL_ID 39

#define BUTTON_GIFT_ID 40
#define BUTTON_GIFT_WIDTH 198                                   // ��ʼ��Ϸ��ť���
#define BUTTON_GIFT_HEIGHT 201                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_GIFT_X  600 // ��ʼ��Ϸ��ťX����
#define BUTTON_GIFT_Y  200

#define BUTTON_BARRIER_ID 41
#define BUTTON_BARRIER_WIDTH 405                                   // ��ʼ��Ϸ��ť���
#define BUTTON_BARRIER_HEIGHT 116                                          // ��ʼ��Ϸ��ť�߶�
#define BUTTON_BARRIER_X  0 // ��ʼ��Ϸ��ťX����
#define BUTTON_BARRIER_Y  500

#define BUTTON_TOHELP_ID 42
// TODO: �����Ϸ��Ҫ�ĸ���궨��

#pragma endregion

#pragma region ȫ�ֱ���

#define MAX_LOADSTRING 100

// ȫ�ֱ�����
HINSTANCE hInst;                     // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];       // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING]; // ����������
int g_arrBackGround[WINDOW_HEIGHT][WINDOW_WIDTH] = { 0 };
int g_nScore = 0;
int SCORE = 0;
int type;
char Score[10];
int The_Stage = 0;
int count14 = 0;
int ADJUST = 0;
bool CONDITION1 = false;
bool CONDITION2 = false;
bool STARTCOUNT = false;
int count15 = 0;
int count16 = 0;
bool YES = false;
int mid = 0;
bool success = false;
bool STARTCOUNT1 = false;
int mid1 = 0;
bool YES1 = false;
int gift = 0;
bool FANBEI = false;
bool BARRIERCONDITION = false;

// λͼ��Դ��
HBITMAP bmp_StartButton;     // ��ʼ��ťͼ����Դ
HBITMAP bmp_Help;
HBITMAP bmp_JingDian;
HBITMAP bmp_KuangBao;
HBITMAP bmp_Rock;            // ʯͷͼ����Դ
HBITMAP bmp_Block;           // ש��ͼ����Դ
HBITMAP bmp_WhiteBackground; // ���ɵĴ���ɫ����ͼ��
HBITMAP bmp_GameBackground;  // ���ɵ���Ϸ����ͼ��
HBITMAP bmp_TITLE;
HBITMAP bmp_BACKGROUND;
HBITMAP bmp_OPEN;
HBITMAP bmp_STUDY;
HBITMAP bmp_TITLES;
HBITMAP bmp_BACKGROUND2;
HBITMAP bmp_BACK;
HBITMAP bmp_SHUOMING;
HBITMAP bmp_CONTINUE;
HBITMAP bmp_RESTART;
HBITMAP bmp_BACKTO;
HBITMAP bmp_END;
HBITMAP bmp_EXPLAIN;
HBITMAP bmp_SHEZHI;
HBITMAP bmp_SLOW;
HBITMAP bmp_MEDIUM;
HBITMAP bmp_FAST;
HBITMAP bmp_1;
HBITMAP bmp_10;
HBITMAP bmp_100;
HBITMAP bmp_EXPLAINED;
HBITMAP bmp_BACKGROUND3;
HBITMAP bmp_BACKGROUND4;
HBITMAP bmp_CHALLENGE;
HBITMAP bmp_PERFECT;
HBITMAP bmp_GREAT;
HBITMAP bmp_FAIL;
HBITMAP bmp_666;
HBITMAP bmp_GIFT;
HBITMAP bmp_BARRIER;
HBITMAP bmp_RROCK;
HBITMAP bmp_TOHELP;

// ���̣�
bool keyUp = false;    // ��
bool keyDown = false;  // ��
bool keyLeft = false;  // ��
bool keyRight = false; // ��
bool keyrotateLeft = false;//������ת90��
bool keyrotateRight = false;
bool keyESCdown = false;

// ��꣺
int mouseX = 0;         // ���X����
int mouseY = 0;         // ���Y����
bool mouseDown = false; // ��갴��

//�÷�
int score = 0;
#pragma endregion

#pragma region �ṹ�嶨��

//���巽������
enum Blocktype
{
    I, J, L, O, T, S, Z
};

//���巽��ṹ��
typedef struct {
    int shape[4][4];      // 4x4�����ʾ������״
    int cell_x, cell_y;   // �����x,y����
    int frame_index;      //��ǰ��ʾ֡�����ǵڼ���
    COLORREF color;       //��֪�Ƿ��õ���
    HBITMAP blockmap;
}Block;

Block* block = NULL;

//���峡���ṹ��
typedef struct {
    int stageID;      //����ID
    HBITMAP backgroundimg;//����ͼƬ
    bool pause;       //�Ƿ���ͣ����ʱ���Ƿ����У�
}Stage;

Stage* currentStage = NULL;

//���尴ť�ṹ��
typedef struct {
    int buttonID;
    HBITMAP buttonimg;
    int x;           //��ť����
    int y;
    int width;       //��ť��С
    int height;
}Button;

vector<Button*> buttons;   // ��ť

#pragma endregion

#pragma region �¼�����������

//��ʼ����Ϸ���庯��
void InitGame(HWND hwnd, WPARAM wparam, LPARAM lparam);
//���̰��´�����
void KeyDown(HWND hwnd, WPARAM wparam, LPARAM lparam);
//�����ɿ�������
void KeyUp(HWND hwnd, WPARAM wparam, LPARAM lparam);
//���������´�����
void LButtonDown(HWND hwnd, WPARAM wparam, LPARAM lparam);
//�������ɿ�������
void LButtonUp(HWND hwnd, WPARAM wparam, LPARAM lparam);
//����ƶ�������
void MouseMove(HWND hwnd, WPARAM wparam, LPARAM lparam);
//��ʱ���¼�������;
void TimerUpdate(HWND hwnd, WPARAM wparam, LPARAM lparam);
void PaintUpdate(HWND hwnd, WPARAM wparam, LPARAM lparam);

#pragma endregion

#pragma region ������Ϸ����״̬��������
//��ʼ����Ϸ��������
void InitStage(HWND hwnd, int stageID);

//��Ӱ�ť����
Button* CreatButton(int buttonID, HBITMAP buttonimg, int x, int y, int width, int height);

// ˢ��ש��״̬����
void UpdateBrick(HWND hWnd);
void PaintUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion

#pragma region ��������Դ������
void bgm()
{
    mciSendString(L"open ./nitaimei.mp3 alias bgm", 0, 0, 0);
    mciSendString(L"play bgm", 0, 0, 0);
}
//TODO:������Դ
#pragma endregion

#pragma region Win32������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DEMO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEMO));

    MSG msg;

    // ����Ϣѭ��:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex{};

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEMO));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DEMO);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

    HWND hWnd = CreateWindowW(
        szWindowClass, szTitle,
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        WINDOW_WIDTH,
        WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
        nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_CREATE   - �����ڴ����¼�
//  WM_TIMER    - ����ʱ��TimeOut�¼�
//  WM_PAINT    - ����������
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        // ��ʼ����Ϸ����
        InitGame(hWnd, wParam, lParam);
    }
    break;
    case WM_KEYDOWN:
    {
        // ���̰����¼�
        KeyDown(hWnd, wParam, lParam);
    }
    break;
    case WM_KEYUP:
    {
        // �����ɿ��¼�
        KeyUp(hWnd, wParam, lParam);
    }
    break;
    case WM_MOUSEMOVE:
    {
        // ����ƶ��¼�
        MouseMove(hWnd, wParam, lParam);
    }
    break;
    case WM_LBUTTONDOWN:
    {
        // �����������¼�
        LButtonDown(hWnd, wParam, lParam);
    }
    break;
    case WM_LBUTTONUP:
    {
        // �������ɿ��¼�
        LButtonUp(hWnd, wParam, lParam);
    }
    break;
    case WM_TIMER:
    {
        // �ж���Ϸ�Ƿ���ͣ
        if (currentStage != NULL && !currentStage->pause)
        {
            TimerUpdate(hWnd, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        // ��ͼ
        Paint(hWnd);
    }
    break;

    // TODO��������Ϣ
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // �����˵�ѡ��:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_DESTROY:
    {
        // �����˳�
        PostQuitMessage(0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

#pragma endregion

#pragma region �¼�������

// ��ʼ����Ϸ���庯��
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    // ����ͼ����Դ
    bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP__START));
    bmp_Rock = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ROCK));
    bmp_Block = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BRICK));
    bmp_Help = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP__HELP));
    bmp_JingDian = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_JINGDIAN));
    bmp_KuangBao = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_KUANGBAO));
    bmp_WhiteBackground = CreateWhiteBackground(hWnd);
    bmp_GameBackground = CreateGameBackground(hWnd);
    bmp_TITLE = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_TITLE));
    bmp_BACKGROUND = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND));
    bmp_OPEN = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_OPEN));
    bmp_STUDY = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STUDY));
    bmp_TITLES = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_TITLES));
    bmp_BACKGROUND2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND2));
    bmp_BACK = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
    bmp_SHUOMING = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_shuoming));
    bmp_CONTINUE = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_CONTINUE));
    bmp_RESTART = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RESTART));
    bmp_BACKTO = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKTO));
    bmp_END = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_END));
    bmp_EXPLAIN = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_EXPLAIN));
    bmp_SHEZHI = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SHEZHI));
    bmp_SLOW = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SLOW));
    bmp_MEDIUM = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_MEDIUM));
    bmp_FAST = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FAST));
    bmp_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_1));
    bmp_10 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_10));
    bmp_100 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_100));
    bmp_EXPLAINED = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_EXPLAINED));
    bmp_BACKGROUND3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND3));
    bmp_BACKGROUND4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND4));
    bmp_CHALLENGE = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_CHALLENGE));
    bmp_PERFECT = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_PERFECT));
    bmp_GREAT = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GREAT));
    bmp_FAIL = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FAIL));
    bmp_666 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_666));
    bmp_GIFT = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_fubao));
    bmp_BARRIER = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BARRIER));
    bmp_RROCK = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_RROCK));
    bmp_TOHELP = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_TOHELP));

    // ��ʼ����ʼ����
    InitStage(hWnd, STAGE_START);

    // ��ʼ������ʱ��
    SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

//���̰��´�����
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    switch (wParam)
    {
    case 0x57:      //W,����
    case VK_UP:
        keyUp = true;
        break;
    case 0x53:      //S,����
    case VK_DOWN:
        keyDown = true;
        break;
    case 0x41:      //A,����
    case VK_LEFT:
        keyLeft = true;
        break;
    case 0x44:      //D,����
    case VK_RIGHT:
        keyRight = true;
        break;
    case 0x51:      //Q,������ת90��
        keyrotateLeft = true;
        break;
    case 0x45:      //E,
        keyrotateRight = true;
        break;
    case VK_ESCAPE: //esc
        keyESCdown = true;
    default:
        break;
    }
}
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)     //����ƶ�
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
}
void MouseDown(HWND hWnd, WPARAM wParam, LPARAM lParam)     //����������
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
    mouseDown = true;

    //�ж�����Ƿ�����ť
    for (int i = 0; i < buttons.size(); i++) {
        Button* button = buttons[i];
        if (button->x <= mouseX && button->x + button->width >= mouseX && button->y <= mouseY && button->y + button->height >= mouseY)
        {
            switch (button->buttonID)
            {
            case BUTTON_STARTGAME_ID:
            {
                if (CONDITION1 == false) {
                    ADJUST = TIMER_ADJUST1;
                }
                if (CONDITION2 == false) {
                    SCORE = TIMER_SCORE2;
                }
                count16 = 0;
                InitStage(hWnd, STAGE_GAME);
            }
            break;


            // TODO: ������ť
            default:
                break;
            }
        }
    }
}

void MouseUp(HWND hWnd, WPARAM wParam, LPARAM lParam)       //�������ɿ�
{
    mouseX = LOWORD(lParam);
    mouseY = HIWORD(lParam);
    mouseDown = false;
}
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)   //��ʱ���¼�������
{
    switch (currentStage->stageID) {
    case STAGE_START:
        UpdateBrick(hWnd);
        break;

    case STAGE_RESTART:     //???
        count14++;
        The_Stage = 2;
        if (STARTCOUNT)count15++;
        count16++;
        UpdateBrick(hWnd);
        break;

    case STAGE_HELP:
        break;

    case STAGE_BACK:
        break;

    case STAGE_ESC:
        break;

    case STAGE_END:
        break;

    case STAGE_CHALLENGEEND:
        break;

    case STAGE_GAME:
        The_Stage = 3;
        if (STARTCOUNT)count15++;
        if (YES)mid++;
        count16++;
        UpdateBrick(hWnd);
        break;

        //TODO:��Ӷ����Ϸ����

    default:
        break;
    }
    //ˢ����ʾ
    InvalidateRect(hWnd, NULL, false);
}

void PaintUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (currentStage->stageID == STAGE_GAME)
    {
        if (block != NULL) {
            block->frame_index = (block->frame_index + 1) % BLOCK_FRAME_SIZE;
        }
    }
    if (currentStage->stageID == STAGE_START)
    {
        if (block != NULL) {
            block->frame_index = (block->frame_index + 1) % BLOCK_FRAME_SIZE;
        }
    }
    InvalidateRect(hWnd, NULL, false);
}

#pragma endregion

#pragma region ������Ϸ״̬������
//��ʼ����Ϸ��������
void InitStage(HWND hWnd, int stageID)
{
    //��ʼ������ʵ��
    if (currentStage != NULL) {
        delete currentStage;
        currentStage = new Stage();
        currentStage->stageID = stageID;

        switch (stageID) {
        case STAGE_START:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;                 //��ɫ����ͼƬ
            currentStage->pause = false;
            g_nScore = 0;

            //ɾ���ɰ�ť
            for (size_t i = 0; i < buttons.size(); i++) {
                void InitGame(HWND hwnd, WPARAM wparam, LPARAM lparam);
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            //����µĿ�ʼ��ť
            Button* startButton = CreateButton(
                BUTTON_STARTGAME_ID, bmp_StartButton,
                BUTTON_STARTGAME_X, BUTTON_STARTGAME_Y,
                BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT);
            buttons.push_back(startButton);

            Button* HELPButton = CreateButton(
                BUTTON_HELP_ID, bmp_Help,
                BUTTON_HELP_X, BUTTON_HELP_Y,
                BUTTON_HELP_WIDTH, BUTTON_HELP_HEIGHT);
            buttons.push_back(HELPButton);

            Button* SHEZHIButton = CreateButton(
                BUTTON_SHEZHI_ID, bmp_SHEZHI,
                BUTTON_SHEZHI_X, BUTTON_SHEZHI_Y,
                BUTTON_SHEZHI_WIDTH, BUTTON_SHEZHI_HEIGHT);
            buttons.push_back(SHEZHIButton);

            Button* CHALLENGEButton = CreateButton(
                BUTTON_CHALLENGE_ID, bmp_CHALLENGE,
                BUTTON_CHALLENGE_X, BUTTON_CHALLENGE_Y,
                BUTTON_CHALLENGE_WIDTH, BUTTON_CHALLENGE_HEIGHT);
            buttons.push_back(CHALLENGEButton);

            Button* BARRIERButton = CreateButton(
                BUTTON_BARRIER_ID, bmp_BARRIER,
                BUTTON_BARRIER_X, BUTTON_BARRIER_Y,
                BUTTON_BARRIER_WIDTH, BUTTON_BARRIER_HEIGHT);
            buttons.push_back(BARRIERButton);
        }
        break;
        case STAGE_BACK:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;
            g_nScore = 0;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ����µĿ�ʼ��ť
            Button* startButton = CreateButton(
                BUTTON_STARTGAME_ID, bmp_StartButton,
                BUTTON_STARTGAME_X, BUTTON_STARTGAME_Y,
                BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT);
            buttons.push_back(startButton);

            Button* HELPButton = CreateButton(
                BUTTON_HELP_ID, bmp_Help,
                BUTTON_HELP_X, BUTTON_HELP_Y,
                BUTTON_HELP_WIDTH, BUTTON_HELP_HEIGHT);
            buttons.push_back(HELPButton);

            Button* SHEZHIButton = CreateButton(
                BUTTON_SHEZHI_ID, bmp_SHEZHI,
                BUTTON_SHEZHI_X, BUTTON_SHEZHI_Y,
                BUTTON_SHEZHI_WIDTH, BUTTON_SHEZHI_HEIGHT);
            buttons.push_back(SHEZHIButton);

            Button* CHALLENGEButton = CreateButton(
                BUTTON_CHALLENGE_ID, bmp_CHALLENGE,
                BUTTON_CHALLENGE_X, BUTTON_CHALLENGE_Y,
                BUTTON_CHALLENGE_WIDTH, BUTTON_CHALLENGE_HEIGHT);
            buttons.push_back(CHALLENGEButton);

            Button* BARRIERButton = CreateButton(
                BUTTON_BARRIER_ID, bmp_BARRIER,
                BUTTON_BARRIER_X, BUTTON_BARRIER_Y,
                BUTTON_BARRIER_WIDTH, BUTTON_BARRIER_HEIGHT);
            buttons.push_back(BARRIERButton);
        }
        break;
        case STAGE_HELP:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();
            // ����µİ�ť
            Button* backButton = CreateButton(
                BUTTON_BACK_ID, bmp_BACK,
                BUTTON_BACK_X, BUTTON_BACK_Y,
                BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT);
            buttons.push_back(backButton);

        }
        break;
        case STAGE_ESC:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ����µİ�ť
            Button* CONTINUEButton = CreateButton(
                BUTTON_CONTINUE_ID, bmp_CONTINUE,
                BUTTON_CONTINUE_X, BUTTON_CONTINUE_Y,
                BUTTON_CONTINUE_WIDTH, BUTTON_CONTINUE_HEIGHT);
            buttons.push_back(CONTINUEButton);

            Button* RESTARTButton = CreateButton(
                BUTTON_RESTART_ID, bmp_RESTART,
                BUTTON_RESTART_X, BUTTON_RESTART_Y,
                BUTTON_RESTART_WIDTH, BUTTON_RESTART_HEIGHT);
            buttons.push_back(RESTARTButton);

            Button* BACKTOButton = CreateButton(
                BUTTON_BACKTO_ID, bmp_BACKTO,
                BUTTON_BACKTO_X, BUTTON_BACKTO_Y,
                BUTTON_BACKTO_WIDTH, BUTTON_BACKTO_HEIGHT);
            buttons.push_back(BACKTOButton);
        }
        break;
        case STAGE_CHALLENGEEND:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ����µİ�ť

            Button* BACKTOButton = CreateButton(
                BUTTON_BACKTO_ID, bmp_BACKTO,
                BUTTON_BACKTO_X, BUTTON_BACKTO_Y,
                BUTTON_BACKTO_WIDTH, BUTTON_BACKTO_HEIGHT);
            buttons.push_back(BACKTOButton);
        }
        break;
        case STAGE_BARRIEREND:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ����µİ�ť

            Button* BACKTOButton = CreateButton(
                BUTTON_BACKTO_ID, bmp_BACKTO,
                BUTTON_BACKTO_X, BUTTON_BACKTO_Y,
                BUTTON_BACKTO_WIDTH, BUTTON_BACKTO_HEIGHT);
            buttons.push_back(BACKTOButton);
        }
        break;
        case STAGE_GAME:
        {
            currentStage->backgroundimg = bmp_GameBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ɾ���ɵ�ש�飬�����µ�ש��
            if (gift != 1) {
                if (block != NULL)
                    delete block;
                srand((unsigned)time(NULL));
                int type = rand() % 7 + 1;
                block = CreateBrick(bmp_Block, type);
            }

            if (gift == 1) {
                Button* fubaoButton = CreateButton(
                    BUTTON_GIFT_ID, bmp_GIFT,
                    BUTTON_GIFT_X, BUTTON_GIFT_Y,
                    BUTTON_GIFT_WIDTH, BUTTON_GIFT_HEIGHT);
                buttons.push_back(fubaoButton);
            }
        }
        break;
        case STAGE_RESTART:
        {
            currentStage->backgroundimg = bmp_GameBackground;
            currentStage->pause = false;
            count14 = 0;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            // ɾ���ɵ�ש�飬�����µ�ש��
            if (block != NULL)
                delete block;
            srand((unsigned)time(NULL));
            int type = rand() % 7 + 1;
            block = CreateBrick(bmp_Block, type);

            if (gift == 1) {
                Button* fubaoButton = CreateButton(
                    BUTTON_GIFT_ID, bmp_GIFT,
                    BUTTON_GIFT_X, BUTTON_GIFT_Y,
                    BUTTON_GIFT_WIDTH, BUTTON_GIFT_HEIGHT);
                buttons.push_back(fubaoButton);
            }
        }
        break;
        case STAGE_END:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            Button* BACKTOButton = CreateButton(
                BUTTON_BACKTO_ID, bmp_BACKTO,
                BUTTON_BACKTO_X, BUTTON_BACKTO_Y,
                BUTTON_BACKTO_WIDTH, BUTTON_BACKTO_HEIGHT);
            buttons.push_back(BACKTOButton);

        }
        break;
        case STAGE_SHEZHI:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            Button* SLOWButton = CreateButton(
                BUTTON_SLOW_ID, bmp_SLOW,
                BUTTON_SLOW_X, BUTTON_SLOW_Y,
                BUTTON_SLOW_WIDTH, BUTTON_SLOW_HEIGHT);
            buttons.push_back(SLOWButton);

            Button* MEDIUMButton = CreateButton(
                BUTTON_MEDIUM_ID, bmp_MEDIUM,
                BUTTON_MEDIUM_X, BUTTON_MEDIUM_Y,
                BUTTON_MEDIUM_WIDTH, BUTTON_MEDIUM_HEIGHT);
            buttons.push_back(MEDIUMButton);

            Button* FASTButton = CreateButton(
                BUTTON_FAST_ID, bmp_FAST,
                BUTTON_FAST_X, BUTTON_FAST_Y,
                BUTTON_FAST_WIDTH, BUTTON_FAST_HEIGHT);
            buttons.push_back(FASTButton);
        }
        break;
        case STAGE_SHEZHI2:
        {
            currentStage->backgroundimg = bmp_WhiteBackground;
            currentStage->pause = false;

            // ɾ���ɵİ�ť
            for (size_t i = 0; i < buttons.size(); i++)
            {
                Button* button = buttons[i];
                delete button;
            }
            buttons.clear();

            Button* ONEButton = CreateButton(
                BUTTON_1_ID, bmp_1,
                BUTTON_1_X, BUTTON_1_Y,
                BUTTON_1_WIDTH, BUTTON_1_HEIGHT);
            buttons.push_back(ONEButton);

            Button* TENButton = CreateButton(
                BUTTON_10_ID, bmp_10,
                BUTTON_10_X, BUTTON_10_Y,
                BUTTON_10_WIDTH, BUTTON_10_HEIGHT);
            buttons.push_back(TENButton);

            Button* HOUNDButton = CreateButton(
                BUTTON_100_ID, bmp_100,
                BUTTON_100_X, BUTTON_100_Y,
                BUTTON_100_WIDTH, BUTTON_100_HEIGHT);
            buttons.push_back(HOUNDButton);
        }
        break;
        // TODO����Ӷ����Ϸ����
        default:
            break;
        }

        // ˢ����ʾ
        InvalidateRect(hWnd, NULL, FALSE);

    }
}

//��Ӱ�ť����
Button* CreateButton(int buttonID, HBITMAP img, int x, int y, int width, int height)
{

    Button* button = new Button();
    button->buttonID = buttonID;
    button->buttonimg = img;
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    return button;
}
//���ש�麯��
Block* CreateBrick(HBITMAP img, int type)
{
    Block* block = nullptr;
    if (type == 1) {
        block = new Block();
        memcpy(block->shape, shape_T, sizeof(block->shape));
    }
    if (type == 2) {
        block = new Block();
        memcpy(block->shape, shape_O, sizeof(block->shape));
    }
    if (type == 3) {
        block = new Block();
        memcpy(block->shape, shape_I, sizeof(block->shape));
    }
    if (type == 4) {
        block = new Block();
        memcpy(block->shape, shape_S, sizeof(block->shape));
    }
    if (type == 5) {
        block = new Block();
        memcpy(block->shape, shape_Z, sizeof(block->shape));
    }
    if (type == 6) {
        block = new Block();
        memcpy(block->shape, shape_L, sizeof(block->shape));
    }
    if (type == 7) {
        block = new Block();
        memcpy(block->shape, shape_J, sizeof(block->shape));
    }
    block->blockmap = img;
    block->frame_index = 0;
    block->cell_x = BLOCK_COLUMNS * 3 / 8;
    block->cell_y = 0;
    return block;
}

//ˢ��ש��״̬����
void UpdateBlock(HWND hWnd)
{
    if (The_Stage) {
        //restartģʽ������
        if (count14 == 1) {
            g_nScore = 0;
            int i;
            for (i = 0; i < BLOCK_COLUMNS; i++) {
                for (int j = 0; j < BLOCK_ROWS; j++) {
                    g_arrBackGround[j][i] = 0;
                }
            }
        }

        if (The_Stage != 2) count14 = 0;

        //challengeģʽ�¼�ʱ
        if (count15 >= 400) {
            if (g_nScore == 0)success = false;
            else success = true;
            InitStage(hWnd, STAGE_CHALLENGEEND);
            STARTCOUNT = false;
            count15 = 0;
            g_nScore = 0;
            int i;
            for (i = 0; i < BLOCK_COLUMNS; i++) {
                for (int j = 0; j < BLOCK_ROWS; j++) {
                    g_arrBackGround[j][i] = 0;
                }
            }
            return;
        }

        bool flag = false;
        int condition1 = 1;
        int condition2 = 1;
        int condition0 = 1;
        int temp0 = g_nScore;
        int z = 0;
        //����ת�����ַ���
        if (g_nScore == 0) Score[z++] = '0';
        else {
            while (g_nScore) {
                Score[z++] = g_nScore % 10 + '0';
                g_nScore = g_nScore / 10;
            }
            g_nScore = temp0;
            for (int i = 0, j = z - 1; i < j; i++, j--) {
                char temp1 = Score[i];
                Score[i] = Score[j];
                Score[j] = temp1;
            }
        }
        Score[z] = '\0';

        //����GIFT����
        if (g_nScore == SCORE || g_nScore == SCORE * 5 || g_nScore == SCORE * 20) {
            gift = 1;
            InitStage(hWnd, STAGE_GAME);
            if (STARTCOUNT1) {
                FANBEI = true;
                for (int t = 0; t < BLOCK_COLUMNS; t++) {
                    g_arrBackGround[WINDOW_HEIGHT - 1][t] = 1;
                }
                gift = 0;
                STARTCOUNT1 = false;
                InitStage(hWnd, STAGE_GAME);
            }
            else {
                if (count16 > 5) {
                    gift = 0;
                    InitStage(hWnd, STAGE_GAME);
                }
                count16 = 0;
            }
        }


        // ��������
        if (block != NULL) {
            block->frame_index = (block->frame_index + 1) % BLOCK_FRAME_SIZE;
            static int count = 0;// �ֲ���̬����
            candowndown(block, &condition0, &flag);
            if (++count >= ADJUST && condition0) {
                block->cell_y++;
                count = 0;
            }
        }

        // λ�ø���
        if (keyDown)
        {
            candowndown(block, &condition0, &flag);
            if (condition0)
                block->cell_y++;
        }
        if (keyLeft)
        {
            candowndown(block, &condition0, &flag);
            canleft(block, &condition1);
            if (condition1 && condition0)
                block->cell_x--;
        }
        if (keyRight)
        {
            candowndown(block, &condition0, &flag);
            canright(block, &condition2);
            if (condition2 && condition0)
                block->cell_x++;
        }

        // ��ֹ������Ļ
        //��ֹ������߽߱�
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (block->shape[i][j]) {
                    if (block->cell_x + j <= 0) {
                        block->cell_x = -j;
                        break;
                    }
                }
            }
        }
        //��ֹ�����ұ߽߱�
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= 0; j--) {
                if (block->shape[i][j]) {
                    if (block->cell_x + j >= BLOCK_COLUMNS - 1) {
                        block->cell_x = BLOCK_COLUMNS - j - 1;
                        break;
                    }
                }
            }
        }
        //��ֹ�����ϱ߽߱�
        if (block->cell_y < 0)
        {
            block->cell_y = 0;
        }
        //��ֹ����ȥ
        if (block->cell_y >= BLOCK_ROWS)
        {
            block->cell_y = BLOCK_ROWS;
        }
        //�ڵײ��̶�����
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (block->shape[i][j]) {
                    if (block->cell_y + i >= BLOCK_ROWS) {
                        flag = true;
                        block->cell_y = BLOCK_ROWS - i - 1;
                        for (int m = 0; m < 4; m++) {
                            for (int n = 0; n < 4; n++) {
                                if (block->shape[m][n] == 1)
                                    g_arrBackGround[block->cell_y + m][block->cell_x + n] = 1;
                            }
                        }
                    }
                }
            }
        }
        //��ײ��̶�����
        if (flag == true) {
            for (int m = 0; m < 4; m++) {
                for (int n = 0; n < 4; n++) {
                    if (block->shape[m][n] == 1) {
                        g_arrBackGround[block->cell_y + m][block->cell_x + n] = 1;
                    }
                }
            }
        }

        //��ת
        //˳ʱ����ת90��
        if (keyrotateRight) {
            int shape1[4][4] = { 0 };
            int n = 4;
            memcpy(shape1, block->shape, sizeof(shape1));
            int rotated[4][4] = { 0 };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rotated[j][n - 1 - i] = shape1[i][j];
                }
            }
            memcpy(shape1, rotated, sizeof(shape1));
            memcpy(block->shape, shape1, sizeof(shape1));

        }
        //��ʱ����ת90��
        if (keyrotateLeft) {
            int shape1[4][4] = { 0 };
            int n = 4;
            memcpy(shape1, block->shape, sizeof(shape1));
            int rotated[4][4] = { 0 };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rotated[n - 1 - j][i] = shape1[i][j];
                }
            }
            memcpy(shape1, rotated, sizeof(shape1));
            memcpy(block->shape, shape1, sizeof(shape1));

        }
        //�����µķ���
        if (flag == true) {
            if (block != NULL)
                delete block;
            srand((unsigned)time(NULL));
            type = rand() % 7 + 1;
            block = CreateBrick(bmp_Block, type);

        }

        //����
        remove();

        //��Ϸ����
        if (GameOver() == 0) {
            if (BARRIERCONDITION) {
                InitStage(hWnd, STAGE_BARRIEREND);
                BARRIERCONDITION = false;
                return;
            }
            else {
                InitStage(hWnd, STAGE_END);
                return;
            }
        }
        else if (GameOver() == 2) {
            if (g_nScore == 0)success = false;
            else success = true;
            InitStage(hWnd, STAGE_CHALLENGEEND);
            return;
        }
        The_Stage = 0;
    }
    //����������������Ļ
    else {
        int i;
        for (i = 0; i < BLOCK_COLUMNS; i++) {
            for (int j = 0; j < BLOCK_ROWS; j++) {
                g_arrBackGround[j][i] = 0;
            }
        }
    }
}

//�ж�ש���Ƿ��������

void candowndown(Block* block, int* condition0, bool* flag)
{
    for (int x = 3; x >= 0; x--) {
        for (int y = 0; y < 4; y++) {
            if (block->shape[x][y] == 1) {
                if (g_arrBackGround[block->cell_y + x + 1][block->cell_x + y] == 1)
                {
                    *condition0 = 0;
                    *flag = true;
                }
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < 4; j++) {
            if (block->shape[i][j]) {
                if (block->cell_y + i >= BLOCK_ROWS) {
                    *condition0 = 0;
                }
            }
        }
    }
}

//�ж��Ƿ���������ƶ�
void canleft(Block* block, int* condition1)
{
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (block->shape[x][y] == 1) {
                if (g_arrBackGround[block->cell_y + x][block->cell_x + y - 1] == 1)
                {
                    *condition1 = 0;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block->shape[i][j]) {
                if (block->cell_y + i >= BLOCK_ROWS) {
                    *condition1 = 0;
                }
            }
        }
    }
}
//�ж��Ƿ���������ƶ�
void canright(Block* block, int* condition2) {
    for (int y = 3; y >= 0; y--) {
        for (int x = 3; x >= 0; x--) {
            if (block->shape[x][y] == 1) {
                if (g_arrBackGround[block->cell_y + x][block->cell_x + y + 1] == 1)
                {
                    *condition2 = 0;
                }
            }
        }
    }
    for (int i = 3; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
            if (block->shape[i][j]) {
                if (block->cell_y + i >= BLOCK_ROWS) {
                    *condition2 = 0;
                }
            }
        }
    }
}

//���к���
void remove()
{
    int count = 0;
    int h, t;
    int temp;
    for (int h = WINDOW_HEIGHT - 1; h >= 0; h--) {
        for (int t = 0; t < BLOCK_COLUMNS; t++) {
            count = g_arrBackGround[h][t] + count;
        }
        if (count == BLOCK_COLUMNS) {
            for (temp = h; temp >= 0; temp--) {
                for (int t = 0; t < BLOCK_COLUMNS; t++) {
                    g_arrBackGround[temp][t] = g_arrBackGround[temp - 1][t];
                }
            }
            if (FANBEI) {
                g_nScore = g_nScore * 2;
                FANBEI = false;
            }
            else g_nScore = g_nScore + SCORE;
            YES = true;
            if (mid > 4) {
                YES = false;
                mid = 0;
            }
            if (gift != 1) {
                h++;
            }
        }
        count = 0;
    }
}

//��Ϸ��������
int GameOver() {
    int i;
    for (i = 0; i < BLOCK_COLUMNS; i++) {
        if (g_arrBackGround[0][i] == 1) {
            for (i = 0; i < BLOCK_COLUMNS; i++) {
                for (int j = 0; j < BLOCK_ROWS; j++) {
                    g_arrBackGround[j][i] = 0;
                }
            }
            //CHALLENGEģʽ���ж���Ϸ����
            if (STARTCOUNT) {
                count15 = 400;
                STARTCOUNT = false;
                CONDITION1 = false;
                CONDITION2 = false;
                return 2;
            }
            else return 0;
        }
    }
    return 1;
}

#pragma endregion

#pragma region ��ͼ����
// ��ͼ����
void Paint(HWND hWnd)
{
    // ��ʼ����
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // ��������
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);//����������DC
    HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

    // ��ʼ������
    HBITMAP blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);//����һ��ֽ
    SelectObject(hdc_memBuffer, blankBmp);//��Ļ�����Ļ��������

    // ���Ʊ���������
    SelectObject(hdc_loadBmp, currentStage->backgroundimg);
    BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

    // ����������������ݵ�����
    switch (currentStage->stageID)
    {
    case STAGE_START:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 856, 824,
            RGB(255, 255, 255));

        SelectObject(hdc_loadBmp, bmp_TITLES);
        TransparentBlt(
            hdc_memBuffer, 0, 50,
            1215, 300,
            hdc_loadBmp, 0, 0, 554, 186,
            RGB(255, 255, 255));

    }
    break;
    case STAGE_BACK:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 856, 824,
            RGB(255, 255, 255));

        SelectObject(hdc_loadBmp, bmp_TITLES);
        TransparentBlt(
            hdc_memBuffer, 0, 50,
            1215, 300,
            hdc_loadBmp, 0, 0, 554, 186,
            RGB(255, 255, 255));

    }
    break;
    case STAGE_ESC:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND2);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            600, 824,
            hdc_loadBmp, 0, 0, 1086, 1124,
            RGB(255, 255, 255));
    }
    break;
    case STAGE_HELP: {
        SelectObject(hdc_loadBmp, bmp_TOHELP);
        TransparentBlt(
            hdc_memBuffer, 20, 50,
            800, 600,
            hdc_loadBmp, 0, 0, 1370, 924,
            RGB(255, 255, 255));
    }
                   break;
    case STAGE_RESTART:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 725, 878,
            RGB(255, 255, 255));

        SelectObject(hdc_loadBmp, bmp_BACKGROUND4);
        TransparentBlt(
            hdc_memBuffer, BLOCK_WIDTH + 10, 480,
            WINDOW_WIDTH - BLOCK_WIDTH - 50, 312,
            hdc_loadBmp, 0, 0, 902, 1434,
            RGB(255, 255, 255));

        if (YES && mid <= 4) {
            SelectObject(hdc_loadBmp, bmp_666);
            TransparentBlt(
                hdc_memBuffer, 600, 200,
                200, 200,
                hdc_loadBmp, 0, 0, 685, 778,
                RGB(255, 255, 255));
        }

        if (block != nullptr) {
            SelectObject(hdc_loadBmp, block->blockmap);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (block->shape[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, (block->cell_x + j) * BG_CELL_WIDTH, (block->cell_y + i) * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        if (block != nullptr) {
            SelectObject(hdc_loadBmp, bmp_Rock);
            for (int i = 0; i < WINDOW_HEIGHT; i++) {
                for (int j = 0; j < WINDOW_WIDTH; j++) {
                    if (g_arrBackGround[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }

        if (BARRIERCONDITION) {
            for (int i = 10; i < 15; i++) {
                for (int j = 0; j < BLOCK_COLUMNS; j++) {
                    SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
                    TransparentBlt(
                        hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
                        BG_CELL_WIDTH, BG_CELL_HEIGHT,
                        hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                        RGB(255, 255, 255));
                }
            }
        }

        //����
        MoveToEx(hdc_memBuffer, BLOCK_WIDTH, 0, NULL);
        LineTo(hdc_memBuffer, BLOCK_WIDTH, BLOCK_HEIGHT);

        //д����
        HFONT hFont = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
            BLOCK_WIDTH,
            20,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            50 };
        // ����
        DrawText(hdc_memBuffer, TEXT("����ǰ�ķ�����"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        HFONT hFont0 = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont0 = (HFONT)SelectObject(hdc_memBuffer, hFont0);
        // ������������
        RECT rect0 = {
            BLOCK_WIDTH,
            60,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            90 };
        // ����
        DrawTextA(hdc_memBuffer, Score, -1, &rect0, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont0);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont0);
    }
    break;
    case STAGE_CHALLENGE:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 725, 878,
            RGB(255, 255, 255));

        SelectObject(hdc_loadBmp, bmp_BACKGROUND4);
        TransparentBlt(
            hdc_memBuffer, BLOCK_WIDTH + 10, 480,
            WINDOW_WIDTH - BLOCK_WIDTH - 50, 312,
            hdc_loadBmp, 0, 0, 902, 1434,
            RGB(255, 255, 255));

        if (block != nullptr) {
            SelectObject(hdc_loadBmp, block->blockmap);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (block->shape[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, (block->cell_x + j) * BG_CELL_WIDTH, (block->cell_y + i) * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        if (block != nullptr) {
            SelectObject(hdc_loadBmp, bmp_Rock);
            for (int i = 0; i < WINDOW_HEIGHT; i++) {
                for (int j = 0; j < WINDOW_WIDTH; j++) {
                    if (g_arrBackGround[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        //����
        MoveToEx(hdc_memBuffer, BLOCK_WIDTH, 0, NULL);
        LineTo(hdc_memBuffer, BLOCK_WIDTH, BLOCK_HEIGHT);

        //д����
        HFONT hFont = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
            BLOCK_WIDTH,
            20,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            50 };
        // ����
        DrawText(hdc_memBuffer, TEXT("����ǰ�ķ�����"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        HFONT hFont0 = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont0 = (HFONT)SelectObject(hdc_memBuffer, hFont0);
        // ������������
        RECT rect0 = {
            BLOCK_WIDTH,
            60,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            90 };
        // ����
        DrawTextA(hdc_memBuffer, Score, -1, &rect0, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont0);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont0);
    }
    break;
    case STAGE_GAME:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 725, 878,
            RGB(255, 255, 255));

        SelectObject(hdc_loadBmp, bmp_BACKGROUND4);
        TransparentBlt(
            hdc_memBuffer, BLOCK_WIDTH + 10, 480,
            WINDOW_WIDTH - BLOCK_WIDTH - 50, 312,
            hdc_loadBmp, 0, 0, 902, 1434,
            RGB(255, 255, 255));

        if (YES && mid <= 4) {
            SelectObject(hdc_loadBmp, bmp_666);
            TransparentBlt(
                hdc_memBuffer, 600, 200,
                200, 200,
                hdc_loadBmp, 0, 0, 685, 778,
                RGB(255, 255, 255));
        }

        // ����ש��
        if (block != nullptr) {
            SelectObject(hdc_loadBmp, block->blockmap);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (block->shape[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, (block->cell_x + j) * BG_CELL_WIDTH, (block->cell_y + i) * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }
        if (block != nullptr) {
            SelectObject(hdc_loadBmp, bmp_Rock);
            for (int i = 0; i < WINDOW_HEIGHT; i++) {
                for (int j = 0; j < WINDOW_WIDTH; j++) {
                    if (g_arrBackGround[i][j] == 1) {
                        TransparentBlt(
                            hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
                            BG_CELL_WIDTH, BG_CELL_HEIGHT,
                            hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                            RGB(255, 255, 255));
                    }
                }
            }
        }


        if (BARRIERCONDITION) {
            for (int i = 10; i < 15; i++) {
                for (int j = 0; j < BLOCK_COLUMNS; j++) {
                    SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
                    TransparentBlt(
                        hdc_memBuffer, j * BG_CELL_WIDTH, i * BG_CELL_HEIGHT,
                        BG_CELL_WIDTH, BG_CELL_HEIGHT,
                        hdc_loadBmp, 0, 0, BG_CELL_WIDTH, BG_CELL_WIDTH,
                        RGB(255, 255, 255));
                }
            }
        }

        //����
        MoveToEx(hdc_memBuffer, BLOCK_WIDTH, 0, NULL);
        LineTo(hdc_memBuffer, BLOCK_WIDTH, BLOCK_HEIGHT);

        //д����
        HFONT hFont = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
            BLOCK_WIDTH,
            20,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            50 };
        // ����
        DrawText(hdc_memBuffer, TEXT("����ǰ�ķ�����"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        HFONT hFont0 = CreateFont(
            30,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("΢���ź�")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont0 = (HFONT)SelectObject(hdc_memBuffer, hFont0);
        // ������������
        RECT rect0 = {
            BLOCK_WIDTH,
            60,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            90 };
        // ����
        DrawTextA(hdc_memBuffer, Score, -1, &rect0, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont0);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont0);
    }
    break;
    case STAGE_SHEZHI:
    {
        HFONT hFont = CreateFont(
            50,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
            BLOCK_WIDTH - 600,
            70,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            150 };
        // ����
        DrawText(hdc_memBuffer, TEXT("��ѡ�����ʣ�"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        SelectObject(hdc_loadBmp, bmp_BACKGROUND2);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            600, 824,
            hdc_loadBmp, 0, 0, 1086, 1124,
            RGB(255, 255, 255));
    }
    break;
    case STAGE_SHEZHI2:
    {
        HFONT hFont = CreateFont(
            50,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
            BLOCK_WIDTH - 600,
            70,
            BLOCK_WIDTH + BUTTON_STARTGAME_WIDTH,
            150 };
        // ����
        DrawText(hdc_memBuffer, TEXT("��ѡ��������ʣ�"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        SelectObject(hdc_loadBmp, bmp_BACKGROUND2);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            600, 824,
            hdc_loadBmp, 0, 0, 1086, 1124,
            RGB(255, 255, 255));
    }
    break;
    case STAGE_CHALLENGEEND:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 725, 878,
            RGB(255, 255, 255));

        if (success) {
            SelectObject(hdc_loadBmp, bmp_PERFECT);
            TransparentBlt(
                hdc_memBuffer, 200, 20,
                800, 312,
                hdc_loadBmp, 0, 0, 394, 124,
                RGB(255, 255, 255));
        }
        else {
            SelectObject(hdc_loadBmp, bmp_FAIL);
            TransparentBlt(
                hdc_memBuffer, 150, 20,
                800, 824,
                hdc_loadBmp, 0, 0, 962, 1113,
                RGB(255, 255, 255));
        }

        HFONT hFont = CreateFont(
            80,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
           250,
            400,
           900,
            500 };
        // ����
        DrawText(hdc_memBuffer, TEXT("�������յ÷�Ϊ��"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        HFONT hFont0 = CreateFont(
            80,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont0 = (HFONT)SelectObject(hdc_memBuffer, hFont0);
        // ������������
        RECT rect0 = {
            850,
            400,
            1000,
            500 };
        // ����
        DrawTextA(hdc_memBuffer, Score, -1, &rect0, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont0);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont0);
    }
    break;
    case STAGE_BARRIEREND:
    {
        SelectObject(hdc_loadBmp, bmp_BACKGROUND3);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 725, 878,
            RGB(255, 255, 255));

        if (success) {
            SelectObject(hdc_loadBmp, bmp_PERFECT);
            TransparentBlt(
                hdc_memBuffer, 200, 20,
                800, 312,
                hdc_loadBmp, 0, 0, 394, 124,
                RGB(255, 255, 255));
        }
        else {
            SelectObject(hdc_loadBmp, bmp_FAIL);
            TransparentBlt(
                hdc_memBuffer, 150, 20,
                800, 824,
                hdc_loadBmp, 0, 0, 962, 1113,
                RGB(255, 255, 255));
        }

        HFONT hFont = CreateFont(
            80,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont = (HFONT)SelectObject(hdc_memBuffer, hFont);
        // ������������
        RECT rect = {
           250,
            400,
           900,
            500 };
        // ����
        DrawText(hdc_memBuffer, TEXT("�������յ÷�Ϊ��"), -1, &rect, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont);

        HFONT hFont0 = CreateFont(
            80,                       // ����߶�
            0,                        // �����ȣ�0 ��ʾ�Զ����㣩
            0,                        // �������б�Ƕ�
            0,                        // ����Ļ�����б�Ƕ�
            FW_NORMAL,                // ����Ĵ�ϸ
            FALSE,                    // �Ƿ�б��
            FALSE,                    // �Ƿ��»���
            FALSE,                    // �Ƿ�ɾ����
            DEFAULT_CHARSET,          // �ַ���
            OUT_DEFAULT_PRECIS,       // �������
            CLIP_DEFAULT_PRECIS,      // ���þ���
            DEFAULT_QUALITY,          // �������
            DEFAULT_PITCH | FF_SWISS, // �������ͼ��
            TEXT("������κ")          // ��������
        );
        // ѡ���Զ������嵽�豸������
        HFONT hOldFont0 = (HFONT)SelectObject(hdc_memBuffer, hFont0);
        // ������������
        RECT rect0 = {
            850,
            400,
            1000,
            500 };
        // ����
        DrawTextA(hdc_memBuffer, Score, -1, &rect0, DT_CENTER);
        // �ָ�ԭ��������
        SelectObject(hdc_memBuffer, hOldFont0);
        // ɾ���Զ����������ͷ���Դ
        DeleteObject(hFont0);
    }
    break;
    case STAGE_END:
    {
        SelectObject(hdc_loadBmp, bmp_END);
        TransparentBlt(
            hdc_memBuffer, 0, 0,
            1215, 824,
            hdc_loadBmp, 0, 0, 1077, 854,
            RGB(255, 255, 255));

    }
    break;
    // TODO����Ӷ����Ϸ����
    default:
        break;
    }
    for (int i = 0; i < buttons.size(); i++)
    {
        Button* button = buttons[i];
        SelectObject(hdc_loadBmp, button->buttonimg);
        TransparentBlt(
            hdc_memBuffer, button->x, button->y,
            button->width, button->height,
            hdc_loadBmp, 0, 0, button->width, button->height,
            RGB(255, 255, 255));
    }


    // ������е���Ϣ���Ƶ���Ļ��
    BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

    // ������Դ��ռ���ڴ棨�ǳ���Ҫ��
    DeleteObject(blankBmp);
    DeleteDC(hdc_loadBmp);
    DeleteDC(hdc_memBuffer);//�ͷż�����DC

    // ��������
    EndPaint(hWnd, &ps);
}

// �������ױ���ͼ��
HBITMAP CreateWhiteBackground(HWND hWnd)
{
    // ��ʼ����
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // ��������
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);

    // ��ʼ������
    HBITMAP bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(hdc_memBuffer, bmp_output);

    // ��������ɫ��ˢ
    HBRUSH hbr = CreatePatternBrush(bmp_BACKGROUND3);

    // ����һ������
    RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };

    // ���������Ϊ��ɫ
    FillRect(hdc_memBuffer, &rect, hbr);

    // ������Դ��ռ���ڴ棨�ǳ���Ҫ��
    DeleteObject(hbr);
    DeleteDC(hdc_memBuffer);

    // ��������
    EndPaint(hWnd, &ps);

    return bmp_output;
}

HBITMAP CreateGameBackground(HWND hWnd)
{
    // ��ʼ����
    PAINTSTRUCT ps;
    HDC hdc_window = BeginPaint(hWnd, &ps);

    // ��������
    HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
    HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

    // ��ʼ������
    HBITMAP bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    SelectObject(hdc_memBuffer, bmp_output);

    // ��ʼ��Ϊ��ɫ����
    SelectObject(hdc_loadBmp, bmp_WhiteBackground);
    BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);

    // ������Դ��ռ���ڴ棨�ǳ���Ҫ��
    DeleteDC(hdc_loadBmp);
    DeleteDC(hdc_memBuffer);

    // ��������
    EndPaint(hWnd, &ps);

    return bmp_output;
}

#pragma endregion



