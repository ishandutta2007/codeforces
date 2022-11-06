#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 5000;
const int MOD = 1E9 + 7;
int dp[MAXN + 1][MAXN + 1];
int a[MAXN + 1];
int ways[MAXN + 1];
 
void add(int &x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
 
    //fill(ways + 1, ways + n + 1, 1);
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j > 1)
                add(dp[i][j], dp[i - 1][j - 1]);
            if (j < n)
                add(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    for (int j = 0; j <= k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            add(ways[i], (int) ((long long) dp[j][i] * dp[k - j][i] % MOD));
        }
    }
    /*
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            add(ways[i], (int) ((long long) dp[j][i] * dp[k - j][i] % MOD));
            //cout << ways[i] << endl;
        }
    }
    */
    /*
    for (int i = 1; i <= n; i++)
        cout << "ways " << i << " " << ways[i] << endl;
    */
    int ans = 0;
    for (int i = 1; i <= n; i++)
        add(ans, (int) ((long long) ways[i] * a[i] % MOD));
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        add(ans, MOD - (int) ((long long) ways[i] * a[i] % MOD));
        a[i] = x;
        add(ans, (int) ((long long) ways[i] * a[i] % MOD));
        cout << ans << "\n";
    }
    return 0;
}