#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

// you have to choose a subset of a path, and take the max independent set out of neighbors of the chosen nodes

// MergeInto : Aggregate * Value * Vertex(int) * EdgeIndex(int) -> Aggregate
template <class Aggregate, class Value, class MergeInto>
auto exclusive(const std::vector<Value>& a, const Aggregate& base,
               const MergeInto& merge_into, int vertex) {
    int n = (int)std::size(a);
    std::vector<Aggregate> b(n, base);
    for (int bit = (int)std::__lg(n); bit >= 0; --bit) {
        for (int i = n - 1; i >= 0; --i) b[i] = b[i >> 1];
        int sz = n - (n & !bit);
        for (int i = 0; i < sz; ++i) {
            int index = (i >> bit) ^ 1;
            b[index] = merge_into(b[index], a[i], vertex, i);
        }
    }
    return b;
}
 
// MergeInto : Aggregate * Value * Vertex(int) * EdgeIndex(int) -> Aggregate
// Base : Vertex(int) -> Aggregate
// FinalizeMerge : Aggregate * Vertex(int) -> Value
template <class Aggregate, class Value, class MergeInto, class FinalizeMerge,
          class Base>
auto rerooter(const std::vector<std::vector<int>>& g, const Value& default_val,
              const Aggregate&, const Base& base, const MergeInto& merge_into,
              const FinalizeMerge& finalize_merge) {
    int n = (int)std::size(g);
 
    std::vector<Value> root_dp(n, default_val);
    std::vector<std::vector<Value>> edge_dp(n);
 
    std::vector<Value> dp(n, default_val);
 
    std::vector<int> bfs(n), parent(n, -1);
    int cnt = 1;
    parent[0] = 0;
    for (int i = 0; i < n; ++i) {
        int u = bfs[i];
        for (auto v : g[u]) {
            if (parent[v] != -1) continue;
            parent[v] = u;
            bfs[cnt++] = v;
        }
    }
 
    for (int i = n - 1; i >= 0; --i) {
        int u = bfs[i];
        int p = parent[u];
        Aggregate aggregate = base(u);
        for (auto v : g[u]) {
            if (v == p) continue;
            aggregate = merge_into(aggregate, dp[v], u, v);
        }
        dp[u] = finalize_merge(aggregate, u);
    }
 
    for (auto u : bfs) {
        dp[parent[u]] = dp[u];
        edge_dp[u].reserve(g[u].size());
        for (auto v : g[u]) edge_dp[u].push_back(dp[v]);
        auto dp_exclusive = exclusive(edge_dp[u], base(u), merge_into, u);
        for (int i = 0; i < (int)dp_exclusive.size(); ++i) {
            auto v = g[u][i];
            dp[v] = finalize_merge(dp_exclusive[i], u);
        }
        root_dp[u] =
            finalize_merge(merge_into(dp_exclusive[0], edge_dp[u][0], u, 0), u);
    }
 
    return make_pair(root_dp, edge_dp);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    auto calc_dp = [&]() {
        struct Data {
            int on_path;
            int root_on_path;
            int chosen;

            Data() {
                chosen = 1;
                on_path = 0;
                root_on_path = 0;
            }
        };

        auto merge_into = [&](Data vertex_dp, Data neighbor_dp, int vertex, int neighbor) {
            vertex_dp.chosen = max(vertex_dp.chosen, neighbor_dp.on_path + 1);
            int cnt_children = sz(adj[vertex]) - 1;
            vertex_dp.on_path = max(vertex_dp.on_path, cnt_children - 1 + max(neighbor_dp.chosen, neighbor_dp.on_path));
            cnt_children++;
            vertex_dp.root_on_path = max(vertex_dp.root_on_path, cnt_children - 1 + max(neighbor_dp.chosen, neighbor_dp.on_path));
            return vertex_dp;
        };
        auto finalize_merge = [&](Data vertex_dp, int vertex) {
            return vertex_dp;
        };
        auto base = [&](int vertex) {
            return Data();
        };

        auto [root_dp, edge_dp] = rerooter(adj, Data(), Data(), base, merge_into, finalize_merge);

        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = root_dp[i].root_on_path;
        }
        return dp;
    };

    auto dp = calc_dp();
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}