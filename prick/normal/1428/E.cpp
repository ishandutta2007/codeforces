//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long

#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

int f(int x, int k) {
    return (x / k) * (x / k) * (k - x % k) +
           ((x + k - 1) / k) * ((x + k - 1) / k) * (x % k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    set<tuple<int, int, int>> d;
    for (int i = 0; i < n; ++i) {
        ans += f(a[i], 1);
        if (a[i] > 1) {
            d.insert(make_tuple(f(a[i], 2) - f(a[i], 1), i, 2));
        }
    }
    for (int iter = 0; iter < k - n; ++iter) {
        assert(!d.empty());
        auto [diff, pos, parts] = *d.begin();
        d.erase(d.begin());
        ans += diff;
        if (a[pos] > parts) {
            d.insert(make_tuple(
                f(a[pos], parts + 1) - f(a[pos], parts),
                pos, parts + 1
            ));
        }
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