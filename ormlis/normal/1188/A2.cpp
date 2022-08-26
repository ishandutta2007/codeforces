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

vector<pair<int, int>> g[maxN];

vector<ar<ll, 3>> ans;

vector<pair<int, ll>> dfs(int v, int p, int pw) {
    vector<vector<pair<int, ll>>> childs;
    for (auto &[u, w] : g[v]) {
        if (u == p) continue;
        auto kek = dfs(u, v, w);
        childs.push_back(kek);
    }
    if (childs.empty()) return {{v, pw}};
    if (childs.size() == 1) {
        ll sm = 0;
        for(auto &[a, b] : childs[0]) sm += b;
        if (sm != pw && p != -1) {
            cout << "NO\n";
            exit(0);
        }
        return childs[0];
    }
    ll sm = 0;
    for(auto &ch : childs) for(auto &[a, b] : ch) sm += b;
    auto a = childs[0][0], b = childs[1][0];
    ll d = (sm - pw) / 2;
    ans.push_back({a.first, b.first, d});
    childs[0][0].second -= d;
    childs[1][0].second -= d;
    vector<pair<int, ll>> ret;
    for(auto &ch : childs) for(auto &pr : ch) ret.push_back(pr);
    return ret;
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int u, v;
        cin >> u >> v;
        int x;
        cin >> x;
        g[u].push_back({v, x});
        g[v].push_back({u, x});
    }
    int r = -1;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            r = i;
            break;
        }
    }
    auto res = dfs(r, -1, 0);
    for(auto &[a, b] : res) {
        ans.push_back({r, a, b});
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto &[a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';
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