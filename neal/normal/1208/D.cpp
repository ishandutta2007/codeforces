#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


const long long LL_INF = (long long) 2e18 + 5;

struct segment_change {
    long long to_add;

    segment_change(long long _to_add = 0) : to_add(_to_add) {}

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
    long long minimum;
    int min_index;

    segment(long long _minimum = LL_INF, int _min_index = -1) : minimum(_minimum), min_index(_min_index) {}

    void apply(int, const segment_change &change) {
        minimum += change.to_add;
    }

    void join(const segment &other) {
        if (other.minimum <= minimum) {
            minimum = other.minimum;
            min_index = other.min_index;
        }
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

    template<typename T_range_op>
    void process_range(int position, int start, int end, int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a <= start && end <= b) {
            range_op(position, end - start);
            return;
        }

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
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(1, 0, tree_n, a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);
            if (position < tree_n) changes[position] = changes[position].combine(change);
        });
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> S(N);

    for (long long &s : S)
        cin >> s;

    vector<segment> initial;

    for (int i = 0; i < N; i++)
        initial.emplace_back(S[i], i);

    seg_tree tree(N);
    tree.build(initial);
    vector<int> P(N, 0);

    for (int number = 1; number <= N; number++) {
        segment result = tree.query(0, N);
        int index = result.min_index;
        P[index] = number;
        tree.update(index + 1, N, segment_change(-number));
        tree.update(index, index + 1, segment_change(LL_INF));
    }

    for (int i = 0; i < N; i++)
        cout << P[i] << (i < N - 1 ? ' ' : '\n');
}