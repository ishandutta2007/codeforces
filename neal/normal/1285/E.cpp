#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct segment_change {
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int minimum, left, right, drop_count;

    segment(int _minimum = 0, int _left = 0, int _right = 0, int _drop_count = 0)
        : minimum(_minimum), left(_left), right(_right), drop_count(_drop_count) {}

    void apply(int, const segment_change &change) {
        minimum += change.to_add;
        left += change.to_add;
        right += change.to_add;
    }

    int get_goal_count(int goal) const {
        return minimum == goal ? drop_count : 0;
    }

    void join(const segment &other) {
        if (minimum < other.minimum) {
            right = other.right;
        } else if (minimum > other.minimum) {
            minimum = other.minimum;
            drop_count = other.drop_count;

            if (other.left == minimum)
                drop_count++;

            right = other.right;
        } else {
            drop_count += other.drop_count;

            if (right > minimum && other.left == minimum)
                drop_count++;

            right = other.right;
        }
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


struct interval {
    long long start, end;

    bool operator<(const interval &other) const {
        return start < other.start;
    }
};

void run_case() {
    int N;
    cin >> N;
    vector<interval> intervals(N);

    for (interval &inter : intervals) {
        cin >> inter.start >> inter.end;
        inter.start *= 2;
        inter.end *= 2;

        if (inter.start == inter.end)
            inter.end++;
    }

    vector<long long> sorted;

    for (interval &inter : intervals) {
        sorted.push_back(inter.start);
        sorted.push_back(inter.end);
    }

    sort(sorted.begin(), sorted.end());
    sorted.resize(unique(sorted.begin(), sorted.end()) - sorted.begin());
    int S = sorted.size();

    for (interval &inter : intervals) {
        inter.start = lower_bound(sorted.begin(), sorted.end(), inter.start) - sorted.begin();
        inter.end = lower_bound(sorted.begin(), sorted.end(), inter.end) - sorted.begin();
    }

    seg_tree tree(S + 1);

    for (interval &inter : intervals)
        tree.update(inter.start, inter.end, segment_change(+1));

    int best = 0;

    for (interval &inter : intervals) {
        tree.update(inter.start, inter.end, segment_change(-1));
        best = max(best, tree.tree[1].get_goal_count(0));
        tree.update(inter.start, inter.end, segment_change(+1));
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}