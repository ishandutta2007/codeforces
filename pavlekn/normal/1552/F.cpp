#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    vector<int> s(n + 1);
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> r[i] >> l[i] >> s[i];
    }
    vector<int> ans(n + 1);
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int L = 0;
        int R = i;
        while (R - L > 1)
        {
            int MED = (L + R) / 2;
            if (r[MED] < l[i])
            {
                L = MED;
            }
            else
            {
                R = MED;
            }
        }
        if (s[i] == 0)
        {
            ans[i] = ans[i - 1] + (r[i] - r[i - 1]);
        }
        else
        {
            ans[i] = ans[i - 1] + 2 * (r[i] - r[i - 1]) + dp[i - 1] - dp[L] - (l[i] - r[L]);
        }
        dp[i] = dp[i - 1] + 2 * (r[i] - r[i - 1]) + dp[i - 1] - dp[L] - (l[i] - r[L]);
        ans[i] %= mod;
        ans[i] += mod;
        ans[i] %= mod;
        dp[i] += mod;
        dp[i] %= mod;
    }
    cout << (ans[n] + 1) % mod << endl;
    return 0;
}