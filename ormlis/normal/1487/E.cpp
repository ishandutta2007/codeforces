#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < (n); ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

const ll INF = 1e18;

using namespace std;
const int md = 1e9 + 7;
const int INFi = 2e9;
const int maxN = 59;

void solve() {
    vector<int> n(4);
    range(i, 4) cin >> n[i];
    vector<vector<int>> a(4);
    range(j, 4) {
        int m = n[j];
        a[j].resize(m);
        range(i, m) cin >> a[j][i];
    }
    vector<pair<int, int>> dp(n[0]);
    range(i, n[0]) {
        dp[i] = {a[0][i], i};
    }
    sort(all(dp));
    for (int j = 1; j < 4; ++j) {
        int m;
        cin >> m;
        vector<set<int>> g(n[j]);
        range(_, m) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[y].insert(x);
        }
        int k = n[j];
        vector<pair<int, int>> newdp;
        range(i, k) {
            int mn = INFi;
            for (auto &[z, pos] : dp) {
                if (g[i].count(pos)) continue;
                mn = min(mn, z);
                break;
            }
            if (mn != INFi) newdp.emplace_back(mn + a[j][i], i);
        }
        sort(all(newdp));
        swap(dp, newdp);
    }
    if (dp.empty()) cout << "-1\n";
    else cout << dp.front().first << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}