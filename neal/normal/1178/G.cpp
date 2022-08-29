// Solution to https://codeforces.com/contest/1178/problem/G
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

const int64_t INF64 = int64_t(2e18) + 5;

struct segment_change {
    int64_t add;

    segment_change(int64_t _add = 0) : add(_add) {}

    bool has_change() const {
        return add != 0;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(add + other.add);
    }
};

struct segment {
    int64_t A, B, wait;

    // wait = how long until any node within our subtree becomes out of date (its A, B pair is no longer optimal).
    segment(int64_t _A = 0, int64_t _B = -INF64, int64_t _wait = INF64) : A(_A), B(_B), wait(_wait) {}

    int64_t value() const {
        return B;
    }

    // apply returns true if we can stop here. If false, we need to continue updating down.
    bool apply(int, const segment_change &change) {
        B += A * change.add;
        wait -= change.add;
        return wait >= 0;
    }

    void join(segment other) {
        if (other.value() > value())
            swap(*this, other);

        wait = min(wait, other.wait);

        if (other.A > A)
            wait = min(wait, (value() - other.value()) / (other.A - A));
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

// kinetic_tournament tree supports a number of (A_i, B_i) pairs. We can perform the following operations:
// 1) Do B_i += A_i * x for all i in the range [L, R), where x >= 0.
// 2) Query for the maximum value of B_i for all i in the range [L, R).
// Queries take log n time, and updates take log^2 n time (and are fast in practice).
// See https://codeforces.com/blog/entry/68534?#comment-528741 for details.
struct kinetic_tournament_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    kinetic_tournament_tree(int n = -1) {
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

    bool apply_and_combine(int position, int length, const segment_change &change) {
        if (tree[position].apply(length, change)) {
            if (position < tree_n)
                changes[position] = changes[position].combine(change);

            return true;
        }

        return false;
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            bool success = true;
            success &= apply_and_combine(2 * position, length / 2, changes[position]);
            success &= apply_and_combine(2 * position + 1, length / 2, changes[position]);
            assert(success);
            changes[position] = segment_change();
        }
    }

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        // range_op returns true if we can finish here; if false, we need to continue recursing down.
        if (a <= start && end <= b && range_op(position, end - start))
            return;

        if (position >= tree_n)
            return;

        push_down(position, end - start);
        int mid = (start + end) / 2;
        if (a < mid) process_range(2 * position, start, mid, a, b, needs_join, range_op);
        if (b > mid) process_range(2 * position + 1, mid, end, a, b, needs_join, range_op);
        if (needs_join) tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(1, 0, tree_n, a, b, false, [&](int position, int) {
            answer.join(tree[position]);
            return true;
        });

        return answer;
    }

    segment query_full() const {
        return tree[1];
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            return apply_and_combine(position, length, change);
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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<int> parent(N, -1);
    vector<vector<int>> children(N);
    vector<int> A(N), B(N);
    vector<int64_t> A_sum(N, 0), B_sum(N, 0);
    vector<int> tour_start(N), tour_end(N);

    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    int tour = 0;

    y_combinator([&](auto dfs, int node) -> void {
        tour_start[node] = tour++;
        A_sum[tour_start[node]] = A[node] + (parent[node] < 0 ? 0 : A_sum[tour_start[parent[node]]]);
        B_sum[tour_start[node]] = B[node] + (parent[node] < 0 ? 0 : B_sum[tour_start[parent[node]]]);

        for (int child : children[node])
            dfs(child);

        tour_end[node] = tour;
    })(0);

    kinetic_tournament_tree tree(2 * N);
    vector<segment> initial(2 * N);

    for (int i = 0; i < N; i++) {
        initial[2 * i] = segment(-B_sum[i], A_sum[i] * -B_sum[i]);
        initial[2 * i + 1] = segment(B_sum[i], A_sum[i] * B_sum[i]);
    }

    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        int type, v, x;
        cin >> type >> v;
        v--;

        if (type == 1) {
            cin >> x;
            tree.update(2 * tour_start[v], 2 * tour_end[v], x);
        } else if (type == 2) {
            cout << (v == 0 ? tree.query_full() : tree.query(2 * tour_start[v], 2 * tour_end[v])).value() << '\n';
        } else {
            assert(false);
        }
    }
}