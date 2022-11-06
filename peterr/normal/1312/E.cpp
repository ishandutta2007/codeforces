#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int a[MAXN];
int dp[MAXN][MAXN];
int ans[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = -1;
            for (int k = i + 1; k <= j; k++)
            {
                if (dp[i][k - 1] == dp[k][j] && dp[i][k - 1] != -1)
                    dp[i][j] = dp[i][k - 1] + 1;
            }
        }
    }
    ans[0] = 1;
    for (int i = 1; i < n; i++)
    {
        ans[i] = i + 1;
        for (int j = i; j > 0; j--)
        {
            if (dp[j][i] != -1)
                ans[i] = min(ans[i], 1 + ans[j - 1]);
        }
        if (dp[0][i] != -1)
            ans[i] = 1;
    }
    cout << ans[n - 1] << endl;
    return 0;
}