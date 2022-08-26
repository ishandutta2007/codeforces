#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<set<int>> g(n);
    vector<pair<int, int>> edges(m);
    range(i, m) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        edges[i] = {x, y};
        g[x].insert(y);
        g[y].insert(x);
    }
    queue<int> q;
    range(i, n) {
        if (g[i].size() < k) q.push(i);
    }
    int sz = n;
    vector<int> ans(m);
    for(int i = m - 1; i >= 0; --i) {
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            sz--;
            for(auto &u : g[v]) {
                g[u].erase(v);
                if (g[u].size() == k - 1) {
                    q.push(u);
                }
            }
        }
        ans[i] = sz;
        auto [x, y] = edges[i];
        if (g[x].size() < k || g[y].size() < k) continue;
        g[x].erase(y);
        g[y].erase(x);
        if (g[x].size() < k) {
            q.push(x);
        }
        if (g[y].size() < k) {
            q.push(y);
        }
    }
    range(i, m) cout << ans[i] << '\n';
    cout << '\n';
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