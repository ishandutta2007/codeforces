#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


struct log_lca {
    int n = 0;
    vector<int> parent, depth;
    vector<vector<int>> adj;
    vector<vector<int>> ancestor;

    log_lca(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        parent.resize(n);
        depth.resize(n);
        adj.assign(n, {});
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        parent[node] = par;

        for (int neighbor : adj[node])
            if (neighbor != par)
                dfs(neighbor, node);
    }

    void build() {
        dfs(0, -1);
        ancestor.assign(largest_bit(n) + 1, vector<int>(n));
        ancestor[0] = parent;

        for (int k = 0; k < largest_bit(n); k++)
            for (int i = 0; i < n; i++)
                ancestor[k + 1][i] = ancestor[k][i] < 0 ? -1 : ancestor[k][ancestor[k][i]];
    }

    int get_kth_ancestor(int v, int k) const {
        for (int i = 0; 1 << i <= k; i++)
            if (k & 1 << i) {
                v = ancestor[i][v];

                if (v < 0)
                    break;
            }

        return v;
    }

    int get_lca(int a, int b) const {
        if (depth[a] > depth[b])
            swap(a, b);

        b = get_kth_ancestor(b, depth[b] - depth[a]);

        if (a == b)
            return a;

        assert(a != b && depth[a] == depth[b]);

        for (int k = largest_bit(depth[a]); k >= 0; k--)
            if (ancestor[k][a] != ancestor[k][b]) {
                a = ancestor[k][a];
                b = ancestor[k][b];
            }

        assert(parent[a] == parent[b]);
        return parent[a];
    }

    bool is_ancestor(int a, int b) const {
        return depth[a] <= depth[b] && get_kth_ancestor(b, depth[b] - depth[a]) == a;
    }

    bool on_path(int x, int a, int b) const {
        int anc = get_lca(a, b);
        return is_ancestor(anc, x) && (is_ancestor(x, a) || is_ancestor(x, b));
    }

    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
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
};

log_lca lca;


struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    static const int SENTINEL = numeric_limits<int>::min();

    int to_set;

    segment_change(int _to_set = SENTINEL) : to_set(_to_set) {}

    bool has_set() const {
        return to_set != SENTINEL;
    }
};

struct segment {
    static const int EMPTY = -1;
    static const int INVALID = -2;

    int nodes[2];

    // TODO: make sure the default constructor is the identity segment.
    segment(int node = EMPTY) : nodes{node, node} {}

    void apply(const segment_change &change) {
        if (change.has_set())
            nodes[0] = nodes[1] = change.to_set;
    }

    void join(const segment &other) {
        if (nodes[0] == INVALID || other.nodes[0] == INVALID) {
            nodes[0] = nodes[1] = INVALID;
            return;
        }

        if (other.nodes[0] == EMPTY)
            return;

        if (nodes[0] == EMPTY) {
            *this = other;
            return;
        }

        int all[4] = {nodes[0], nodes[1], other.nodes[0], other.nodes[1]};
        int dists[4][4] = {0};
        int most = -1, a = -1, b = -1;

        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++) {
                dists[i][j] = dists[j][i] = lca.get_dist(all[i], all[j]);

                if (dists[i][j] > most) {
                    most = dists[i][j];
                    a = i;
                    b = j;
                }
            }

        for (int i = 0; i < 4; i++)
            if (i != a && i != b && dists[a][i] + dists[b][i] != dists[a][b]) {
                nodes[0] = nodes[1] = INVALID;
                return;
            }

        nodes[0] = all[a];
        nodes[1] = all[b];
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct iterative_seg_tree {
    // Note: POWER_OF_TWO_MODE is only necessary in order to binary search the tree.
    static const bool POWER_OF_TWO_MODE = true;
    static const bool NEEDS_JOIN = true;

    int tree_n = 0;
    vector<segment> tree;

    iterative_seg_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    static segment right_half[];

    segment query(int a, int b) {
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = tree[--b];
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(right_half[i]);

        return answer;
    }

    void update(int position, const segment_change &change) {
        position += tree_n;
        tree[position].apply(change);

        for (position /= 2; position > 0; position /= 2)
            if (NEEDS_JOIN)
                tree[position].join(tree[2 * position], tree[2 * position + 1]);
            else
                tree[position].apply(change);
    }

    void update(int a, int b, const segment_change &change) {
        if (a == b)
            return;

        assert(b - a == 1);
        update(a, change);
    }

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join) {
        assert(POWER_OF_TWO_MODE);
        segment current;

        // Check edge cases.
        if (!should_join(current, current))
            return -1;

        if (should_join(current, tree[1]))
            return n;

        int position = 1;
        int start = 0, end = tree_n;

        while (position < tree_n) {
            int mid = (start + end) / 2;

            if (should_join(current, tree[2 * position])) {
                current.join(tree[2 * position]);
                position = 2 * position + 1;
                start = mid;
            } else {
                position = 2 * position;
                end = mid;
            }
        }

        assert(position == tree_n + start);
        assert(0 <= start && start < n);
        assert(end - start == 1);
        return start;
    }
};

segment iterative_seg_tree::right_half[100];


int main() {
    int N;
    scanf("%d", &N);
    lca.init(N);
    vector<int> P(N);

    for (int &p : P)
        scanf("%d", &p);

    for (int i = 1; i < N; i++) {
        int parent;
        scanf("%d", &parent);
        parent--;
        lca.add_edge(parent, i);
    }

    lca.build();
    iterative_seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[P[i]] = segment(i);

    tree.build(initial);
    int Q;
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int type;
        scanf("%d", &type);

        if (type == 2) {
            printf("%d\n", tree.find_last_prefix(N, [&](const segment &first, const segment &second) {
                segment together;
                together.join(first, second);
                return together.nodes[0] != segment::INVALID;
            }));
        } else {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            swap(P[a], P[b]);
            tree.update(P[a], segment_change(a));
            tree.update(P[b], segment_change(b));
        }
    }
}