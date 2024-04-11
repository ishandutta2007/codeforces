#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
string board[MAXN];
int dp[MAXN + 1][MAXN + 1][MAXN + 1];
bool goodOut[MAXN][MAXN];
int rt[MAXN][MAXN];
int dn[MAXN][MAXN];
int lt[MAXN][MAXN];
int up[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            char ch = board[r][c];
            int t = c;
            while (t < m && board[r][t] == ch)
            {
                t++;
                rt[r][c]++;
            }
            t = c;
            while (t >= 0 && board[r][t] == ch)
            {
                t--;
                lt[r][c]++;
            }
            t = r;
            while (t < n && board[t][c] == ch)
            {
                t++;
                dn[r][c]++;
            }
            t = r;
            while (t >= 0 && board[t][c] == ch)
            {
                t--;
                up[r][c]++;
            }
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int r = 0; r + len - 1 < n; r++)
        {
            for (int c = 0; c + len - 1 < m; c++)
            {
                dp[len][r][c] = max(max(max(dp[len - 1][r][c], dp[len - 1][r][c + 1]), dp[len - 1][r + 1][c + 1]), dp[len - 1][r + 1][c]);
                if (len % 2 == 0 && board[r][c] == 'R' && board[r][c + len - 1] == 'G' && board[r + len - 1][c] == 'Y' && board[r + len - 1][c + len - 1] == 'B')
                {
                    int half = len / 2;
                    if (rt[r][c] == half && dn[r][c] == half && lt[r][c + len - 1] == half && dn[r][c + len - 1] == half && up[r + len - 1][c] == half && rt[r + len - 1][c] == half && lt[r + len - 1][c + len - 1] == half && up[r + len - 1][c + len - 1] == half)
                        dp[len][r][c] = len * len;
                }
                //cout << len << " " << r << " " << c << " " << dp[len][r][c] << endl;
            }
        }
    }
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        r2--;
        c1--;
        c2--;
        int len = min(r2 - r1, c2 - c1) + 1;
        int ans = 0;
        if (r2 > r1 + len - 1)
        {
            for (int r = r1; r + len - 1 <= r2; r++)
            {
                ans = max(ans, dp[len][r][c1]);
            }
        }
        else
        {
            for (int c = c1; c + len - 1 <= c2; c++)
            {
                ans = max(ans, dp[len][r1][c]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}