#include <iostream>

using namespace std;

const int MAXN = 500;
int up[MAXN][MAXN];
int down[MAXN][MAXN];
int leftt[MAXN][MAXN];
int rightt[MAXN][MAXN];
bool filled[MAXN][MAXN];

int main()
{
    int h, w;
    cin >> h >> w;
    int total = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                total++;
                filled[i][j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i >= 1 && filled[i-1][j])
                up[i][j] = up[i-1][j] + 1;

            if (j >= 1 && filled[i][j-1])
                leftt[i][j] = leftt[i][j-1] + 1;

        }
    }
    for (int i = h-1; i >= 0; i--)
    {
        for (int j = w-1; j >= 0; j--)
        {
            if (i < h - 1 && filled[i+1][j])
                down[i][j] = down[i+1][j] + 1;
            if (j < w - 1 && filled[i][j+1])
                rightt[i][j] = rightt[i][j+1] + 1;
        }
    }

    bool found = false;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (filled[i][j] && up[i][j] && down[i][j] && leftt[i][j] && rightt[i][j])
            {
                if (up[i][j] + down[i][j] + leftt[i][j] + rightt[i][j] + 1 == total)
                    found = true;
            }
        }
    }
    if (found)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}