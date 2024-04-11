#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
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
        n = values.size();
        levels = largest_bit(n) + 1;
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

struct edge {
    int node = -1;
    long long weight = 0;

    edge() {}

    edge(int _node, long long _weight) : node(_node), weight(_weight) {}
};

struct weighted_LCA {
    int n = 0;
    vector<vector<edge>> adj;
    vector<int> parent, depth, subtree_size;
    vector<long long> weighted_depth, up_weight;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, tour_list, postorder;
    vector<int> heavy_root;
    RMQ<int> rmq;

    weighted_LCA(int _n = 0) {
        init(_n);
    }

    // Warning: this does not call build().
    weighted_LCA(const vector<vector<edge>> &_adj) {
        init(_adj);
    }

    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        weighted_depth.resize(n);
        up_weight.assign(n, 0);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
        postorder.resize(n);
        heavy_root.resize(n);
    }

    // Warning: this does not call build().
    void init(const vector<vector<edge>> &_adj) {
        init(_adj.size());
        adj = _adj;
    }

    void add_edge(int a, int b, long long weight) {
        adj[a].emplace_back(b, weight);
        adj[b].emplace_back(a, weight);
    }

    void erase_edge(int from, int to) {
        for (edge &e : adj[from])
            if (e.node == to) {
                swap(e, adj[from].back());
                adj[from].pop_back();
                return;
            }

        assert(false);
    }

    void dfs(int node, int par, long long weight) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;
        weighted_depth[node] = weight;

        // Erase the edge to parent.
        if (par >= 0)
            erase_edge(node, par);

        for (edge &e : adj[node]) {
            up_weight[e.node] = e.weight;
            dfs(e.node, node, weight + e.weight);
            subtree_size[node] += subtree_size[e.node];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](const edge &a, const edge &b) {
            return subtree_size[a.node] > subtree_size[b.node];
        });
    }

    int tour, post_tour;

    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = euler.size();
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (edge &e : adj[node]) {
            tour_dfs(e.node, heavy_child);
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
                dfs(i, -1, 0);

        tour = post_tour = 0;

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        assert((int) euler.size() == 2 * n);
        vector<int> euler_depths;

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        rmq.build(euler_depths);
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
        int anc = get_lca(a, b);
        return is_ancestor(anc, x) && (is_ancestor(x, a) || is_ancestor(x, b));
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }

    long long get_weighted_dist(int a, int b) const {
        return weighted_depth[a] + weighted_depth[b] - 2 * weighted_depth[get_lca(a, b)];
    }

    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));

        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(is_ancestor(child, b));
        return child;
    }
};


int N, K;

void solve_case() {
    cin >> K;
    N = 2 * K;
    weighted_LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;
        a--; b--;
        lca.add_edge(a, b, weight);
    }

    lca.build();
    long long lowest = 0, highest = 0;

    for (int i = 1; i < N; i++) {
        if (lca.subtree_size[i] % 2 != 0)
            lowest += lca.up_weight[i];

        highest += min(lca.subtree_size[i], N - lca.subtree_size[i]) * lca.up_weight[i];
    }

    cout << lowest << ' ' << highest << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}