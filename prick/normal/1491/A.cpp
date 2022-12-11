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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll mod) {
    return (ull)rng() % mod;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int ones = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) ++ones;
    }
    for (int i = 0; i < q; ++i) {
        int tp, x;
        cin >> tp >> x;
        if (tp == 1) {
            if (a[x]) --ones;
            else ++ones;
            a[x] = 1 - a[x];
        } else {
            if (x <= ones) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
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