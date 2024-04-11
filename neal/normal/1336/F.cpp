#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using splay_key = int;

struct splay_node {
    splay_node *parent = nullptr, *child[2] = {nullptr, nullptr};
    splay_key key;
    int size = 1;

    static int get_size(splay_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    int parent_index() const {
        if (parent == nullptr)
            return -1;

        return this == parent->child[0] ? 0 : 1;
    }

    void set_child(int index, splay_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
    }
};

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 splay_rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
int64_t splay_count = 0;

struct splay_tree {
    static const int POOL_SIZE = 10000;
    static vector<splay_node*> node_pool;
    static vector<splay_node*> pointers_to_delete;

    static splay_node* new_node(const splay_key &key) {
        if (node_pool.empty()) {
            splay_node *ptr = new splay_node[POOL_SIZE];
            pointers_to_delete.push_back(ptr);

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        splay_node *node = node_pool.back();
        node_pool.pop_back();
        node->key = key;
        return node;
    }

    static void _delete_pointers() {
        for (splay_node *node : pointers_to_delete)
            delete[] node;
    }

    splay_node *root = nullptr;

    splay_tree() {
        atexit(_delete_pointers);
    }

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return root == nullptr ? 0 : root->size;
    }

    splay_node *set_root(splay_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return root = x;
    }

    void rotate_up(splay_node *x, bool x_join = true) {
        splay_node *p = x->parent, *gp = p->parent;
        int index = x->parent_index();

        if (gp == nullptr)
            set_root(x);
        else
            gp->set_child(p->parent_index(), x);

        p->set_child(index, x->child[!index]);
        x->set_child(!index, p);
        p->join();

        if (x_join)
            x->join();
    }

    void splay(splay_node *x) {
        splay_count++;

        while (x != root) {
            splay_node *p = x->parent;

            if (p != root)
                rotate_up(x->parent_index() == p->parent_index() ? p : x, false);

            rotate_up(x, false);
        }

        x->join();
    }

    static constexpr double SPLAY_RNG_RANGE = splay_rng.max() + 1.0;
    static constexpr double LOG_CONSTANT = 2.0;
    static constexpr double SPLAY_PROBABILITY = 0.25;
    static const int SIZE_CUTOFF = 100;

    void check_splay(splay_node *x, int depth) {
        int n = size(), log_n = 32 - __builtin_clz(n);

        // Splay when deep or with a certain random chance when small.
        if (depth > LOG_CONSTANT * log_n || (n < SIZE_CUTOFF && splay_rng() < SPLAY_PROBABILITY * SPLAY_RNG_RANGE))
            splay(x);
    }

    pair<splay_node*, int> insert(const splay_key &key, bool require_unique = false) {
        return insert(new_node(key), require_unique);
    }

    // Returns {new node pointer, index (number of existing elements that are strictly less)}
    pair<splay_node*, int> insert(splay_node *x, bool require_unique = false) {
        if (root == nullptr)
            return {set_root(x), 0};

        splay_node *current = root, *prev = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            prev = current;
            depth++;

            if (current->key < x->key) {
                below += splay_node::get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                // Check for equal keys.
                if (require_unique && !(x->key < current->key)) {
                    below += splay_node::get_size(current->child[0]);
                    check_splay(current, depth);
                    return {current, below};
                }

                current = current->child[0];
            }
        }

        prev->set_child(prev->key < x->key ? 1 : 0, x);
        check_splay(x, depth);

        for (splay_node *node = x; node != nullptr; node = node->parent)
            node->join();

        return {x, below};
    }

