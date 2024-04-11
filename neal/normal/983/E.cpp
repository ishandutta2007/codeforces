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

    int better_index(int a, int b) const {
        return (values[a] < values[b]) ^ maximum_mode ? a : b;
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
    vector<int> parent, depth;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, tour_list;
    RMQ<int> rmq;

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
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
    }

    // Warning: this does not call build().
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
        tour_list[tour] = node;
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

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);
        tree_sum = 0;

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        assert(count <= tree_n);
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    // Returns the last i in [0, N] such that query(i) <= sum, or -1 if no such i exists (sum < 0).
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const int INF = 1e9 + 5;

struct path_query {
    int y, index;
};

int N, M, Q;
LCA lca;
vector<vector<int>> bus_lca;
vector<vector<int>> bus_endpoint;
vector<int> single_bus;
vector<vector<int>> bus_jump;
vector<vector<path_query>> queries_at;
vector<int> answers;
fenwick_tree<int> tree;

int largest_bit(int x) {
    return 31 - __builtin_clz(x);
}

int higher(int a, int b) {
    return lca.depth[a] < lca.depth[b] ? a : b;
}

void bus_dfs(int node) {
    single_bus[node] = node;

    for (int anc : bus_lca[node])
        single_bus[node] = higher(single_bus[node], anc);

    for (int child : lca.adj[node]) {
        bus_dfs(child);
        single_bus[node] = higher(single_bus[node], single_bus[child]);
    }
}

void build_bus_jump() {
    bus_jump.assign(largest_bit(N) + 1, vector<int>(N));
    bus_jump[0] = single_bus;

    for (int k = 0; k < largest_bit(N); k++)
        for (int i = 0; i < N; i++)
            bus_jump[k + 1][i] = bus_jump[k][bus_jump[k][i]];
}

int min_buses_to_ancestor(int node, int anc) {
    if (node == anc)
        return 0;

    assert(lca.is_ancestor(anc, node));
    assert(lca.depth[node] > lca.depth[anc]);
    int buses = 0;

    for (int i = largest_bit(N); i >= 0; i--) {
        int candidate = bus_jump[i][node];

        if (lca.depth[candidate] > lca.depth[anc]) {
            node = candidate;
            buses += 1 << i;
        }
    }

    assert(lca.depth[node] > lca.depth[anc]);
    node = single_bus[node];
    buses++;
    return lca.depth[node] <= lca.depth[anc] ? buses : INF;
}

int get_kth_bus_ancestor(int node, int k) {
    for (int i = 0; 1 << i <= k; i++)
        if (k >> i & 1)
            node = bus_jump[i][node];

    return node;
}

void path_dfs(int node) {
    vector<int> saved(queries_at[node].size());

    for (int i = 0; i < (int) queries_at[node].size(); i++) {
        int y = queries_at[node][i].y;
        saved[i] = tree.query(lca.tour_start[y], lca.tour_end[y]);
    }

    for (int end : bus_endpoint[node])
        tree.update(lca.tour_start[end], +1);

    for (int child : lca.adj[node])
        path_dfs(child);

    for (int i = 0; i < (int) queries_at[node].size(); i++) {
        int y = queries_at[node][i].y;
        int paths_covering = tree.query(lca.tour_start[y], lca.tour_end[y]) - saved[i];

        // `paths_covering` is the number of paths that include the path node -- y.
        if (paths_covering > 0)
            answers[queries_at[node][i].index]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    lca.init(N);

    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        lca.add_edge(p, i);
    }

    lca.build();
    bus_lca.assign(N, {});
    bus_endpoint.assign(N, {});
    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int anc = lca.get_lca(a, b);
        bus_lca[a].push_back(anc);
        bus_lca[b].push_back(anc);
        bus_endpoint[a].push_back(b);
        bus_endpoint[b].push_back(a);
    }

    single_bus.resize(N);
    bus_dfs(0);
    build_bus_jump();
    cin >> Q;
    queries_at.assign(N, {});
    answers.resize(Q);

    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        int anc = lca.get_lca(u, v);
        int u_buses = min_buses_to_ancestor(u, anc);
        int v_buses = min_buses_to_ancestor(v, anc);

        if (u_buses >= INF || v_buses >= INF) {
            answers[i] = -1;
        } else {
            answers[i] = u_buses + v_buses;

            if (u_buses > 0 && v_buses > 0) {
                int x = get_kth_bus_ancestor(u, u_buses - 1);
                int y = get_kth_bus_ancestor(v, v_buses - 1);
                queries_at[x].push_back({y, i});
            }
        }
    }

    tree.init(N);
    path_dfs(0);

    for (int answer : answers)
        cout << answer << '\n';
}