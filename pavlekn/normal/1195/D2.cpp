#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

const int MAXN = 2e5 + 7;

int dp[MAXN][2];

int pw[30];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < 30; ++i)
    {
        pw[i] = pw[i - 1] * 10;
        pw[i] %= mod;
    }
    int n;
    cin >> n;
    vector<string> a(n);
    int ans = 0;
    vector<int> cnt(11);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++cnt[a[i].size()];
        reverse(a[i].begin(), a[i].end());
    }
    for (int i = 0; i < n; ++i)
    {
        for (int l = 1; l < 11; ++l)
        {
            int cur = 0;
            for (int j = 0; j < min(l, (int)a[i].size()); ++j)
            {
                cur += (a[i][j] - '0') * (pw[2 * j] + pw[2 * j + 1]);
                cur %= mod;
            }
            for (int j = min(l, (int)a[i].size()); j < a[i].size(); ++j)
            {
                cur += (a[i][j] - '0') * pw[l + j] * 2;
                cur %= mod;
            }
            cur *= cnt[l];
            ans += cur;
            ans %= mod;
        }
    }
    cout << ans << endl;
}