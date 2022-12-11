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
    int wins = 0;
    int len = 0;
    vector<int> lens;
    for (auto ch: s) {
        if (ch == 'W') {
            if (len > 0) {
                lens.push_back(len);
            }
            ++wins;
            len = 0;
        } else if (wins > 0) {
            ++len;
        }
    }
    int rest = k;
    sort(lens.begin(), lens.end());
    int cnt = sz(lens);
    for (auto x: lens) {
        rest -= x;
        if (rest >= 0) {
            --cnt;
        }
    }
    if (k == 0 && wins == 0) {
        cout << 0 << '\n';
    } else {
        cout << 2 * min(n, wins + k) - (cnt + 1) << '\n';
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
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}