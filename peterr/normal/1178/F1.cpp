#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 500;
int color[MAXN];
int dp[MAXN + 1][MAXN + 1];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> color[i];
    for (int i = 0; i <= m; i++)
    {
        dp[i][i] = 1;
    }
    for (int len = 1; len <= m; len++)
    {
        for (int left = 0; left + len <= m; left++)
        {
            int right = left + len;
            int index = left;
            for (int j = left; j < right; j++)
            {
                if (color[j] < color[index])
                    index = j;
            }
            int leftWays = 0;
            for (int k = index; k >= left; k--)
            {
                leftWays = (leftWays + (long long) dp[left][k] * dp[k][index]) % MOD;
            }
            for (int k = index + 1; k <= right; k++)
            {
                int ways = (long long) leftWays * ((long long) dp[index + 1][k] * dp[k][right] % MOD) % MOD;
                dp[left][right] = (dp[left][right] + ways) % MOD;
            }
        }
    }
    cout << dp[0][m] << endl;
    return 0;
}