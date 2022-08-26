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
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll d[maxN][4];
vector<pair<int, int>> g[maxN];

void solve() {
    int n, m; cin >> n >> m;
    range(_, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for(int i = 1; i <= n; ++i) range(j, 4) d[i][j] = INF;
    d[1][0] = 0;
    set<ar<ll, 3>> q;
    q.insert({0, 1, 0});
    while(!q.empty()) {
        auto [dd, v, mask] = *q.begin();
        q.erase(q.begin());
        for(auto &[u, w] : g[v]) {
            if (d[u][mask] > dd + w) {
                if (d[u][mask] != INF) q.erase({d[u][mask], u, mask});
                d[u][mask] = dd + w;
                q.insert({d[u][mask], u, mask});
            }
            if ((mask & 1) == 0 && d[u][mask | 1] > dd) {
                if (d[u][mask | 1] != INF) q.erase({d[u][mask | 1], u, mask | 1});
                d[u][mask | 1] = dd;
                q.insert({d[u][mask | 1], u, mask | 1});
            }
            if ((mask & 2) == 0 && d[u][mask | 2] > dd + w * 2) {
                if (d[u][mask | 2] != INF) q.erase({d[u][mask | 2], u, mask | 2});
                d[u][mask | 2] = dd + w * 2;
                q.insert({d[u][mask | 2], u, mask | 2});
            }
            if (mask == 0 && d[u][3] > dd + w) {
                if (d[u][3] != INF) q.erase({d[u][3], u, 3});
                d[u][3] = dd + w;
                q.insert({d[u][3], u, mask});
            }
        }
    }
    for(int i = 2; i <= n; ++i) {
        cout << d[i][3] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}