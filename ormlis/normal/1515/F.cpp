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
const int maxN = 3e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll a[maxN];
bool used[maxN];
vector<pair<int, int>> g[maxN];
vector<int> ord1;
vector<int> ord2;

ll x;

void dfs(int v) {
    used[v] = true;
    for(auto &[u, i] : g[v]) {
        if (used[u]) continue;
        dfs(u);
        if (a[u] >= x) {
            ord1.push_back(i);
            a[v] += a[u] - x;
        } else {
            ord2.push_back(i);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    ll s = accumulate(a + 1, a + n + 1, 0ll);
    if (s < 1ll * (n - 1) * x) {
        cout << "NO\n";
        return;
    }
    range(_, m) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, _});
        g[v].push_back({u, _});
    }
    dfs(1);
    cout << "YES\n";
    for(auto &i : ord1) cout << i + 1 << '\n';
    reverse(all(ord2));
    for(auto &i : ord2) cout << i + 1 << '\n';
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