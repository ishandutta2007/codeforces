#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 200;
int dp[MAXN + 1][2 * MAXN + 1];
int a[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2 * n; j++)
            {
                dp[i][j] = INF;
                if (j < i)
                    continue;
                for (int k = 1; k <= j; k++)
                {
                    if (dp[i - 1][k - 1] == INF)
                        continue;
                    dp[i][j] = min(dp[i][j], abs(k - a[i]) + dp[i - 1][k - 1]);
                }
            }
        }
        cout << dp[n][2 * n] << "\n";
    }
    return 0;
}