    splay_node *begin() {
        if (root == nullptr)
            return nullptr;

        splay_node *x = root;
        int depth = 0;

        while (x->child[0] != nullptr) {
            x = x->child[0];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    // To iterate through all nodes in order:
    // for (splay_node *node = tree.begin(); node != nullptr; node = tree.successor(node))
    splay_node *successor(splay_node *x) const {
        if (x->child[1] != nullptr) {
            x = x->child[1];

            while (x->child[0] != nullptr)
                x = x->child[0];

            return x;
        }

        while (x->parent_index() == 1)
            x = x->parent;

        return x->parent;
    }

    splay_node *last() {
        splay_node *x = root;
        int depth = 0;

        while (x->child[1] != nullptr) {
            x = x->child[1];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    void clear() {
        vector<splay_node*> nodes;
        nodes.reserve(size());

        for (splay_node *node = begin(); node != nullptr; node = successor(node))
            nodes.push_back(node);

        for (splay_node *node : nodes) {
            // Instead of deleting, add `node` back to `node_pool`.
            *node = splay_node();
            node_pool.push_back(node);
        }

        set_root(nullptr);
    }

    void erase(splay_node *x) {
        splay_node *new_x = nullptr, *fix_node = nullptr;

        if (x->child[0] == nullptr || x->child[1] == nullptr) {
            new_x = x->child[x->child[0] == nullptr ? 1 : 0];
            fix_node = x->parent;
        } else {
            splay_node *next = successor(x);
            assert(next != nullptr && next->child[0] == nullptr);
            new_x = next;
            fix_node = next->parent == x ? next : next->parent;

            next->parent->set_child(next->parent_index(), next->child[1]);
            next->set_child(0, x->child[0]);
            next->set_child(1, x->child[1]);
        }

        if (x == root)
            set_root(new_x);
        else
            x->parent->set_child(x->parent_index(), new_x);

        int depth = 0;

        for (splay_node *node = fix_node; node != nullptr; node = node->parent) {
            node->join();
            depth++;
        }

        if (fix_node != nullptr)
            check_splay(fix_node, depth);

        // Instead of deleting, add `x` back to `node_pool`.
        *x = splay_node();
        node_pool.push_back(x);
    }

    // Returns {node pointer, index (number of existing elements that are strictly less)}
    pair<splay_node*, int> lower_bound(const splay_key &key) {
        splay_node *current = root, *prev = nullptr, *answer = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            prev = current;
            depth++;

            if (current->key < key) {
                below += splay_node::get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                answer = current;
                current = current->child[0];
            }
        }

        if (prev != nullptr)
            check_splay(prev, depth);

        return make_pair(answer, below);
    }

    bool contains(const splay_key &key) {
        splay_node *node = lower_bound(key).first;
        return node != nullptr && node->key == key;
    }

    bool erase(const splay_key &key) {
        splay_node *x = lower_bound(key).first;

        if (x == nullptr || x->key != key)
            return false;

        erase(x);
        return true;
    }

    // Returns a splay_node pointer representing all nodes with key less than `key`. Note the return can be `nullptr`.
    splay_node *query_prefix(const splay_key &key) {
        splay_node *node = lower_bound(key).first;

        if (node == nullptr)
            return root;

        splay(node);
        return node->child[0];
    }

    splay_node *node_at_index(int index) {
        if (index < 0 || index >= size())
            return nullptr;

        splay_node *current = root;
        int depth = 0;

        while (current != nullptr) {
            int left_size = splay_node::get_size(current->child[0]);
            depth++;

            if (index == left_size) {
                check_splay(current, depth);
                return current;
            }

            if (index < left_size) {
                current = current->child[0];
            } else {
                current = current->child[1];
                index -= left_size + 1;
            }
        }

        assert(false);
    }
};

vector<splay_node*> splay_tree::node_pool;
vector<splay_node*> splay_tree::pointers_to_delete;

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
        n = values.size();
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
        first_occurrence[node] = euler.size();
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

        assert((int) euler.size() == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());

        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);

        rmq.build(euler_depths);
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

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};

        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = nodes.size();

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < (int) nodes.size(); i++)
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

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

template<typename T>
struct tree_sum_DS {
    LCA &lca;
    bool vertex_mode;
    vector<T> values;
    fenwick_tree<T> tour_tree, postorder_tree;
    T tree_sum = 0;

    // Warning: make sure to call init as well.
    tree_sum_DS(LCA &_lca) : lca(_lca) {}

    // Warning: make sure the LCA object is already initialized before calling this.
    void init(bool _vertex_mode) {
        vertex_mode = _vertex_mode;
        values.assign(lca.n, 0);
        tour_tree.init(lca.n);
        postorder_tree.init(lca.n);
    }

    void update_node(int node, T change) {
        values[node] += change;
        tree_sum += change;
        tour_tree.update(lca.tour_start[node], change);
        postorder_tree.update(lca.postorder[node], change);
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
        // The set of nodes whose tour_start is less than tour_end[node] minus the set of nodes whose postorder is less
        // than postorder[node] is exactly the path from node to the root, inclusive.
        return tour_tree.query(lca.tour_end[node]) - postorder_tree.query(lca.postorder[node]);
    }

    // Returns the sum of tree values for all nodes / edges on the path from `u` to `v`, inclusive.
    T query_path(int u, int v, int ancestor = -1) const {
        if (ancestor < 0)
            ancestor = lca.get_lca(u, v);

        return query_root_path(u) + query_root_path(v) - 2 * query_root_path(ancestor) + (vertex_mode ? values[ancestor] : 0);
    }

    // Returns the sum of tree values for all nodes / edges in the subtree of `node`, inclusive when in `vertex_mode`.
    T query_subtree(int node) const {
        return tour_tree.query(lca.tour_start[node], lca.tour_end[node]) - (vertex_mode ? 0 : values[node]);
    }
};


