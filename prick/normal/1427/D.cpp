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
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        segs.emplace_back(x, x);
    }
    vector<vector<int>> answer;
    while (true) {
        vector<pair<int, int>> next;
        for (auto [left, right]: segs) {
            if (!next.empty() && left == next.back().Y + 1) {
                int L = next.back().X;
                next.pop_back();
                next.emplace_back(L, right);
            } else {
                next.emplace_back(left, right);
            }
        }
        segs = next;
        if (sz(segs) == 1) {
            break;
        }
        vector<int> pref(sz(segs) + 1);
        for (int i = 0; i < sz(segs); ++i) {
            pref[i + 1] = pref[i] + segs[i].Y - segs[i].X + 1;
        }
        bool ok = false;
        for (int i = 0; i < sz(segs) && !ok; ++i) {
            for (int j = i + 1; j < sz(segs) && !ok; ++j) {
                if (segs[j].Y == segs[i].X - 1) {
                    ok = true;
                    answer.push_back({pref[i], pref[j] - pref[i], pref[j + 1] - pref[j], pref.back() - pref[j + 1]});
                    reverse(segs.begin(), segs.begin() + i);
                    reverse(segs.begin() + i, segs.begin() + j);
                    reverse(segs.begin() + (j + 1), segs.end());
                    
                    reverse(segs.begin(), segs.end());
                }
            }
        }
        
    }
    cout << sz(answer) << '\n';
    for (const auto &vec: answer) {
        vector<int> out;
        for (auto i: vec) {
            if (i > 0) out.push_back(i);
        }
        assert(!out.empty());
        cout << sz(out);
        for (auto i: out) {
            cout << ' ' << i;
        }
        cout << '\n';
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