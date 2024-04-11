#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <vector>
using namespace std;

struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    static const int SENTINEL = numeric_limits<int>::min();

    // Note that to_set goes first, and to_add goes after.
    long long to_add;
    int to_set;

    segment_change(long long _to_add = 0, int _to_set = SENTINEL) : to_add(_to_add), to_set(_to_set) {}

    bool has_set() const {
        return to_set != SENTINEL;
    }

    void reset() {
        to_add = 0;
        to_set = SENTINEL;
    }

    bool has_change() const {
        return has_set() || to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        if (other.has_set())
            return other;

        return segment_change(to_add + other.to_add, to_set);
    }
};

struct segment {
    long long sum;
    long long weighted_sum;
    int length;

    segment(long long _sum = 0, long long _weighted_sum = 0, int _length = 1) : sum(_sum), weighted_sum(_weighted_sum), length(_length) {}

    void apply(int _length, const segment_change &change) {
        assert(length == _length);

        if (change.has_set()) {
            sum = (long long) length * change.to_set;
            weighted_sum = (long long) length * (length + 1) / 2 * change.to_set;
        }

        if (change.to_add != 0) {
            sum += (long long) length * change.to_add;
            weighted_sum += (long long) length * (length + 1) / 2 * change.to_add;
        }
    }

    void join(const segment &other) {
        weighted_sum = weighted_sum + (long long) other.length * sum + other.weighted_sum;
        sum += other.sum;
        length += other.length;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = 0) {
        if (n > 0)
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

    pair<int, int> right_half[32];

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

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join);

    template<typename T_bool>
    int find_last_subarray(int n, int start, T_bool &&should_join);
};


template<typename T_bool>
int seg_tree::find_last_prefix(int n, T_bool &&should_join) {
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
        push_down(position, end - start);

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

template<typename T_bool>
int seg_tree::find_last_subarray(int n, int start, T_bool &&should_join) {
    assert(0 <= start && start <= n);
    segment current;

    // Check edge cases.
    if (!should_join(current, current))
        return -1;

    if (start >= n)
        return start;

    push_all(start, start + 1);
    int position = tree_n + start;

    if (!should_join(current, tree[position]))
        return start;

    current.join(tree[position]);

    // Search up the tree.
    while (position > 1) {
        if (position % 2 == 0) {
            position++;

            if (should_join(current, tree[position]))
                current.join(tree[position]);
            else
                break;
        }

        position /= 2;
    }

    if (position == 1)
        return n;

    int length = tree_n >> (31 - __builtin_clz(position));

    // Search down the tree.
    while (position < tree_n) {
        push_down(position, length);

        if (should_join(current, tree[2 * position])) {
            current.join(tree[2 * position]);
            position = 2 * position + 1;
        } else {
            position = 2 * position;
        }

        length /= 2;
    }

    return position - tree_n;
}


int N, Q;
vector<int> A, K;
vector<long long> K_prefix, K_weighted;

long long weighted_K_sum(int start, int end) {
    return K_weighted[end] - K_weighted[start] - (end - start) * K_prefix[start];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.assign(N + 1, 0);
    K.assign(N, 0);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i < N; i++)
        cin >> K[i];

    K_prefix.assign(N + 1, 0);
    K_weighted.assign(N + 1, 0);

    for (int i = 0; i < N; i++) {
        K_prefix[i + 1] = K_prefix[i] + K[i];
        K_weighted[i + 1] = K_weighted[i] + K_prefix[i + 1];
    }

    seg_tree tree(N);
    vector<segment> initial;

    for (int i = 0; i < N; i++) {
        long long value = A[i + 1] - A[i] - K[i];
        initial.emplace_back(value, value);
    }

    tree.build(initial);
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;

        if (type == '+') {
            int i, x;
            cin >> i >> x;
            tree.update(i - 1, i, segment_change(x));

            int end = tree.find_last_subarray(N, i, [&](const segment &a, const segment &b) {
                return a.sum + b.sum <= x;
            });

            long long sum = tree.query(i, end).sum;
            tree.update(i, end, segment_change(0, 0));

            if (end < N)
                tree.update(end, end + 1, segment_change(sum - x));
        } else if (type == 's') {
            int L, R;
            cin >> L >> R;

            long long count = R - L + 1;
            long long a = tree.query(0, L).sum + K_prefix[L];
            long long answer = a * count + tree.query(L, R).weighted_sum + weighted_K_sum(L, R);
            cout << answer << '\n';
        } else {
            assert(false);
        }
    }
}