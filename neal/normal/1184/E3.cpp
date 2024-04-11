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

template<typename T>
struct kruskal {
    struct edge {
        int a, b;
        T weight;
        int index = -1;
        bool in_tree = false;

        edge() {}

        edge(int _a, int _b, T _weight, int _index = -1) : a(_a), b(_b), weight(_weight), index(_index) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    union_find UF;
    vector<edge> edges;
    vector<bool> original_in_tree;

    kruskal(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        UF.init(n);
        edges = {};
    }

    void add_edge(int a, int b, T weight) {
        edges.emplace_back(a, b, weight, edges.size());
        original_in_tree.push_back(false);
    }

    T solve() {
        sort(edges.begin(), edges.end());
        T total = 0;

        for (edge &e : edges)
            if (UF.unite(e.a, e.b)) {
                total += e.weight;
                e.in_tree = true;
                original_in_tree[e.index] = true;
            }

        return total;
    }
};

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        if (n > 0)
            range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query_value(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

// https://codeforces.com/blog/entry/71568?#comment-559304
// Performs O(n log n) preprocessing to enable querying the maximum edge weight on any path in a tree in O(1) time.
template<typename T_weight>
struct line_tree {
    struct line_tree_union_find {
        vector<int> parent;
        vector<int> size;
        vector<int> left, right;

        line_tree_union_find(int n = -1) {
            if (n >= 0)
                init(n);
        }

        void init(int n) {
            parent.resize(n);
            size.assign(n, 1);
            left.resize(n);
            right.resize(n);

            for (int i = 0; i < n; i++)
                parent[i] = left[i] = right[i] = i;
        }

        int find(int x) {
            return x == parent[x] ? x : parent[x] = find(parent[x]);
        }

        // Returns the two nodes that get joined in the line tree by joining these two nodes.
        pair<int, int> unite(int x, int y) {
            x = find(x);
            y = find(y);
            assert(x != y);

            if (size[x] < size[y])
                swap(x, y);

            parent[y] = x;
            size[x] += size[y];
            pair<int, int> result = {right[x], left[y]};
            right[x] = right[y];
            return result;
        }
    };

    struct edge {
        int a, b;
        T_weight weight;

        edge() {}

        edge(int _a, int _b, T_weight _weight) : a(_a), b(_b), weight(_weight) {}

        bool operator<(const edge &other) const {
            return weight < other.weight;
        }
    };

    int n = 0;
    vector<edge> edges;
    vector<int> line_index;
    RMQ<T_weight, true> rmq;

    line_tree(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        edges.clear();
    }

    void add_edge(int a, int b, T_weight weight) {
        edges.emplace_back(a, b, weight);
    }

    void build() {
        assert((int) edges.size() == max(n - 1, 0));
        sort(edges.begin(), edges.end());
        line_tree_union_find UF(n);
        vector<int> next_node(n, -1);
        vector<bool> has_prev(n, false);
        vector<T_weight> next_weight(n, numeric_limits<T_weight>::min());

        for (edge &e : edges) {
            pair<int, int> to_unite = UF.unite(e.a, e.b);
            next_node[to_unite.first] = to_unite.second;
            has_prev[to_unite.second] = true;
            next_weight[to_unite.first] = e.weight;
        }

        int start = -1;

        for (int i = 0; i < n; i++)
            if (!has_prev[i]) {
                start = i;
                break;
            }

        vector<int> line;
        vector<T_weight> line_weights;

        while (start >= 0) {
            line.push_back(start);

            if (next_node[start] >= 0)
                line_weights.push_back(next_weight[start]);

            start = next_node[start];
        }

        line_index.resize(n);

        for (int i = 0; i < n; i++)
            line_index[line[i]] = i;

        rmq.build(line_weights);
    }

    T_weight query_path_max(int a, int b) const {
        if (a == b)
            return numeric_limits<T_weight>::min();

        a = line_index[a];
        b = line_index[b];

        if (a > b)
            swap(a, b);

        return rmq.query_value(a, b);
    }
};

const int MAX_WEIGHT = 1e9;

struct segment_change {
    int min_update;

    segment_change(int _min_update = MAX_WEIGHT) : min_update(_min_update) {}

    void reset() {
        min_update = MAX_WEIGHT;
    }

    bool has_change() const {
        return min_update < MAX_WEIGHT;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(min(min_update, other.min_update));
    }
};

struct segment {
    int minimum;

    segment(int _minimum = MAX_WEIGHT) : minimum(_minimum) {}

    void apply(int, const segment_change &change) {
        minimum = min(minimum, change.min_update);
    }

    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};


struct heavy_light {
    int n = 0;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;

    vector<int> chain_root, chain_size;
    vector<seg_tree> chain_tree;

    heavy_light() {}

    heavy_light(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        chain_root.resize(n);
        chain_size.assign(n, 0);
        chain_tree.assign(n, {});
    }

    void add_edge(int a, int b) {
         adj[a].push_back(b);
         adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        if (par >= 0)
            adj[node].erase(find(adj[node].begin(), adj[node].end(), par));

        for (int &child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }

    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        chain_size[chain_root[node]]++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            chain_dfs(child, heavy_child);
            heavy_child = false;
        }
    }

    void build(const segment &initial) {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                chain_dfs(i, false);
            }

        for (int i = 0; i < n; i++)
            if (chain_root[i] == i) {
                chain_tree[i].init(chain_size[i]);
                chain_tree[i].build(vector<segment>(chain_size[i], initial));
            }
    }

    template<typename T_tree_op>
    void process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(chain_tree[root], 0, depth[v] - depth[root] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        int root = chain_root[v];
        op(chain_tree[root], depth[u] - depth[root] + (vertex_mode ? 0 : 1), depth[v] - depth[root] + 1);
    }

    segment query_path(int u, int v) {
        segment answer;

        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            answer.join(tree.query(a, b));
        });

        return answer;
    }

    void update_path(int u, int v, const segment_change &change) {
        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            tree.update(a, b, change);
        });
    }
};


struct edge {
    int a, b, weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);
    kruskal<int> mst(N);

    for (edge &e : edges) {
        cin >> e.a >> e.b >> e.weight;
        e.a--; e.b--;
        mst.add_edge(e.a, e.b, e.weight);
    }

    mst.solve();
    line_tree<int> line(N);
    heavy_light HLD(N, false);

    for (int i = 0; i < M; i++)
        if (mst.original_in_tree[i]) {
            line.add_edge(edges[i].a, edges[i].b, edges[i].weight);
            HLD.add_edge(edges[i].a, edges[i].b);
        }

    line.build();
    HLD.build(segment());

    for (int i = 0; i < M; i++)
        if (!mst.original_in_tree[i])
            HLD.update_path(edges[i].a, edges[i].b, segment_change(edges[i].weight));

    vector<int> answer(M, -1);

    for (int i = 0; i < M; i++)
        if (!mst.original_in_tree[i])
            answer[i] = line.query_path_max(edges[i].a, edges[i].b);
        else
            answer[i] = HLD.query_path(edges[i].a, edges[i].b).minimum;

    for (int i = 0; i < M; i++)
        cout << answer[i] << '\n';
}