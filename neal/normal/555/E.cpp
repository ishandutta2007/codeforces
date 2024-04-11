// Solution to https://codeforces.com/contest/555/problem/E
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};

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
    vector<int> parent;
    vector<int> depth;
    vector<int> euler;
    vector<int> first_occurrence;
    vector<int> tour_start;
    vector<int> tour_end;
    RMQ<int> rmq;

    LCA(int _n = -1) {
        if (_n >= 0)
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
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
    }

    void init(const vector<vector<int>> &_adj) {
        init(_adj.size());
        adj = _adj;
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int tour;

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        first_occurrence[node] = euler.size();
        euler.push_back(node);
        tour_start[node] = tour++;

        if (par >= 0)
            adj[node].erase(find(adj[node].begin(), adj[node].end(), par));

        for (int child : adj[node]) {
            dfs(child, node);
            euler.push_back(node);
        }

        tour_end[node] = tour;
    }

    void build() {
        tour = 0;
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        assert((int) euler.size() == 2 * n);
        vector<int> euler_depths;

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        rmq.build(euler_depths);
    }

    // Note: returns -1 if a and b aren't connected.
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

    // Returns the child of a that is an ancestor of b.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));
        assert(!adj[a].empty());
        int low = 0, high = (int) adj[a].size() - 1;

        while (low < high) {
            int mid = (low + high) / 2;

            if (tour_start[b] < tour_end[adj[a][mid]])
                high = mid;
            else
                low = mid + 1;
        }

        int child = adj[a][low];
        assert(is_ancestor(child, b));
        return child;
    }
};


struct edge {
    int node, index;

    edge() {}

    edge(int _node, int _index) : node(_node), index(_index) {}
};

int N, M, Q;
vector<vector<edge>> adj;
vector<int> parent, depth, highest;
vector<bool> visited, is_bridge;
LCA lca;

void dfs(int node, int par) {
    assert(!visited[node]);
    visited[node] = true;
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    highest[node] = depth[node];

    for (edge &e : adj[node]) {
        if (e.node == par)
            continue;

        if (visited[e.node]) {
            highest[node] = min(highest[node], depth[e.node]);
        } else {
            dfs(e.node, node);
            is_bridge[e.index] = highest[e.node] == depth[e.node];
            highest[node] = min(highest[node], highest[e.node]);
        }
    }
}

enum status {
    NONE,
    UP,
    DOWN
};

vector<status> edge_status;
vector<int> next_different;

// Finds the first strict ancestor of node that has different status from target (which is the status of the first node
// queried), or -1 if no such ancestor exists.
int find_different(int node, status target) {
    if (node < 0 || edge_status[node] != target)
        return node;

    // Path compression.
    return next_different[node] = find_different(next_different[node], target);
}

// Mark all nodes from node (inclusive) to anc (exclusive) as target. Returns true if successful and false if conflict.
bool mark_path(int node, int anc, status target) {
    while (node >= 0 && depth[node] > depth[anc]) {
        if (edge_status[node] != target && edge_status[node] != NONE)
            return false;

        edge_status[node] = target;
        node = find_different(node, target);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    parent.resize(N);
    depth.resize(N);
    highest.resize(N);
    visited.assign(N, false);
    is_bridge.assign(M, false);

    for (int i = 0; i < N; i++)
        if (!visited[i])
            dfs(i, -1);

    union_find biconnected_UF(N);

    for (int i = 0; i < N; i++)
        for (edge &e : adj[i])
            if (!is_bridge[e.index])
                biconnected_UF.unite(i, e.node);

    lca.init(N);
    union_find tree_UF(N);

    for (int i = 0; i < N; i++)
        for (edge &e : adj[i])
            if (is_bridge[e.index]) {
                int a = biconnected_UF.find(i);
                int b = biconnected_UF.find(e.node);

                if (tree_UF.unite(a, b))
                    lca.add_edge(a, b);
            }

    lca.build();
    edge_status.assign(N, NONE);
    next_different = parent;

    for (int q = 0; q < Q; q++) {
        int source, destination;
        cin >> source >> destination;
        source--; destination--;
        source = biconnected_UF.find(source);
        destination = biconnected_UF.find(destination);
        int anc = lca.get_lca(source, destination);

        if (anc < 0 || !mark_path(source, anc, UP) || !mark_path(destination, anc, DOWN)) {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
}