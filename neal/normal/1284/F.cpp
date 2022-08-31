#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    static const int SENTINEL = numeric_limits<int>::min();

    int to_set;

    segment_change(int _to_set = SENTINEL) : to_set(_to_set) {}

    bool has_set() const {
        return to_set != SENTINEL;
    }

    void reset() {
        to_set = SENTINEL;
    }

    bool has_change() const {
        return has_set();
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return other.has_set() ? other : *this;
    }
};

struct segment {
    int first;

    segment(int _first = -1) : first(_first) {}

    void apply(int, const segment_change &change) {
        if (change.has_set())
            first = change.to_set;
    }

    void join(const segment &other) {
        if (first < 0)
            first = other.first;
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


static segment v_half[32];

struct ordered_path_heavy_light {
    int n = 0;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;

    vector<int> chain_root, chain_size;
    vector<seg_tree> chain_up_tree, chain_down_tree;

    ordered_path_heavy_light() {}

    ordered_path_heavy_light(int _n, bool _vertex_mode) {
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
        chain_up_tree.assign(n, {});
        chain_down_tree.assign(n, {});
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
                chain_up_tree[i].init(chain_size[i]);
                chain_down_tree[i].init(chain_size[i]);
                vector<segment> initial_segs(chain_size[i], initial);
                chain_up_tree[i].build(initial_segs);
                chain_down_tree[i].build(initial_segs);
            }
    }

    segment _query_up_tree(int root, int start, int end) {
        int size = chain_size[root];
        return chain_up_tree[root].query(size - end, size - start);
    }

    void _update_up_tree(int root, int start, int end, const segment_change &change) {
        int size = chain_size[root];
        chain_up_tree[root].update(size - end, size - start, change);
    }

    void _update_both_trees(int root, int start, int end, const segment_change &change) {
        _update_up_tree(root, start, end, change);
        chain_down_tree[root].update(start, end, change);
    }

    segment query_path(int u, int v) {
        segment u_half;
        int v_size = 0;

        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            bool pull_u = depth[chain_root[u]] > depth[chain_root[v]];
            int pull_node = pull_u ? u : v;
            int root = chain_root[pull_node];
            int end = depth[pull_node] - depth[root] + 1;

            if (pull_u) {
                u_half.join(_query_up_tree(root, 0, end));
                u = parent[root];
            } else {
                v_half[v_size++] = chain_down_tree[root].query(0, end);
                v = parent[root];
            }
        }

        // One of u and v is an ancestor of the other.
        bool pull_u = depth[u] > depth[v];
        int pull_node = pull_u ? u : v;
        int ancestor = pull_u ? v : u;
        int root = chain_root[pull_node];
        int start = depth[ancestor] - depth[root] + (vertex_mode ? 0 : 1);
        int end = depth[pull_node] - depth[root] + 1;

        if (pull_u)
            u_half.join(_query_up_tree(root, start, end));
        else
            v_half[v_size++] = chain_down_tree[root].query(start, end);

        for (int i = v_size - 1; i >= 0; i--)
            u_half.join(v_half[i]);

        return u_half;
    }

    void update_path(int u, int v, const segment_change &change) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            _update_both_trees(root, 0, depth[v] - depth[root] + 1, change);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        int root = chain_root[v];
        _update_both_trees(root, depth[u] - depth[root] + (vertex_mode ? 0 : 1), depth[v] - depth[root] + 1, change);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    ordered_path_heavy_light HLD(N, false);
    vector<pair<int, int>> T1(N - 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        HLD.add_edge(a, b);
        T1[i] = {a, b};
    }

    HLD.build(segment());

    for (int e = 0; e < N - 1; e++)
        HLD.update_path(T1[e].first, T1[e].second, segment_change(e));

    vector<vector<int>> adj(N);
    vector<int> degree(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++; degree[b]++;
    }

    queue<int> leaves;

    for (int i = 0; i < N; i++)
        if (degree[i] == 1)
            leaves.push(i);

    cout << N - 1 << '\n';

    while (!leaves.empty()) {
        int leaf = leaves.front(); leaves.pop();

        if (degree[leaf] == 0)
            break;

        int parent = -1;

        for (int neighbor : adj[leaf])
            if (degree[neighbor] != 0)
                parent = neighbor;

        assert(parent >= 0);
        int first_edge = HLD.query_path(leaf, parent).first;
        assert(first_edge >= 0);
        int x = T1[first_edge].first, y = T1[first_edge].second;
        HLD.update_path(x, y, segment_change(-1));

        degree[leaf]--;
        degree[parent]--;

        if (degree[parent] == 1)
            leaves.push(parent);

        cout << x + 1 << ' ' << y + 1 << ' ' << leaf + 1 << ' ' << parent + 1 << '\n';
    }
}