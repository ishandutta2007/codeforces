#include <bits/stdc++.h>

using namespace std;

const int INF = 1000;
const int MAXN = 100;
int dp[2][MAXN][MAXN + 1];
int p[MAXN];
bool visited[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    int miss = 0;
    int even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        visited[p[i]] = true;
        if (p[i] == 0)
            miss++;
    }
    for (int i = 2; i <= n; i += 2)
        if (!visited[i])
            even++;
    for (int i = 0; i <= n; i++)
    {
        dp[0][0][i] = dp[1][0][i] = INF;
    }
    if (p[0] == 0)
    {
        dp[0][0][1] = dp[1][0][0] = 0;
    }
    else
    {
        if (p[0] % 2 == 0)
            dp[0][0][0] = 0;
        else
            dp[1][0][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
            {
                if (p[i] == 0)
                {
                    dp[0][i][j] = INF;
                    dp[1][i][j] = min(dp[1][i - 1][j], dp[0][i - 1][j] + 1);
                }
                else
                {
                    if (p[i] % 2 == 0)
                    {
                        dp[0][i][j] = min(dp[1][i - 1][j] + 1, dp[0][i - 1][j]);
                        dp[1][i][j] = INF;
                    }
                    else
                    {
                        dp[0][i][j] = INF;
                        dp[1][i][j] = min(dp[1][i - 1][j], dp[0][i - 1][j] + 1);
                    }
                }
            }
            else
            {
                if (p[i] == 0)
                {
                    dp[0][i][j] = min(dp[1][i - 1][j - 1] + 1, dp[0][i - 1][j - 1]);
                    dp[1][i][j] = min(dp[1][i - 1][j], dp[0][i - 1][j] + 1);
                }
                else
                {
                    if (p[i] % 2 == 0)
                    {
                        dp[0][i][j] = min(dp[1][i - 1][j] + 1, dp[0][i - 1][j]);
                        dp[1][i][j] = INF;
                    }
                    else
                    {
                        dp[0][i][j] = INF;
                        dp[1][i][j] = min(dp[1][i - 1][j], dp[0][i - 1][j] + 1);
                    }
                }
            }
        }
    }
    cout << min(dp[0][n - 1][even], dp[1][n - 1][even]) << endl;
    return 0;
}