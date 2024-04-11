#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using T_tree = long long;
const T_tree T_INF = numeric_limits<T_tree>::max() / 2;

struct segment_change {
    T_tree to_add;

    segment_change(T_tree _to_add = 0) : to_add(_to_add) {}
};

struct segment {
    T_tree min_prefix, sum;

    segment(T_tree _min_prefix = T_INF, T_tree _sum = 0) : min_prefix(_min_prefix), sum(_sum) {}

    void apply(const segment_change &change) {
        min_prefix += change.to_add;
        sum += change.to_add;
    }

    void join(const segment &other) {
        min_prefix = min(min_prefix, sum + other.min_prefix);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct min_prefix_sum_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    min_prefix_sum_tree(int n = -1) {
        if (n >= 0)
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

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment_change &change) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position].apply(change);
        join_up(position);
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};

struct add_min_seg_tree {
    // Build a `min_prefix_sum_tree` on the consecutive differences of the array.
    min_prefix_sum_tree tree;

    add_min_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree.init(n);
    }

    void build(const vector<T_tree> &initial) {
        vector<segment> segment_initial(initial.size());
        T_tree previous = 0;

        for (int i = 0; i < (int) initial.size(); i++) {
            T_tree value = initial[i] - previous;
            previous = initial[i];
            segment_initial[i] = segment(value, value);
        }

        tree.build(segment_initial);
    }

    T_tree query(int a, int b) const {
        return tree.query(0, a).sum + tree.query(a, b).min_prefix;
    }

    T_tree query_full() const {
        return tree.tree[1].min_prefix;
    }

    void update(int a, int b, segment_change change) {
        if (a < tree.tree_n)
            tree.update(a, change);

        if (b < tree.tree_n) {
            change.to_add *= -1;
            tree.update(b, change);
        }
    }

    void set_value(int index, T_tree value) {
        T_tree current = query(index, index + 1);
        update(index, index + 1, segment_change(value - current));
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N), A(N);
    vector<int> location(N + 1, -1);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        location[P[i]] = i;
    }

    for (int i = 0; i < N; i++)
        cin >> A[i];

    add_min_seg_tree tree(N - 1);
    tree.build(vector<T_tree>(N - 1, 0));

    for (int i = 0; i < N; i++)
        tree.update(i, N - 1, segment_change(A[i]));

    T_tree best = tree.query(0, N - 1);

    for (int p = 1; p <= N; p++) {
        int loc = location[p];
        tree.update(loc, N - 1, segment_change(-A[loc]));
        tree.update(0, loc, segment_change(A[loc]));
        best = min(best, tree.query_full());
    }

    cout << best << '\n';
}