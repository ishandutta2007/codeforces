#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int dp[MAXN + 2][MAXN + 2][MAXN + 2][MAXN + 2];
bool board[MAXN + 1][MAXN + 1];
int pref[MAXN + 1][MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            board[i][j] = s[j - 1] == '#';
            dp[i][j][i][j] = board[i][j];
            pref[i][j] = board[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    for (int w = 1; w <= n; w++)
    {
        for (int h = 1; h <= n; h++)
        {
            if (w == 1 && h == 1)
                continue;
            for (int i = 1; i + h - 1 <= n; i++)
            {
                for (int j = 1; j + w - 1 <= n; j++)
                {
                    int ii = i + h - 1;
                    int jj = j + w - 1;
                    dp[i][j][ii][jj] = max(w, h);
                    for (int k = 0; k < max(w, h); k++)
                    {
                        if (w >= h)
                        {
                            if (pref[ii][j + k] - pref[ii][j + k - 1] - pref[i - 1][j + k] + pref[i - 1][j + k - 1])
                                continue;
                            dp[i][j][ii][jj] = min(dp[i][j][ii][jj], dp[i][j][ii][j + k - 1] + dp[i][j + k + 1][ii][jj]);
                        }
                        else
                        {
                            if (pref[i + k][jj] - pref[i + k - 1][jj] - pref[i + k][j - 1] + pref[i + k - 1][j - 1])
                                continue;
                            dp[i][j][ii][jj] = min(dp[i][j][ii][jj], dp[i][j][i + k - 1][jj] + dp[i + k + 1][j][ii][jj]);
                        }
                    }
                    //cout << i << " " << j << " " << ii << " " << jj << " " << dp[i][j][ii][jj] << "\n";
                }
            }
        }
    }
    cout << dp[1][1][n][n] << "\n";
    return 0;
}