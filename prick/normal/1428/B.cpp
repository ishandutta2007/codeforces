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
    string s;
    cin >> s;
    bool ok1 = true, ok2 = true;
    for (auto ch: s) {
        if (ch == '>') {
            ok1 = false;
        }
        if (ch == '<') {
            ok2 = false;
        }
    }
    if (ok1 || ok2) {
        cout << n << '\n';
        return;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int prev = (i + n - 1) % n;
        if (s[prev] == '-' || s[i] == '-') {
            ++ans;
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
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}