#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }

        if (number != 0 || length == 0)
            write_char(char(number + '0'));

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

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

using hash_t = uint32_t;

struct segment_change {
    hash_t to_xor;

    segment_change(hash_t _to_xor = 0) : to_xor(_to_xor) {}
};

struct segment {
    hash_t hash;

    segment(hash_t _hash = 0) : hash(_hash) {}

    void apply(int, const segment_change &change) {
        // assert(length == 1);
        hash ^= change.to_xor;
    }

    void join(const segment &other) {
        hash ^= other.hash;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct persistent_basic_seg_tree {
    struct node {
        segment seg;
        int left = -1, right = -1;
    };

    int tree_n = 0;
    vector<node> tree;
    int reserve_size = INT32_MAX;

    persistent_basic_seg_tree(int n = -1, int max_updates = 0) {
        if (n >= 0)
            init(n, max_updates);
    }

    void init(int n, int max_updates = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        reserve_size = INT32_MAX;

        if (max_updates > 0) {
            int tree_height = 32 - __builtin_clz(tree_n);
            reserve_size = 2 * tree_n + max_updates * tree_height;
            tree.reserve(reserve_size);
        }

        tree.assign(2 * tree_n, node());

        for (int i = 1; i < tree_n; i++) {
            tree[i].left = 2 * i;
            tree[i].right = 2 * i + 1;
        }
    }

    int left(int position) const { return tree[position].left; }
    int right(int position) const { return tree[position].right; }
    segment& seg(int position) { return tree[position].seg; }
    const segment& seg(int position) const { return tree[position].seg; }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            seg(tree_n + i) = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            seg(position).join(seg(left(position)), seg(right(position)));
    }

    int make_copy(int position) {
        assert(0 <= position && position < int(tree.size()));
        tree.push_back(tree[position]);
        assert(int(tree.size()) <= reserve_size);
        return int(tree.size()) - 1;
    }

    void _query_tree(int position, int start, int end, int a, int b, segment &answer) const {
        if (a <= start && end <= b) {
            answer.join(seg(position));
            return;
        }

        if (left(position) < 0 || right(position) < 0)
            return;

        int mid = (start + end) / 2;
        if (a < mid) _query_tree(left(position), start, mid, a, b, answer);
        if (b > mid) _query_tree(right(position), mid, end, a, b, answer);
    }

    segment query(int root, int a, int b) const {
        assert(root > 0 && 0 <= a && a <= b && b <= tree_n);
        segment answer;
        _query_tree(root, 0, tree_n, a, b, answer);
        return answer;
    }

    // Directly assigning `tree[position].left = make_copy(left(position))` results in segmentation faults, because the
    // address for `tree[position]` can be computed before calling `make_copy`, which may reallocate `tree`.
    void set_left(int position, int result) { tree[position].left = result; }
    void set_right(int position, int result) { tree[position].right = result; }

    template<typename T_range_op>
    int _update_tree(int position, int start, int end, int index, T_range_op &&range_op) {
        position = make_copy(position);

        if (start <= index && index < end)
            range_op(position, end - start);

        if (left(position) < 0 || right(position) < 0)
            return position;

        int mid = (start + end) / 2;

        if (index < mid)
            set_left(position, _update_tree(left(position), start, mid, index, range_op));
        else
            set_right(position, _update_tree(right(position), mid, end, index, range_op));

        // seg(position).join(seg(left(position)), seg(right(position)));
        return position;
    }

    int update(int root, int index, const segment_change &change) {
        assert(root > 0 && 0 <= index && index < tree_n);

        return _update_tree(root, 0, tree_n, index, [&](int position, int length) {
            seg(position).apply(length, change);
        });
    }

    int update(int root, int index, const segment &new_seg) {
        assert(root > 0 && 0 <= index && index < tree_n);

        return _update_tree(root, 0, tree_n, index, [&](int position, int) {
            seg(position) = new_seg;
        });
    }

    // Removes all updates starting from `root` or later from the tree.
    void undo_updates(int root) {
        assert(root >= 2 * tree_n && root <= int(tree.size()));
        tree.resize(root);
    }

    vector<segment> to_array(int root) const {
        assert(root > 0);
        vector<int> level = {root};

        while (left(level.front()) >= 0) {
            vector<int> new_level;
            new_level.reserve(2 * level.size());

            for (int x : level) {
                new_level.push_back(left(x));
                new_level.push_back(right(x));
            }

            swap(level, new_level);
        }

        vector<segment> segs(level.size());

        for (int i = 0; i < int(level.size()); i++)
            segs[i] = seg(level[i]);

        return segs;
    }

    // Finds the last subarray starting at `first` that satisifes `should_join` via binary search in O(log n).
    template<typename T_bool>
    int find_last_subarray_paired(array<int, 2> roots, T_bool &&should_join, int n, int first = 0) const {
        assert(roots[0] > 0 && roots[1] > 0 && 0 <= first && first <= n);
        segment current;

        // Check the degenerate case.
        if (!should_join(current, current))
            return first - 1;

        return y_combinator([&](auto search, array<int, 2> position, int start, int end) -> int {
            if (end <= first)
                return end;
            else if (first <= start && end <= n && should_join(seg(position[0]), seg(position[1])))
                return end;
            else if (end - start == 1)
                return start;

            int mid = (start + end) / 2;
            int x = search(array<int, 2>{left(position[0]), left(position[1])}, start, mid);
            return x < mid ? x : search(array<int, 2>{right(position[0]), right(position[1])}, mid, end);
        })(roots, 0, tree_n);
    }
};


auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

int main() {
    IO::init();

    int N, Q;
    IO::read_int(N, Q);
    vector<int> A(N);

    for (auto &a : A) {
        IO::read_int(a);
        a--;
    }

    LCA lca(N);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        lca.add_edge(x, y);
    }

    lca.build();
    vector<hash_t> weights(N);

    for (auto &w : weights)
        w = hash_t(rng());

    persistent_basic_seg_tree tree(N, N + 1);
    tree.build(vector<segment>(N));
    vector<int> roots(N, -1);

    for (int node : lca.tour_list) {
        roots[node] = lca.parent[node] < 0 ? 1 : roots[lca.parent[node]];
        roots[node] = tree.update(roots[node], A[node], segment_change(weights[A[node]]));
    }

    for (int q = 0; q < Q; q++) {
        int u, v, L, R;
        IO::read_int(u, v, L, R);
        u--; v--; L--;
        int u_root = roots[u], v_root = roots[v];
        int anc = lca.get_lca(u, v);
        u_root = tree.update(u_root, A[anc], segment_change(weights[A[anc]]));

        int answer = tree.find_last_subarray_paired({u_root, v_root}, [&](const segment &a, const segment &b) {
            return a.hash == b.hash;
        }, N, L);

        IO::write_int(answer >= R ? -1 : answer + 1, '\n');
        tree.undo_updates(u_root);
    }
}