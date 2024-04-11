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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
        for (int j = 0; j < a[i].size(); ++j)
        {
            ans += (a[i][j] - '0') * (pw[2 * j] + pw[2 * j + 1]);
            ans %= mod;
        }
    }
    ans *= n;
    ans %= mod;
    cout << ans << endl;
}