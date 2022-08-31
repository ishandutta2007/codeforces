#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> p(n); for (auto& c : p) cin >> c, --c;

    // pair up cycles (they'll have 2 1's in them)
    // then keep removing stuff while maintaining the 2 1's invariant

    vector<int> root; root.reserve(n);
    vector<bool> vis(n);
    vector<int> ones;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        int c = i;
        do {
            vis[c] = 1;
            c = p[c];
        } while (c != i);

        if (p[i] != i) {
            root.push_back(i);
        } else {
            ones.push_back(i);
        }
    }
    vector<pair<int, int>> ans;
    vector<int> col(n, 0);

    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[p[i]] = i;

    set<pair<int, int>> s;
    // s contains the set of pairs {col, x} if col[p[x]] == 1

    auto col_at_pos = [&](int x) {
        return col[p[x]];
    };
    auto op = [&](int x, int y) {
        ans.emplace_back(x, y);

        vector<int> use{x, y, inv[x], inv[y]};
        for (int c : use) s.erase({col_at_pos(c), c});

        swap(inv[p[x]], inv[p[y]]);
        col[p[x]] ^= 1, col[p[y]] ^= 1;
        swap(p[x], p[y]);

        for (int c : use) {
            if (col_at_pos(c) == 1) {
                // assert(c != p[c]);
                s.insert({col_at_pos(p[c]), c});
            }
        }
    };

    for (int i = 0; i < sz(root) - 1; i += 2) {
        int a = root[i], b = root[i+1];
        op(a, b);
    }
    if (sz(root) % 2) {
        if (sz(root) == 1) {
            if (sz(ones)) {
                int a = root[0], b = ones[0];
                op(a, b);
            } else {
                int a = 0, b = p[0], c = inv[0];
                op(a, b);
                op(b, c);
            }
        } else {
            // merge the last cycle into a previous one
            // (previous one has size at least 4, since it's the sum of two cycles)
            int a = root.back(), b = s.begin()->first;
            op(a, b);
        }
    }

    while (sz(s)) {
        auto [x, c] = *s.begin(); s.erase(s.begin());
        op(c, p[c]);
    }
    assert(sz(ans) <= n + 1);
    cout << sz(ans) << '\n';
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}

// 1 3
// 2 1
// 2 3
//
// [2, 1, 3]
// [-3, 1, -2]
// [-1, 3, -2]
// [-1, 2, -3]