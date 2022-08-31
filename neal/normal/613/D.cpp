// Solution to https://codeforces.com/contest/613/problem/D
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, tour_list, postorder;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;

    LCA(int _n = 0) {
        init(_n);
    }

    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
        postorder.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }

    int tour, post_tour;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
        postorder[node] = post_tour++;
    }

    void build() {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
                dfs(i, -1);

        tour = post_tour = 0;
        euler.clear();
        euler.reserve(2 * n);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        rmq.build(euler_depths);
        built = true;
    }

    pair<int, int> find_farthest(int node, int par, int path) const {
        pair<int, int> current = {path, node};

        for (int neighbor : adj[node])
            if (neighbor != par)
                current = max(current, find_farthest(neighbor, node, path + 1));

        return current;
    }

    // Warning: this must be called before build(), since build() erases half of the edges.
    pair<int, pair<int, int>> get_diameter() const {
        int u = find_farthest(0, -1, 0).second;
        pair<int, int> farthest = find_farthest(u, -1, 0);
        int v = farthest.second;
        return {farthest.first, {u, v}};
    }

    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);

        return euler[rmq.query_index(a, b + 1)];
    }

    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }

    int get_kth_ancestor(int a, int k) const {
        while (a >= 0) {
            int root = heavy_root[a];

            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];

            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }

        return a;
    }

    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes.
    int get_common_node(int a, int b, int c) const {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);

        if (depth[y] > depth[x])
            x = y;

        if (depth[z] > depth[x])
            x = z;

        return x;
    }

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));

        return result;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        lca.add_edge(u, v);
    }

    lca.build();
    int Q;
    cin >> Q;
    vector<bool> is_important(N, false);
    vector<vector<int>> compress_adj(N);
    vector<array<int, 2>> dp(N, {0, 0});

    for (int q = 0; q < Q; q++) {
        int k;
        cin >> k;
        vector<int> important(k);

        for (int &city : important) {
            cin >> city;
            city--;
            is_important[city] = true;
        }

        bool has_edge = false;

        for (int &city : important)
            if (lca.parent[city] >= 0 && is_important[lca.parent[city]])
                has_edge = true;

        if (has_edge) {
            cout << -1 << '\n';
        } else {
            vector<pair<int, int>> compressed = lca.compress_tree(important);

            for (auto &p : compressed)
                if (p.second >= 0)
                    compress_adj[p.second].push_back(p.first);

            int C = int(compressed.size());
            int compress_root = compressed.front().first;

            for (int i = C - 1; i >= 0; i--) {
                int node = compressed[i].first;

                // dp[node][0] = min invasions to solve this subtree where node does not have access to an important node.
                // dp[node][1] = min invasions to solve this subtree where node *may* have access to an important node.

                if (is_important[node]) {
                    dp[node][1] = 0;

                    // Since node itself is important, every child must be the 0 case.
                    for (int child : compress_adj[node])
                        dp[node][1] += dp[child][0];

                    // Invading above node gets us dp[node][0].
                    dp[node][0] = dp[node][1] + 1;
                } else {
                    int sum0 = 0, sum1 = 0, min_diff = 0;

                    for (int child : compress_adj[node]) {
                        sum0 += dp[child][0];
                        sum1 += dp[child][1];
                        min_diff = min(min_diff, dp[child][1] - dp[child][0]);
                    }

                    // dp[node][0] can either take dp[child][0] everywhere or take dp[child][1] everywhere and invade node.
                    dp[node][0] = min(sum0, sum1 + 1);

                    // dp[node][1] can take at most one dp[child][1],
                    dp[node][1] = min(sum0 + min_diff, dp[node][0]);
                }

                assert(dp[node][1] <= dp[node][0]);
            }

            cout << dp[compress_root][1] << '\n';

            // Make sure to undo all of the changes.
            for (auto &p : compressed) {
                int node = p.first;
                dp[node] = {0, 0};
                compress_adj[node].clear();
            }
        }

        for (int &city : important)
            is_important[city] = false;
    }
}