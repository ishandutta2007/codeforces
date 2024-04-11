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

void solve(int n, int start, vector<pair<int, int>> &res) {
    if (n == 1) {
        return;
    }
    solve(n / 2, start, res);
    solve(n / 2, start + n / 2, res);
    for (int i = 0; i < n / 2; ++i) {
        res.emplace_back(start + i, start + n / 2 + i);
    }
}

void solve() {
    int n;
    cin >> n;
    int k = 1;
    while (k * 2 <= n) {
        k *= 2;
    }
    vector<pair<int, int>> res;
    solve(k, 1, res);
    if (k < n) {
        solve(k, n - k + 1, res);
    }
    cout << sz(res) << '\n';
    for (auto [a, b]: res) {
        cout << a << ' ' << b << '\n';
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