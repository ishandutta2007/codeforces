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
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    range(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    vector<int> c(n);
    int ans = 0;
    range(i, n) {
        if (g[i].empty() || *g[i].rbegin() < i) {
            c[i] = 1;
        }
        ans += c[i];
    }
    int q;
    cin >> q;
    auto check = [&](int i) {
        ans -= c[i];
        c[i] = 0;
        if (g[i].empty() || *g[i].rbegin() < i) {
            c[i] = 1;
        }
        ans += c[i];
    };
    range(_, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].insert(v);
            g[v].insert(u);
            check(u);
            check(v);
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].erase(v);
            g[v].erase(u);
            check(u);
            check(v);
        } else {
            cout << ans << '\n';
        }
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