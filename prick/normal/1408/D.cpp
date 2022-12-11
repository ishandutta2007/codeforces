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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    vector<int> c(m), d(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }
    vector<pair<int, int>> need;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = max(0, c[j] + 1 - a[i]);
            int y = max(0, d[j] + 1 - b[i]);
            need.emplace_back(x, y);
        }
    }
    need.emplace_back(0, 0);
    sort(need.begin(), need.end());
    int N = sz(need);
    vector<int> sufmax(N + 1);
    for (int i = N - 1; i >= 0; --i) {
        sufmax[i] = max(sufmax[i + 1], need[i].second);
    }
    int ans = (int) 1e7;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, need[i].first + sufmax[i + 1]);
    }
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