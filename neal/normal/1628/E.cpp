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

template<typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }

    void build(const vector<T> &values) {
        n = int(values.size());
        int levels = highest_bit(n) + 1;
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
        int level = highest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

// https://codeforces.com/blog/entry/71568?#comment-559304
// Performs O(n log n) preprocessing to enable querying the maximum edge weight on any path in a tree in O(1) time.
// Note: to find the particular edge that is the maximum, the best way is to input weights that are either
// 1) a pair `{weight, edge index}` or 2) a single value `weight * N + edge index`.
// In particular, RMQ alone cannot be used to find the particular edge, because this could result in wrong answers when
// there are multiple edges with equal weights.
template<typename T_weight>
struct line_tree {
    struct line_tree_union_find {
        vector<int> parent;
        vector<int> size;
        vector<int> first, last;

        line_tree_union_find(int n = 0) {
            parent.resize(n);
            size.assign(n, 1);
            first.resize(n);
            last.resize(n);

            for (int i = 0; i < n; i++)
                parent[i] = first[i] = last[i] = i;
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
            pair<int, int> result = {last[x], first[y]};
            last[x] = last[y];
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
        edges = {};
    }

    void add_edge(int a, int b, T_weight weight) {
        edges.emplace_back(a, b, weight);
    }

    void build() {
        assert(int(edges.size()) == max(n - 1, 0));
        sort(edges.begin(), edges.end());
        line_tree_union_find UF(n);
        vector<int> next_node(n, -1);
        vector<bool> has_prev(n, false);
        vector<T_weight> next_weight(n, numeric_limits<T_weight>::lowest());

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
            return -1;

        a = line_index[a];
        b = line_index[b];

        if (a > b)
            swap(a, b);

        return rmq.query_value(a, b);
    }
};

line_tree<int> line;


struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (4-8 bytes per object).
    static const int SENTINEL = numeric_limits<int>::lowest();

    int to_set;

    segment_change(int _to_set = SENTINEL) : to_set(_to_set) {}

    bool has_set() const {
        return to_set != SENTINEL;
    }

    bool has_change() const {
        return has_set();
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return other.has_set() ? other : *this;
    }
};

pair<int, int> combine_max(int max_between0, int any0, int max_between1, int any1) {
    int max_between = max(max_between0, max_between1);

    if (min(any0, any1) >= 0)
        max_between = max(max_between, line.query_path_max(any0, any1));

    int any = max(any0, any1);
    return {max_between, any};
}

struct segment {
    int max_between, any;
    int max_between_all, any_all;

    segment(int _max_between = -1, int _any = -1, int _max_between_all = -1, int _any_all = -1)
        : max_between(_max_between), any(_any), max_between_all(_max_between_all), any_all(_any_all) {}

    void apply(int, const segment_change &change) {
        if (change.has_set()) {
            if (change.to_set == 0) {
                max_between = -1;
                any = -1;
            } else {
                max_between = max_between_all;
                any = any_all;
            }
        }
    }

    void join(const segment &other) {
        pair<int, int> result = combine_max(max_between, any, other.max_between, other.any);
        pair<int, int> result_all = combine_max(max_between_all, any_all, other.max_between_all, other.any_all);
        max_between = result.first;
        any = result.second;
        max_between_all = result_all.first;
        any_all = result_all.second;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }

    int evaluate(int x) const {
        int ans = max_between;

        if (any >= 0)
            ans = max(ans, line.query_path_max(x, any));

        return ans;
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
        if (position < tree_n) changes[position] = changes[position].combine(change);
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

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    line.init(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        line.add_edge(u, v, weight);
    }

    line.build();
    seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(-1, -1, -1, i);

    tree.build(initial);

    for (int q = 0; q < Q ; q++) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int L, R;
            cin >> L >> R;
            L--;
            tree.update(L, R, segment_change(type == 1));
        } else if (type == 3) {
            int x;
            cin >> x;
            x--;
            cout << tree.query_full().evaluate(x) << '\n';
        } else {
            assert(false);
        }
    }
}