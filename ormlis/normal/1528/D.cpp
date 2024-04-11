#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 600 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int g[maxN][maxN];
int ans[maxN][maxN];
int mns[maxN];

void solve() {
    int n; cin >> n;
    range(i, n) {
        range(j, n) {
            ans[i][j] = g[i][j] = INFi;
        }
        ans[i][i] = 0;
    }
    int m; cin >> m;
    range(i, m) {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    range(i, n) {
        range(_, 2) {
            g[i][0] = min(g[i][0], g[i][n - 1] + 1);
            for(int j = 1; j < n; ++j) g[i][j] = min(g[i][j], g[i][j - 1] + 1);
        }
        int mn = 0;
        range(j, n) if (g[i][j] < g[i][mn]) mn = j;
        mns[i] = mn;
        range(j, n) {
            ans[i][j] = min(ans[i][j], g[i][j]);
        }
    }
    set<ar<int, 3>> s;
    range(i, n) {
        range(j, n) {
            s.insert({ans[i][j], i, j});
        }
    }
    while(!s.empty()) {
        auto [d, i, j] = *s.begin();
        assert(d != INFi);
        s.erase(s.begin());
        range(w, n) {
            int to = (d + w) % n;
            if (ans[i][to] > d + g[j][w]) {
                s.erase({ans[i][to], i, to});
                ans[i][to] = d + g[j][w];
                s.insert({ans[i][to], i, to});
            }
        }
    }
    range(i, n) {
        range(j, n) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}