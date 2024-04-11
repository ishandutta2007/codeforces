#include <algorithm>
#include <array>
#include <bitset>
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

struct segment_change {
    array<int, 2> sum_change;
    bool toggle;

    segment_change(array<int, 2> _sum_change = {0, 0}, bool _toggle = false)
        : sum_change(_sum_change), toggle(_toggle) {}

    bool has_change() const {
        return sum_change != array<int, 2>{0, 0} || toggle;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change({sum_change[0] + other.sum_change[0], sum_change[1] + other.sum_change[1]},
                              toggle ^ other.toggle);
    }
};

struct segment {
    array<int, 2> max_sum_needs;  // [0] = parity of tree root, [1] = opposite parity
    array<int64_t, 2> sum_up_edges;  // [0] = inactive, [1] = active

    segment(array<int, 2> sum_needs = {0, 0}, int up_edge = 0)
        : max_sum_needs(sum_needs), sum_up_edges({0, up_edge}) {}

    void apply(int, const segment_change &change) {
        for (int x = 0; x < 2; x++)
            max_sum_needs[x] += change.sum_change[x];

        if (change.toggle)
            swap(sum_up_edges[0], sum_up_edges[1]);
    }

    void join(const segment &other) {
        for (int x = 0; x < 2; x++) {
            max_sum_needs[x] = max(max_sum_needs[x], other.max_sum_needs[x]);
            sum_up_edges[x] += other.sum_up_edges[x];
        }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

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
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);

        if (position < tree_n)
            changes[position] = changes[position].combine(change);
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position] = segment_change();
        }
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
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

    segment query_full() const {
        return tree[1];
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            apply_and_combine(position, length, change);
        });
    }

    void update_single(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        tree[position] = seg;

        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    // Finds the end of the last subarray starting at `first` satisfying `should_join` via binary search in O(log n).
    template<typename T_bool>
    int find_last_subarray(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        // Check the degenerate case.
        if (!should_join(current, current))
            return first - 1;

        return y_combinator([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};


struct subtree_heavy_light {
    int n = 0;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;

    vector<int> tour_start, tour_end;
    vector<int> chain_root;
    seg_tree full_tree;

    subtree_heavy_light() {}

    subtree_heavy_light(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        tour_start.resize(n);
        tour_end.resize(n);
        chain_root.resize(n);
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

    int tour;

    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            chain_dfs(child, heavy_child);
            heavy_child = false;
        }

        tour_end[node] = tour;
    }

    void build(const segment &initial) {
        tour = 0;
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                chain_dfs(i, false);
            }

        full_tree.init(n);
        full_tree.build(vector<segment>(n, initial));
    }

    void update_subtree(int v, const segment_change &change) {
        full_tree.update(tour_start[v] + (vertex_mode ? 0 : 1), tour_end[v], change);
    }

    segment query_subtree(int v) {
        return full_tree.query(tour_start[v] + (vertex_mode ? 0 : 1), tour_end[v]);
    }

    void update_single(int v, const segment &seg) {
        full_tree.update_single(tour_start[v] + (vertex_mode ? 0 : 1), seg);
    }

    template<typename T_tree_op>
    int process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(full_tree, tour_start[root], tour_start[v] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        op(full_tree, tour_start[u] + (vertex_mode ? 0 : 1), tour_start[v] + 1);
        return u;
    }

    int get_lca(int u, int v) {
        return process_path(u, v, [&](seg_tree &, int, int){});
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


int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    subtree_heavy_light HLD(N, true);
    vector<array<int, 2>> edges(N - 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        HLD.add_edge(u, v);
        edges[i] = {u, v};
    }

    HLD.build(segment());
    vector<int> up_edge(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int u = edges[i][0], v = edges[i][1];
        int deeper = HLD.depth[u] > HLD.depth[v] ? u : v;
        up_edge[deeper] = i + 1;
    }

    auto activate = [&](int v) -> void {
        int depth = HLD.depth[v];
        HLD.update_single(v, segment({0, 0}, up_edge[v]));
        array<int, 2> sum_change = depth % 2 ? array<int, 2>{+1, -1} : array<int, 2>{-1, +1};

        if (HLD.parent[v] >= 0)
            HLD.update_path(HLD.parent[v], 0, segment_change(sum_change, true));
    };

    activate(0);

    auto query = [&]() -> int64_t {
        segment seg = HLD.query_subtree(0);

        if (max(seg.max_sum_needs[0], seg.max_sum_needs[1]) >= 2)
            return 0;

        if (HLD.query_path(0, 0).max_sum_needs[0] != 1)
            return 0;

        return seg.sum_up_edges[1];
    };

    auto print_edges = [&]() -> void {
        if (query() == 0) {
            cout << 0 << endl;
            return;
        }

        vector<int> answer;

        for (int v = 1; v < N; v++)
            if (HLD.query_path(v, v).sum_up_edges[1] > 0)
                answer.push_back(up_edge[v]);

        sort(answer.begin(), answer.end());
        cout << answer.size();

        for (int e : answer)
            cout << ' ' << e;

        cout << endl;
    };

    int type;

    while (cin >> type) {
        if (type == 0 || type == 3) {
            return 0;
        } else if (type == 1) {
            int v;
            cin >> v;
            v--;
            activate(v);
            cout << query() << endl;
            continue;
        } else if (type == 2) {
            print_edges();
        } else {
            assert(false);
        }
    }
}