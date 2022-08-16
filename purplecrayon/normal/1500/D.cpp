#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1.5e3+10, MOD = 1e9+7;
const int Q = 11;

int n, q;
int a[N][N];
ar<pair<int, int>, Q> comb[N][N], mine[N][N];

ar<pair<int, int>, 2 * Q> store;
int has[N * N];
int tt = 1;

void merge(auto& a, const auto& b) {
    std::merge(a.begin(), a.end(), b.begin(), b.end(), store.begin());
    int cnt = 0; tt++;
    for (int j = 0; j <= 2 * q + 1 && cnt <= q; j++) if (store[j].first != MOD && has[store[j].second] != tt) {
        has[store[j].second] = tt;
        a[cnt++] = store[j];
    }
}
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        mine[i][j].fill({MOD, MOD});

    ar<pair<int, int>, Q> horiz, vert;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> use;
        for (int j = n-1; j >= 0; j--) {
            int prv_loc = -1;
            for (int k = 0; k < sz(use); k++) if (use[k].first == a[i][j]) prv_loc = k;
            if (prv_loc != -1) {
                use.erase(use.begin() + prv_loc);
            }
            use.push_back({a[i][j], j});
            if (sz(use) > q + 1) use.erase(use.begin());

            horiz.fill({MOD, MOD});
            for (int k = 0; k < sz(use); k++) {
                horiz[k] = {use[sz(use) - k - 1].second - j, use[sz(use) - k - 1].first};
            }
            merge(mine[i][j], horiz);
        }
    }
    for (int j = 0; j < n; j++) {
        vector<pair<int, int>> use;
        for (int i = n-1; i >= 0; i--) {
            int prv_loc = -1;
            for (int k = 0; k < sz(use); k++) if (use[k].first == a[i][j]) prv_loc = k;
            if (prv_loc != -1) {
                use.erase(use.begin() + prv_loc);
            }
            use.push_back({a[i][j], i});
            if (sz(use) > q + 1) use.erase(use.begin());

            vert.fill({MOD, MOD});
            for (int k = 0; k < sz(use); k++) {
                vert[k] = {use[sz(use) - k - 1].second - i, use[sz(use) - k - 1].first};
            }
            merge(mine[i][j], vert);
        }
    }
    vector<int> ans(n + 2);
    auto add_range = [&](int L, int R) {
        ans[L]++;
        ans[R+1]--;
    };
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            comb[i][j].fill({MOD, MOD});
            if (i < n-1 && j < n-1) {
                for (int k = 0; k <= q; k++) if (comb[i+1][j+1][k].first != MOD) {
                    comb[i][j][k] = comb[i+1][j+1][k];
                    comb[i][j][k].first++;
                }
            }

            merge(comb[i][j], mine[i][j]);

            if (comb[i][j][q].first == MOD) {
                // ans += min(n - i, n - j);
                add_range(1, min(n - i, n - j));
            } else {
                // ans += comb[i][j][q].first;
                add_range(1, min({n - i, n - j, comb[i][j][q].first}));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}