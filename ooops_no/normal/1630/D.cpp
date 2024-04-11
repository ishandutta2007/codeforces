#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int g = 0;
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            g = gcd(g, b[i]);
        }
        vector<vector<int>> dp(g, vector<int>(2));
        for (int i = 0; i < g; i++) {
            dp[i][1] = -INF;
        }
        for (int i = 0; i < n; i++) {
            int res = max(dp[i % g][0] + a[i], dp[i % g][1] - a[i]), res2 = max(dp[i % g][0] - a[i], dp[i % g][1] + a[i]);
            dp[i % g][0] = res;
            dp[i % g][1] = res2;
        }
        int ans = 0, ans2 = 0;
        for (int i = 0; i < g; i++) {
            ans += dp[i][0];
            ans2 += dp[i][1];
        }
        cout << max(ans, ans2) << endl;
    }
    return 0;
}