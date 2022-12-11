#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n);
    dp[0] = 1;
    vector<int> f(n);
    f[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = (i + 1) * (f[i - 1] * 2 + dp[i - 1] - f[i - 1] - 1);
        f[i] = f[i - 1] * (i + 1);
        dp[i] %= mod;
        f[i] %= mod;
    }
    cout << dp[n - 1] % mod << endl;
    return 0;
}