struct path {
    int x, y;
};

int N, M, K;
LCA lca;
tree_sum_DS<int> DS(lca);
vector<vector<path>> paths_at_lca;
int64_t different_answer, same_answer;

void different_lca_dfs(int node) {
    vector<path> &paths = paths_at_lca[node];

    for (path &p : paths) {
        if (lca.depth[p.x] - lca.depth[node] >= K)
            different_answer += DS.query_subtree(lca.get_kth_node_on_path(node, p.x, K));

        if (lca.depth[p.y] - lca.depth[node] >= K)
            different_answer += DS.query_subtree(lca.get_kth_node_on_path(node, p.y, K));
    }

    dbg(node, different_answer);

    for (path &p : paths) {
        DS.update_node(p.x, +1);
        DS.update_node(p.y, +1);
    }

    for (int child : lca.adj[node])
        different_lca_dfs(child);

    for (path &p : paths) {
        DS.update_node(p.x, -1);
        DS.update_node(p.y, -1);
    }
}

vector<splay_tree> path_set;

void merge_into(int from, int to) {
    assert(from != to);

    if (path_set[from].size() > path_set[to].size())
        swap(path_set[from], path_set[to]);

    auto &&query_subtree = [&](int node) {
        return path_set[to].lower_bound(lca.tour_end[node]).second - path_set[to].lower_bound(lca.tour_start[node]).second;
    };

    for (splay_node *x = path_set[from].begin(); x != nullptr; x = path_set[from].successor(x)) {
        int node = lca.tour_list[x->key];

        if (lca.get_dist(to, node) >= K) {
            int goal = lca.get_kth_node_on_path(to, node, K);

            if (lca.is_ancestor(goal, to)) {
                // Go back one, and exclude this subtree instead.
                goal = lca.child_ancestor(goal, to);
                same_answer += path_set[to].size() - query_subtree(goal);
            } else {
                // Count all results within this subtree.
                same_answer += query_subtree(goal);
            }
        }
    }

    for (splay_node *x = path_set[from].begin(); x != nullptr; x = path_set[from].successor(x))
        path_set[to].insert(x->key);

    path_set[from].clear();
}

void same_lca_dfs(int node) {
    vector<path> &paths = paths_at_lca[node];

    sort(paths.begin(), paths.end(), [&](const path &p, const path &q) {
        return lca.tour_start[p.x] < lca.tour_start[q.x];
    });

    // Count pairs whose tour ranges completely don't intersect. In this case, the path will be K shared edges from the
    // lca down toward both the smaller y and the larger x.
    for (path &p : paths) {
        same_answer += DS.query_root_path(p.x);

        if (lca.depth[p.y] - lca.depth[node] >= K)
            DS.update_node(lca.get_kth_node_on_path(node, p.y, K), +1);
    }

    for (path &p : paths)
        if (lca.depth[p.y] - lca.depth[node] >= K)
            DS.update_node(lca.get_kth_node_on_path(node, p.y, K), -1);

    dbg("A", node, same_answer);

    // Count pairs whose tour ranges intersect. We can use lca.compress_tree and do smaller-to-larger when combining
    // x-values to query y-values in the appropriate range.
    vector<int> nodes = {node};

    for (path &p : paths)
        nodes.push_back(p.x);

    vector<pair<int, int>> compressed = lca.compress_tree(nodes);

    // Insert each path into its x-node by using `merge_into`.
    for (int i = 0; i < (int) paths.size(); i++) {
        path &p = paths[i];
        path_set[N].insert(lca.tour_start[p.y]);
        merge_into(N, p.x);
    }

    for (int i = (int) compressed.size() - 1; i > 0; i--)
        merge_into(compressed[i].first, compressed[i].second);

    dbg("B", node, same_answer);
    path_set[node].clear();

    for (int child : lca.adj[node])
        same_lca_dfs(child);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M >> K;
    lca.init(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        lca.add_edge(u, v);
    }

    lca.build();
    DS.init(true);
    paths_at_lca.assign(N, {});
    dbg(lca.tour_list);

    for (int i = 0; i < M; i++) {
        path p;
        cin >> p.x >> p.y;
        p.x--; p.y--;

        if (lca.get_dist(p.x, p.y) < K)
            continue;

        if (lca.tour_start[p.x] > lca.tour_start[p.y])
            swap(p.x, p.y);

        paths_at_lca[lca.get_lca(p.x, p.y)].push_back(p);
    }

    different_answer = same_answer = 0;
    path_set.assign(N + 1, {});
    different_lca_dfs(0);
    same_lca_dfs(0);

    cerr << different_answer << ' ' << same_answer << endl;
    cout << different_answer + same_answer << '\n';
}