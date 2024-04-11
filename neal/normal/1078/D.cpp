#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;


struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    static const int SENTINEL = numeric_limits<int>::min();

    int set_min, set_max;

    segment_change(int _set_min = SENTINEL, int _set_max = SENTINEL) : set_min(_set_min), set_max(_set_max) {}

    bool has_set_min() const {
        return set_min != SENTINEL;
    }

    bool has_set_max() const {
        return set_max != SENTINEL;
    }
};

struct segment {
    int minimum, maximum;

    segment(int _minimum = INF, int _maximum = -INF) : minimum(_minimum), maximum(_maximum) {}

    void apply(const segment_change &change) {
        if (change.has_set_min())
            minimum = change.set_min;

        if (change.has_set_max())
            maximum = change.set_max;
    }

    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
        maximum = max(maximum, other.maximum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct iterative_seg_tree {
    // Note: POWER_OF_TWO_MODE is only necessary in order to binary search the tree.
    static const bool POWER_OF_TWO_MODE = false;
    static const bool NEEDS_JOIN = true;

    int tree_n;
    vector<segment> tree;

    iterative_seg_tree(int n = 0) {
        tree_n = 0;

        if (n > 0)
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

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    static segment right_half[];

    segment query(int a, int b) {
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = tree[--b];
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(right_half[i]);

        return answer;
    }

    void update(int position, const segment_change &change) {
        position += tree_n;
        tree[position].apply(change);

        for (position /= 2; position > 0; position /= 2)
            if (NEEDS_JOIN)
                tree[position].join(tree[2 * position], tree[2 * position + 1]);
            else
                tree[position].apply(change);
    }

    void update(int a, int b, const segment_change &change) {
        if (a == b)
            return;

        assert(b - a == 1);
        update(a, change);
    }
};

segment iterative_seg_tree::right_half[100];


int N, LOG;
vector<int> respect;
vector<vector<int>> L, R;
vector<iterative_seg_tree> trees;

int main() {
    scanf("%d", &N);

    if (N == 1) {
        puts("0");
        return 0;
    }

    respect.resize(3 * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &respect[i]);
        respect[N + i] = respect[2 * N + i] = respect[i];
    }

    LOG = 32 - __builtin_clz(N);
    L.assign(LOG, vector<int>(3 * N, INF));
    R.assign(LOG, vector<int>(3 * N, -INF));
    trees.resize(LOG);

    for (int i = 0; i < 3 * N; i++) {
        L[0][i] = max(i - respect[i], 0);
        R[0][i] = min(i + respect[i], 3 * N - 1);
    }

    for (int k = 0; k < LOG; k++) {
        trees[k].init(3 * N);
        vector<segment> initial;

        for (int i = 0; i < 3 * N; i++)
            initial.emplace_back(L[k][i], R[k][i]);

        trees[k].build(initial);

        if (k + 1 >= LOG)
            continue;

        for (int i = 0; i < 3 * N; i++) {
            segment seg = trees[k].query(L[k][i], R[k][i] + 1);
            L[k + 1][i] = seg.minimum;
            R[k + 1][i] = seg.maximum;
        }
    }

    for (int i = 0; i < N; i++) {
        int latest = 0, left = N + i, right = N + i;

        for (int k = LOG - 1; k >= 0; k--) {
            segment seg = trees[k].query(left, right + 1);

            if (seg.maximum - seg.minimum + 1 < N) {
                latest += 1 << k;
                left = seg.minimum;
                right = seg.maximum;
            }
        }

        printf("%d%c", latest + 1, i < N - 1 ? ' ' : '\n');
    }
}