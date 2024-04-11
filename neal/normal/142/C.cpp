// #define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const char T[4][4][4] =
{
    {"***",
     ".*.",
     ".*."},

    {"*..",
     "***",
     "*.."},

    {".*.",
     ".*.",
     "***"},

    {"..*",
     "***",
     "..*"}
};

int N, M;
char board[10][10], save[10][10];
char global_max;

bool can_place(int r, int c, int type)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (T[type][i][j] == '*' && board[r + i][c + j] != '.')
                return false;

    return true;
}

void place(int r, int c, int type, char letter)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (T[type][i][j] == '*')
                board[r + i][c + j] = letter;
}

void unplace(int r, int c, int type)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (T[type][i][j] == '*')
                board[r + i][c + j] = '.';
}

char maximum[10][10];

void go(int r, int c, char letter)
{
    if (r >= N - 2)
    {
        if (letter > global_max)
        {
            global_max = letter;
            memcpy(save, board, sizeof(board));
        }

        return;
    }

    if (c >= M - 2)
    {
        go(r + 1, 0, letter);
        return;
    }

// incorrect optimization
    if (letter < maximum[r][c] - 1)
        return;

    maximum[r][c] = max(maximum[r][c], letter);

    go(r, c + 1, letter);

    for (int type = 0; type < 4; type++)
        if (can_place(r, c, type))
        {
            place(r, c, type, letter);
            letter++;
            go(r, c + 1, letter);
            unplace(r, c, type);
            letter--;
        }
}

int main()
{
    memset(board, '.', sizeof(board));
    memset(save, '.', sizeof(save));
    memset(maximum, 0, sizeof(maximum));
    global_max = 0;

    scanf("%d %d", &N, &M);
    go(0, 0, 'A');
    printf("%d\n", global_max - 'A');

    for (int i = 0; i < N; i++)
    {
        save[i][M] = '\0';
        puts(save[i]);
    }

    return 0;
}