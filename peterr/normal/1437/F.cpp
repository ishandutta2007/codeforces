#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const int MOD = 998244353;
int a[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (2 * a[i] <= a[j])
            {
                dp[i][j] = (int) ((long long) (i - 1) * dp[i - 1][j] % MOD);
                add(dp[i][i], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = (int) ((long long) (i - 2) * dp[i - 1][j] % MOD);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(ans, dp[n][i]);
    }
    cout << ans << "\n";
    return 0;
}