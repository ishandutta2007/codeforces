#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Note: value_t must be able to handle sums of elements / sums of updates, not just individual elements.
using value_t = int64_t;

struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    // SENTINEL is also conveniently the minimum possible value, which is a no-op for to_max.
    static const value_t SENTINEL = numeric_limits<value_t>::lowest();

    // Note that to_set goes first, then to_max, and then to_add.
    // TODO: check if these values can overflow int.
    value_t to_set, to_max, to_add;

    // TODO: make sure the default constructor is the identity segment_change.
    segment_change(value_t _to_set = SENTINEL, value_t _to_max = SENTINEL, value_t _to_add = 0)
        : to_set(_to_set), to_max(_to_max), to_add(_to_add) {}

    bool has_set() const { return to_set != SENTINEL; }
    bool has_max() const { return to_max != SENTINEL; }

    void reset() {
        to_set = to_max = SENTINEL;
        to_add = 0;
    }

    bool has_change() const {
        return has_set() || has_max() || to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    // TODO: make sure to check for sentinel values.
    segment_change combine(const segment_change &other) const {
        if (other.has_set())
            return other;

        segment_change combined = *this;

        // to_set, to_max, to_add, other.to_max, other.to_add ->
        // to_set, max(to_max, other.to_max - to_add), to_add + other.to_add
        if (other.has_max())
            combined.to_max = max(to_max, other.to_max - to_add);

        combined.to_add += other.to_add;
        return combined;
    }
};

struct segment {
    // TODO: check if these values can overflow int.
    value_t minimum, second_min;
    int min_count, second_count;

    value_t maximum, sum;

    // TODO: make sure the default constructor is the identity segment.
    segment(value_t value = 0, int count = 0) {
        minimum = count != 0 ? value : numeric_limits<value_t>::max();
        min_count = count;
        second_min = numeric_limits<value_t>::max();
        second_count = 0;

        maximum = count != 0 ? value : numeric_limits<value_t>::lowest();
        sum = value_t(value) * count;
    }

    bool empty() const {
        return min_count == 0;
    }

    bool apply(int length, const segment_change &change) {
        if (change.has_set()) {
            minimum = change.to_set;
            min_count = length;
            second_min = numeric_limits<value_t>::max();
            second_count = 0;

            maximum = change.to_set;
            sum = value_t(change.to_set) * length;
        }

        if (change.has_max() && change.to_max > minimum) {
            if (second_count != 0 && change.to_max >= second_min)
                return false;

            sum += value_t(change.to_max - minimum) * min_count;
            minimum = change.to_max;
            maximum = max(maximum, change.to_max);
        }

        if (change.to_add != 0) {
            minimum += change.to_add;
            if (second_count != 0) second_min += change.to_add;
            maximum += change.to_add;
            sum += value_t(change.to_add) * length;
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

        auto &&update_second_min = [&](value_t cand_min, int cand_count) {
            if (cand_min < second_min) {
                second_min = cand_min;
                second_count = cand_count;
            } else if (cand_min == second_min) {
                second_count += cand_count;
            }
        };

        if (minimum == other.minimum) {
            min_count += other.min_count;
            update_second_min(other.second_min, other.second_count);
        } else if (minimum < other.minimum) {
            update_second_min(other.minimum, other.min_count);
        } else {
            second_min = minimum;
            second_count = min_count;
            update_second_min(other.second_min, other.second_count);
            minimum = other.minimum;
            min_count = other.min_count;
        }

        maximum = max(maximum, other.maximum);
        sum += other.sum;
    }

    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree_beats {
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
            changes[position].reset();
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

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            return apply_and_combine(position, length, change);
        });
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> (31 - __builtin_clz(i)));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join);

    template<typename T_bool>
    int find_last_subarray(int n, int start, T_bool &&should_join);
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int INF = int(1e9) + 5;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    map<int, int> seen;
    vector<int> next_occur(N, -1);

    for (int i = N - 1; i >= 0; i--) {
        if (seen.count(A[i]))
            next_occur[i] = seen[A[i]];

        seen[A[i]] = i;
    }

    vector<int> dp(N + 1, INF);
    vector<int> min_around(N + 1, INF);
    seg_tree_beats tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(-INF, 1);

    tree.build(initial);

    for (int i = N - 1; i >= 0; i--) {
        if (next_occur[i] >= 0) {
            min_around[next_occur[i]] = min<int64_t>(min_around[next_occur[i]], -tree.query(next_occur[i], next_occur[i] + 1).maximum);
            dp[i] = min_around[next_occur[i]];
            min_around[i] = min_around[next_occur[i]];
            min_around[i] = min<int64_t>(min_around[i], -tree.query(next_occur[i], next_occur[i] + 1).maximum);
            tree.update(i + 1, next_occur[i], segment_change(segment_change::SENTINEL, -next_occur[i]));
        }

        if (next_occur[i] >= 0 && next_occur[next_occur[i]] >= 0 && next_occur[next_occur[next_occur[i]]] >= 0)
            dp[i] = min(dp[i], next_occur[next_occur[next_occur[i]]]);
    }

    for (int i = N - 1; i >= 0; i--)
        dp[i] = min(dp[i], dp[i + 1]);

    vector<int> sequence;
    int current = 0;

    while (current < N) {
        if (dp[current] == dp[current + 1]) {
            current++;
            continue;
        }

        if (dp[current] > N)
            break;

        int end = dp[current];
        dbg(current, end);
        sequence.push_back(A[current]);
        sequence.push_back(A[end]);
        sequence.push_back(A[current]);
        sequence.push_back(A[end]);
        current = end + 1;
    }

    cout << sequence.size() << '\n';
    output_vector(sequence);
}