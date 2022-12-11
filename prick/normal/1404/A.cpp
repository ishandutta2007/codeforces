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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> fixed(k, -1);
    for (int i = 0; i < n; ++i) {
        int pos = i % k;
        if (s[i] == '?') {
            continue;
        }
        int d = s[i] - '0';
        if (fixed[pos] == -1) {
            fixed[pos] = d;
        } else if (fixed[pos] != d) {
            cout << "NO\n";
            return;
        }
    }
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
        if (fixed[i] == 0) ++a;
        else if (fixed[i] == 1) ++b;
    }
    if (a <= k / 2 && b <= k / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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

	int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}