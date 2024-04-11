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
const int maxN = 4e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int dp[maxN];
vector<int> g[maxN];

void dfs(int v, int p) {
    int childs = 0;
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        childs++;
    }
    dp[v] = 0;
    if (childs == 0) {
        return;
    }
    vector<int> need;
    for(auto &u : g[v]) {
        if (u == p) continue;
        need.emplace_back(dp[u]);
    }
    sort(rall(need));
    range(i, childs) {
        dp[v] = max(dp[v], max(need[i], 1) + i);
    }
    dp[v] = max(dp[v], childs);
}

int ans = 0;

void check(int v) {
    vector<int> can;
    for(auto &u : g[v]) {
        can.push_back(dp[u]);
    }
    sort(rall(can));
    int was = 0;
    range(i, (int)can.size()) {
        ans = max(ans, i + was + max(can[i], 1));
        was = max(was, max(can[i], 1) - 1);
    }
    ans = max(ans, was + (int)can.size());
}

bool dfs_reroot(int v, int p, int f) {
    if (f == v) return true;
    check(v);
    vector<pair<int, int>> childs;
    for(auto &u : g[v]) {
        childs.emplace_back(dp[u], u);
    }
    sort(rall(childs));
    int sz = childs.size();
    vector<int> dp1(sz), dp2(sz);
    range(i, sz) {
        dp1[i] = max(childs[i].first, 1) + i;
        if (i) dp1[i] = max(dp1[i], dp1[i - 1]);
    }
    range(i, sz) {
        dp2[i] = max(childs[i].first, 1) + i - 1;
    }
    for(int i = sz - 2; i >= 0; --i) dp2[i] = max(dp2[i], dp2[i + 1]);
    int was = dp[v];
    range(i, sz) {
        if (childs[i].second == p) continue;
        int cur = sz - 1;
        if (i) cur = max(cur, dp1[i - 1]);
        if (i + 1 < sz) cur = max(cur, dp2[i + 1]);
        dp[v] = cur;
        if (dfs_reroot(childs[i].second, v, f)) return true;
    }
    dp[v] = was;
    return false;
}

int query(int r) {
    cout << "? " << r << endl;
    int x; cin >> x;
    return x;
}

int findA(int v, int p) {
    sort(all(g[v]), [&] (const int &i, const int &j) {
        return dp[i] > dp[j];
    });
    if (g[v].size() == 1) {
        return query(v);
    }
    for(auto &u : g[v]) {
        if (u == p) continue;
        int x = findA(u, v);
        if (x != v) return x;
    }
    return v;
}

void solve() {
    int n; cin >> n;
    range(_, n - 1) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    dfs_reroot(1, -1, -1);
    cout << ans << endl;
    int f; cin >> f;
    dfs(f, -1);
    int root = f;
    sort(all(g[root]), [&] (const int &i, const int &j) {
        return dp[i] > dp[j];
    });
    vector<int> answ;
    for(auto &u : g[root]) {
        int t = findA(u, root);
        if (t == root) continue;
        answ.emplace_back(t);
        if (answ.size() == 2) break;
    }
    while(answ.size() < 2) {
        answ.emplace_back(root);
    }
    cout << "! " << answ[0] << " " << answ[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}