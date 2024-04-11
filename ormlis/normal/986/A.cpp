#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
using namespace __gnu_pbds;


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
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m, k, s; cin >> n >> m >> k >> s;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    range(_, m) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> to(n);
    for(int c = 1; c <= k; ++c) {
        vector<int> d(n, -1);
        queue<int> q;
        range(i, n) {
            if (a[i] == c) {
                d[i] = 0;
                q.push(i);
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto &u : g[v]) {
                if (d[u] != -1) continue;
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
        range(i, n) to[i].push_back(d[i]);
    }
    range(i, n) {
        sort(all(to[i]));
        ll sum = 0;
        range(j, s) sum += to[i][j];
        cout << sum << ' ';
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