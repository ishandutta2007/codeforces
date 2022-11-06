#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
const int MAXM = 10;
const int MOD = 1E9 + 7;
int dp1[MAXM + 1][MAXN + 1];
int dp2[MAXM + 1][MAXN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    fill(dp1[1], dp1[1] + n + 1, 1);
    fill(dp2[1], dp2[1] + n + 1, 1);
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                dp1[i][j] += dp1[i - 1][k];
                if (dp1[i][j] >= MOD)
                    dp1[i][j] -= MOD;
            }
            for (int k = j; k <= n; k++)
            {
                dp2[i][j] += dp2[i - 1][k];
                if (dp2[i][j] >= MOD)
                    dp2[i][j] -= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int temp = (int) (((long long) dp1[m][i] * dp2[m][j]) % MOD);
            ans += temp;
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}