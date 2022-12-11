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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<int> p(n);
    p[0] = a[0];
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] == p[i - 1]) {
            p[i] = b[i];
        } else {
            p[i] = a[i];
        }
    }
    set<int> d{a[n - 1], b[n - 1], c[n - 1]};
    if (d.count(p[0])) d.erase(p[0]);
    if (d.count(p[n - 2])) d.erase(p[n - 2]);
    p[n - 1] = *d.begin();
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
    cout << '\n';
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
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}