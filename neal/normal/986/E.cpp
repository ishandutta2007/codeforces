// Solution to https://codeforces.com/contest/986/problem/E
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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
        return x == 0 ? -1 : 31 - __builtin_clz(x);
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
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, rev_tour_list;
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
        postorder.resize(n);
        tour_list.resize(n);
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
        adj[node].shrink_to_fit();

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

    void build(int root = -1, bool build_rmq = true) {
        parent.assign(n, -1);

        if (0 <= root && root < n)
            dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
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

        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        if (build_rmq)
            rmq.build(euler_depths);

        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const {
        assert(built);

        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};

        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return uxv_max;
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
    // It is also the node with the minimum sum of distances to all three nodes (the centroid of the three nodes).
    int get_common_node(int a, int b, int c) const {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        x = depth[y] > depth[x] ? y : x;
        x = depth[z] > depth[x] ? z : x;
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

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
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
        count = min(count, tree_n);
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

    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);

        if (current == value)
            return false;

        update(index, value - current);
        return true;
    }

    // Returns the largest p in `[0, tree_n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, tree_n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `tree_n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = largest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

template<typename T>
struct range_add_point_query_tree {
    int tree_n = 0;
    fenwick_tree<T> tree;

    range_add_point_query_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.init(n);
    }

    // O(n) initialization of the range_add_point_query_tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        vector<T> initial_diffs(tree_n);

        for (int i = 0; i < tree_n; i++)
            initial_diffs[i] = initial[i] - (i > 0 ? initial[i - 1] : 0);

        tree.build(initial_diffs);
    }

    // Adds change to all indices in the range [start, end).
    void update(int start, int end, const T &change) {
        assert(0 <= start && start <= end && end <= tree_n);
        if (start < tree_n) tree.update(start, change);
        if (end < tree_n) tree.update(end, -change);
    }

    // Queries the value at `index`.
    T query(int index) const {
        assert(0 <= index && index < tree_n);
        return tree.query(index + 1);
    }
};

template<typename T>
struct tree_sum_DS {
    // TODO: decide whether BUILD_SUBTREES = true is needed (for query_subtree).
    static const bool BUILD_SUBTREES = false;

    LCA &lca;
    bool vertex_mode;
    vector<T> values;
    range_add_point_query_tree<T> path_tree;
    fenwick_tree<T> tour_tree;
    T tree_sum = 0;

    // Warning: make sure to call init as well.
    tree_sum_DS(LCA &_lca) : lca(_lca) {}

    // Warning: make sure the LCA object is already initialized before calling this.
    void init(bool _vertex_mode) {
        vertex_mode = _vertex_mode;
        values.assign(lca.n, 0);
        path_tree.init(lca.n);
        if (BUILD_SUBTREES) tour_tree.init(lca.n);
    }

    void update_node(int node, T change) {
        values[node] += change;
        tree_sum += change;
        path_tree.update(lca.tour_start[node], lca.tour_end[node], change);
        if (BUILD_SUBTREES) tour_tree.update(lca.tour_start[node], change);
    }

    void update_edge(int a, int b, T change) {
        // Edge values are stored at the deeper node.
        if (lca.parent[a] == b)
            swap(a, b);

        assert(a == lca.parent[b]);
        update_node(b, change);
    }

    // Returns the sum of tree values for all nodes / edges on the path from `node` to the root, inclusive.
    T query_root_path(int node) const {
        return path_tree.query(lca.tour_start[node]);
    }

    // Returns the sum of tree values for all nodes / edges on the path from `u` to `v`, inclusive.
    T query_path(int u, int v, int anc = -1) const {
        if (anc < 0)
            anc = lca.get_lca(u, v);

        return query_root_path(u) + query_root_path(v) - 2 * query_root_path(anc) + (vertex_mode ? values[anc] : 0);
    }

    // Returns the sum of tree values for all nodes / edges in the subtree of `node`, inclusive when in `vertex_mode`.
    T query_subtree(int node) const {
        assert(BUILD_SUBTREES);
        return tour_tree.query(lca.tour_start[node], lca.tour_end[node]) - (vertex_mode ? 0 : values[node]);
    }
};


const int MOD = int(1e9) + 7;

int64_t mod_pow(int64_t a, int64_t p, int64_t m = MOD) {
    int64_t result = 1;

    while (p > 0) {
        if (p & 1)
            result = result * a % m;

        p >>= 1;

        if (p > 0)
            a = a * a % m;
    }

    return result;
}

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};

    for (int i = 2; i <= maximum; i += 2) {
        prime[i] = i == 2;
        smallest_factor[i] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }

    if (maximum >= 2)
        primes.push_back(2);

    for (int p = 3; p <= maximum; p += 2)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
        }
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

struct safe_hash {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template<typename T>
    uint64_t operator()(T x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
        return sizeof(x) <= 4 ? hash32(unsigned(x ^ FIXED_RANDOM)) : splitmix64(x ^ FIXED_RANDOM);
    }
};

const int AX_MAX = int(1e7) + 5;

struct query {
    int u, v, ancestor, answer;
};

int main() {
    sieve(AX_MAX);

    int N, Q;
    scanf("%d", &N);
    LCA lca(N);
    tree_sum_DS<int> DS(lca);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        lca.add_edge(u, v);
    }

    lca.build();
    DS.init(true);
    gp_hash_table<int, vector<pair<int, int>>, safe_hash> prime_nodes, prime_queries;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);

        while (a > 1) {
            int p = smallest_factor[a];
            int power = 0;

            do {
                a /= p;
                power++;
            } while (a % p == 0);

            prime_nodes[p].emplace_back(power, i);
        }
    }

    scanf("%d", &Q);
    vector<query> queries(Q);

    for (int q = 0; q < Q; q++) {
        int x;
        scanf("%d %d %d", &queries[q].u, &queries[q].v, &x);
        queries[q].u--; queries[q].v--;
        queries[q].ancestor = DS.lca.get_lca(queries[q].u, queries[q].v);
        queries[q].answer = 1;

        while (x > 1) {
            int p = smallest_factor[x];
            int power = 0;

            do {
                x /= p;
                power++;
            } while (x % p == 0);

            prime_queries[p].emplace_back(power, q);
        }
    }

    for (auto &pq : prime_queries) {
        int p = pq.first;
        vector<pair<int, int>> &p_nodes = prime_nodes[p];
        vector<pair<int, int>> &p_queries = pq.second;
        sort(p_queries.begin(), p_queries.end());
        sort(p_nodes.rbegin(), p_nodes.rend());
        vector<pair<int, int>> node_updates;
        int power = 0;

        for (pair<int, int> &p_query : p_queries) {
            int q_power = p_query.first, q_index = p_query.second;

            if (q_power > power) {
                for (pair<int, int> &p_node : p_nodes) {
                    int n_power = p_node.first, n_index = p_node.second;

                    if (n_power < power)
                        break;

                    int change = min(q_power, n_power) - power;
                    DS.update_node(n_index, change);
                    node_updates.emplace_back(n_index, change);
                }

                power = q_power;
            }

            int exponent = DS.query_path(queries[q_index].u, queries[q_index].v, queries[q_index].ancestor);
            queries[q_index].answer = int(int64_t(queries[q_index].answer) * mod_pow(p, exponent) % MOD);
        }

        // Reverse all the tree updates.
        for (pair<int, int> &update : node_updates)
            DS.update_node(update.first, -update.second);
    }

    for (int q = 0; q < Q; q++)
        printf("%d\n", queries[q].answer);
}