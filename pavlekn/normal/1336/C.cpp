#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

const int MAXN = 3e3 + 23;

int dp[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    reverse(s.begin(), s.end());
    //reverse(t.begin(), t.end());
    while (t.size() < s.size())
    {
        t.push_back('$');
    }
    for (int i = 0; m + i <= n; ++i)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (s[i] == t[j] || t[j] == '$')
            {
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }
            if (s[i] == t[n - (i + 1 - j)] || t[n - (i + 1 - j)] == '$')
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}