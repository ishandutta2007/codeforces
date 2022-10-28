#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n); for (auto& s : g) cin >> s;

    ar<int, 2> mn{MOD, MOD};
    ar<int, 2> mx{-MOD, -MOD};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'B') {
                int x = i + j, y = i - j;
                mn[0] = min(mn[0], x), mn[1] = min(mn[1], y);
                mx[0] = max(mx[0], x), mx[1] = max(mx[1], y);
            }
        }
    }

    pair<int, ar<int, 2>> ans{MOD, {-1, -1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i + j, y = i - j;
            int d = max({abs(x - mn[0]), abs(x - mx[0]), abs(y - mn[1]), abs(y - mx[1])});
            ans = min(ans, make_pair(d, ar<int, 2>{i, j}));
        }
    }
    cout << ans.second[0]+1 << ' ' << ans.second[1]+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}