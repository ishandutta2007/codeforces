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

const int INFi = 2e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 1e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<int> g[maxN];

void dfs(int v, int p) {
    if (g[v].size() == 2) {
        cout << "NO\n";
        exit(0);
    }
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

void solve() {
    int n; cin >> n;
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            dfs(i, -1);
            break;
        }
    }
    cout << "YES\n";
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