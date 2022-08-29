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

template<typename T>
struct fenwick_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    T tree_sum = T();
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = T();
        tree.assign(tree_n + 1, T());
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = T();

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
        T sum = T();

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
        if (sum < T())
            return -1;

        int prefix = 0;

        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

template<typename T>
struct sum_pair {
    T x = 0, y = 0;

    sum_pair() {}

    sum_pair(T _x, T _y) : x(_x), y(_y) {}

    sum_pair& operator+=(const sum_pair &other) { x += other.x; y += other.y; return *this; }
    sum_pair& operator-=(const sum_pair &other) { x -= other.x; y -= other.y; return *this; }
    sum_pair operator+(const sum_pair &other) const { return sum_pair(*this) += other; }
    sum_pair operator-(const sum_pair &other) const { return sum_pair(*this) -= other; }
};

template<typename T>
struct range_add_range_sum_tree {
    int tree_n = 0;
    fenwick_tree<sum_pair<T>> tree;

    range_add_range_sum_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.init(tree_n);
    }

    // O(n) initialization of the range_add_range_sum_tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        vector<sum_pair<T>> diffs(tree_n);

        for (int i = 0; i < tree_n; i++) {
            diffs[i].x = initial[i] - (i > 0 ? initial[i - 1] : 0);
            diffs[i].y = i * diffs[i].x;
        }

        tree.build(diffs);
    }

    // Adds change to all indices in the range [start, end).
    void update(int start, int end, const T &change) {
        assert(start <= end);

        if (start < tree_n)
            tree.update(max(start, 0), sum_pair<T>(change, start * change));

        if (end < tree_n)
            tree.update(max(end, 0), sum_pair<T>(-change, -end * change));
    }

    T query(int count) const {
        sum_pair<T> result = tree.query(count);
        return count * result.x - result.y;
    }

    // Queries the value at `index`.
    T query(int start, int end) const {
        return query(end) - query(start);
    }
};

range_add_range_sum_tree<int64_t> sum_tree;

// Note: value_t must be able to handle sums of elements / sums of updates, not just individual elements.
using value_t = int64_t;

struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (4-8 bytes per object).
    // SENTINEL is also conveniently the maximum possible value, which is a no-op for to_min.
    static const value_t SENTINEL = numeric_limits<value_t>::max();

    // Note that to_set goes first, then to_min.
    value_t to_set, to_min;

    segment_change(value_t _to_set = SENTINEL, value_t _to_min = SENTINEL)
        : to_set(_to_set), to_min(_to_min) {}

    bool has_set() const { return to_set != SENTINEL; }
    bool has_min() const { return to_min != SENTINEL; }

    bool has_change() const {
        return has_set() || has_min();
    }

    // Return the combined result of applying this segment_change followed by `other`.
    segment_change combine(const segment_change &other) const {
        if (other.has_set())
            return other;

        return segment_change(to_set, min(to_min, other.to_min));
    }
};

struct segment {
    value_t maximum, second_max;
    int max_count, second_count;

    value_t minimum, sum;

    segment(value_t value = 0, int count = 0) {
        maximum = count != 0 ? value : numeric_limits<value_t>::lowest();
        max_count = count;
        second_max = numeric_limits<value_t>::lowest();
        second_count = 0;

        minimum = count != 0 ? value : numeric_limits<value_t>::max();
        sum = value_t(value) * count;
    }

    bool empty() const {
        return max_count == 0;
    }

    bool apply(int length, const segment_change &change, bool pushed) {
        if (change.has_set()) {
            maximum = change.to_set;
            max_count = length;
            second_max = numeric_limits<value_t>::lowest();
            second_count = 0;

            minimum = change.to_set;
            sum = value_t(change.to_set) * length;
        }

        if (change.has_min() && change.to_min < maximum) {
            if (second_count != 0 && change.to_min <= second_max)
                return false;

            // Update the sum_tree only if this is the original update and not a push_down.
            if (!pushed)
                sum_tree.update(int(change.to_min), int(maximum), -max_count);

            sum += value_t(change.to_min - maximum) * max_count;
            maximum = change.to_min;
            minimum = min(minimum, change.to_min);
        }

        return true;
    }

    void join(const segment &other) {
        if (empty()) {
            *this = other;
            return;
        } else if (other.empty()) {
            return;
        }

        auto update_second_max = [&](value_t cand_max, int cand_count) {
            if (cand_max > second_max) {
                second_max = cand_max;
                second_count = cand_count;
            } else if (cand_max == second_max) {
                second_count += cand_count;
            }
        };

        if (maximum == other.maximum) {
            max_count += other.max_count;
            update_second_max(other.second_max, other.second_count);
        } else if (maximum > other.maximum) {
            update_second_max(other.maximum, other.max_count);
        } else {
            second_max = maximum;
            second_count = max_count;
            update_second_max(other.second_max, other.second_count);
            maximum = other.maximum;
            max_count = other.max_count;
        }

        minimum = min(minimum, other.minimum);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree_beats {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree_beats(int n = -1) {
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

    bool apply_and_combine(int position, int length, const segment_change &change, bool pushed) {
        if (tree[position].apply(length, change, pushed)) {
            if (position < tree_n)
                changes[position] = changes[position].combine(change);

            return true;
        }

        return false;
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            bool success = true;
            success &= apply_and_combine(2 * position, length / 2, changes[position], true);
            success &= apply_and_combine(2 * position + 1, length / 2, changes[position], true);
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
            return apply_and_combine(position, length, change, false);
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

    // Finds the last subarray starting at `first` that satisifes `should_join` via binary search in O(log n).
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
    seg_tree_beats tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(i + 1, 1);

    tree.build(initial);
    sum_tree.init(N);
    sum_tree.build(vector<int>(N, 1));

    for (int q = 0; q < Q; q++) {
        int p, L, R;
        cin >> p >> L >> R;
        L--;

        if (p == 1) {
            tree.update(0, L + 1, segment_change(segment_change::SENTINEL, L));
            tree.update(L, L + 1, segment_change(R));
            sum_tree.update(L, R, 1);
        } else if (p == 2) {
            cout << sum_tree.query(L, R) << '\n';
        } else {
            assert(false);
        }
    }
}