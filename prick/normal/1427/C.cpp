//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

void solve() {
    int r, n;
    cin >> r >> n;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    x[0] = y[0] = 1;
    t[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> x[i] >> y[i];
    }
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = -1e7;
        for (int j = max(0, i - 2000); j < i; ++j) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}