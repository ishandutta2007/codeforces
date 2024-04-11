#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E3;
const int MOD = 1E9 + 7;
int board[MAXN][MAXN];
int r[MAXN];
int c[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    bool possible = true;
    for (int i = 0; i < h; i++)
    {
        fill(board[i], board[i] + w, -1);
    }
    for (int i = 0; i < h; i++)
    {
        cin >> r[i];
        for (int j = 0; j < r[i]; j++)
        {
            board[i][j] = 1;
        }
        if (r[i] < w)
            board[i][r[i]] = 0;
    }
    for (int i = 0; i < w; i++)
    {
        cin >> c[i];
        for (int j = 0; j < c[i]; j++)
        {
            if (board[j][i] == 0)
            {
                possible = false;
            }
            else
            {
                board[j][i] = 1;
            }
        }
        if (c[i] < h)
        {
            if (board[c[i]][i] == 1)
            {
                possible = false;
            }
            else
            {
                board[c[i]][i] = 0;
            }
        }
    }
    int ans = 0;
    if (possible)
    {
        ans = 1;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == -1)
                {
                    ans = (int) (((long long) ans * 2) % MOD);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}