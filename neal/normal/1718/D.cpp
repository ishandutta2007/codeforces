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

struct cartesian_node {
    // parent and children are indices of the tree. [start, end) is the range that this node is the min/max of.
    int parent = -1, children[2] = {-1, -1};
    int start, end;
};

// Use compare = less<T>() for a min heap and compare = greater<T>() for a max heap.
// When there are ties, the left value will be the parent of the right value.
template<typename T, typename Compare>
vector<cartesian_node> build_cartesian_tree(const vector<T> &A, Compare &&compare) {
    int n = int(A.size());
    vector<cartesian_node> nodes(n);
    vector<int> stack;

    auto add_edge = [&](int p, int c, int index) -> void {
        if (p >= 0) nodes[p].children[index] = c;
        if (c >= 0) nodes[c].parent = p;
    };

    for (int i = 0; i < n; i++) {
        int erased = -1;

        while (!stack.empty() && compare(A[i], A[stack.back()])) {
            nodes[stack.back()].end = i;
            erased = stack.back();
            stack.pop_back();
        }

        add_edge(stack.empty() ? -1 : stack.back(), i, 1);
        add_edge(i, erased, 0);
        nodes[i].start = nodes[i].parent + 1;
        stack.push_back(i);
    }

    while (!stack.empty()) {
        nodes[stack.back()].end = n;
        stack.pop_back();
    }

    return nodes;
}

int find_root(const vector<cartesian_node> &nodes) {
    int n = int(nodes.size());

    for (int i = 0; i < n; i++)
        if (nodes[i].parent < 0)
            return i;

    return -1;
}

using T_tree = int;
const T_tree T_INF = numeric_limits<T_tree>::max() / 2;

struct segment_change {
    T_tree to_add;

    segment_change(T_tree _to_add = 0) : to_add(_to_add) {}

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    T_tree minimum;

    segment(T_tree _minimum = T_INF) : minimum(_minimum) {}

    void apply(int, const segment_change &change) {
        minimum += change.to_add;
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

struct add_min_seg_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    add_min_seg_tree(int n = -1) {
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
        assert(0 <= a && a <= b && b <= tree_n);

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
        segment answer;

        process_range(a, b, false, [&](int position, int) -> void {
            answer.join(tree[position]);
        });

        return answer;
    }

    segment query_full() const {
        return tree[1];
    }

    void update(int a, int b, const segment_change &change) {
        process_range(a, b, true, [&](int position, int length) -> void {
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

    void set_value(int index, T_tree value) {
        assert(0 <= index && index < tree_n);
        T_tree current = query(index, index + 1).minimum;
        update(index, index + 1, segment_change(value - current));
    }

    void minimize(int index, T_tree value) {
        assert(0 <= index && index < tree_n);
        T_tree current = query(index, index + 1).minimum;

        if (value < current)
            update(index, index + 1, segment_change(value - current));
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


const int INF = int(1e9) + 5;

void run_case() {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N);

    for (auto &p : P)
        cin >> p;

    vector<int> A(N);
    int K = 0;

    for (auto &a : A) {
        cin >> a;
        K += a == 0;
    }

    int K1 = max(K - 1, 0);
    vector<int> S(K1);

    for (auto &s : S)
        cin >> s;

    sort(S.begin(), S.end());
    vector<cartesian_node> nodes = build_cartesian_tree(P, greater<int>());
    int root = find_root(nodes);
    vector<array<int, 2>> intervals(N, {0, 0});

    y_combinator([&](auto self, int node, int min_ancestor) -> int {
        int nmin_ancestor = min_ancestor;

        if (A[node] != 0)
            nmin_ancestor = min(nmin_ancestor, A[node]);

        int max_descendant = 0;

        for (int child : nodes[node].children)
            if (child >= 0)
                max_descendant = max(max_descendant, self(child, nmin_ancestor));

        intervals[node] = {max_descendant, min_ancestor};
        max_descendant = max(max_descendant, A[node]);
        return max_descendant;
    })(root, INF);

    int ans_low = 0, ans_high = INF;

    auto intersect_ans = [&](int low, int high) -> void {
        ans_low = max(ans_low, low);
        ans_high = min(ans_high, high);
    };

    // Check if the existing numbers are already invalid.
    for (int i = 0; i < N; i++)
        if (A[i] != 0 && (A[i] <= intervals[i][0] || A[i] >= intervals[i][1]))
            ans_low = ans_high = 0;

    vector<int> sorted = A;
    sorted.insert(sorted.end(), S.begin(), S.end());
    sorted.push_back(0);
    sorted.push_back(INF);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int C = int(sorted.size());

    auto compress = [&](int x) -> int {
        return int(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin());
    };

    add_min_seg_tree tree(C);
    tree.build(vector<segment>(C, 0));
    vector<vector<int>> intervals_starting_at(C);

    for (int i = 0; i < N; i++)
        if (A[i] == 0)
            intervals_starting_at[compress(intervals[i][0])].push_back(i);

    for (int left = C - 1, s_index = K1 - 1; left >= 0; left--) {
        while (s_index >= 0 && sorted[left] < S[s_index]) {
            int compressed = compress(S[s_index]);
            tree.update(compressed + 1, C, +1);
            s_index--;
        }

        for (int index : intervals_starting_at[left])
            tree.update(compress(intervals[index][1]), C, -1);

        int global_min = tree.query_full().minimum;

        if (global_min <= -2) {
            ans_low = ans_high = 0;
            break;
        }

        if (global_min == -1) {
            int earliest = tree.find_last_subarray([&](const segment &, const segment &add) -> bool {
                return add.minimum >= 0;
            }, C, left);

            assert(earliest < C);
            intersect_ans(sorted[left], sorted[earliest]);
        }
    }

    for (int q = 0; q < Q; q++) {
        int d;
        cin >> d;
        cout << (ans_low < d && d < ans_high ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}