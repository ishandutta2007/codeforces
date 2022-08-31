#include <cassert>
#include <limits>
#include <iostream>
#include <vector>
using namespace std;

struct segment_change {
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int sum;

    segment() : sum(0) {}

    void apply(int start, int end, const segment_change &change) {
        sum += change.to_add;
    }

    void join(const segment &other) {
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct persistent_seg_tree {
    static const bool LAZY_PROPAGATION = false;

    struct node {
        segment seg;
        segment_change change;
        int left, right;
    };

    int tree_n;
    vector<node> tree;

    persistent_seg_tree(int n = 0, int reserve_size = 0) {
        tree_n = 0;

        if (n > 0)
            init(n, reserve_size);
    }

    void init(int n, int reserve_size = 0) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        if (reserve_size > 0)
            tree.reserve(reserve_size);

        tree.assign(2 * tree_n, node());

        for (int i = 1; i < tree_n; i++) {
            tree[i].left = 2 * i;
            tree[i].right = 2 * i + 1;
        }
    }

    int& left(int position) { return tree[position].left; }
    int& right(int position) { return tree[position].right; }

    int make_copy(int position) {
        assert(0 <= position && position < (int) tree.size());
        tree.push_back(tree[position]);
        return tree.size() - 1;
    }

    void push_down(int position, int start, int mid, int end) {
        tree[left(position)].seg.apply(start, mid, tree[position].change);
        tree[right(position)].seg.apply(mid, end, tree[position].change);
        tree[left(position)].change = tree[left(position)].change.combine(tree[position].change);
        tree[right(position)].change = tree[right(position)].change.combine(tree[position].change);
        tree[position].change.reset();
    }

    void query_tree(int position, int start, int end, int a, int b, segment &answer, const segment_change &propagate) {
        if (a <= start && end <= b) {
            segment seg = tree[position].seg;
            seg.apply(start, end, propagate);
            answer.join(seg);
            return;
        }

        if (left(position) == -1 || right(position) == -1)
            return;

        int mid = (start + end) / 2;
        segment_change next_propagate = tree[position].change.combine(propagate);
        if (a < mid) query_tree(left(position), start, mid, a, b, answer, next_propagate);
        if (b > mid) query_tree(right(position), mid, end, a, b, answer, next_propagate);
    }

    segment query(int root, int a, int b) {
        segment answer;
        query_tree(root, 0, tree_n, a, b, answer, segment_change());
        return answer;
    }

    // Directly assigning `left(position) = make_copy(left(position))` results in segmentation faults, because the
    // address for `left(position)` can be computed before calling `make_copy`, which may reallocate `tree`.
    void set_left(int position, int result) { left(position) = result; }
    void set_right(int position, int result) { right(position) = result; }

    int update_tree(int position, int start, int end, int a, int b, const segment_change &change, bool needs_copy) {
        if (needs_copy)
            position = make_copy(position);

        if (a <= start && end <= b) {
            tree[position].seg.apply(start, end, change);
            tree[position].change = tree[position].change.combine(change);
            return position;
        }

        if (left(position) == -1 || right(position) == -1)
            return position;

        int mid = (start + end) / 2;

        if (LAZY_PROPAGATION) {
            set_left(position, make_copy(left(position)));
            set_right(position, make_copy(right(position)));
            push_down(position, start, mid, end);
            needs_copy = false;
        }

        if (a < mid) set_left(position, update_tree(left(position), start, mid, a, b, change, needs_copy));
        if (b > mid) set_right(position, update_tree(right(position), mid, end, a, b, change, needs_copy));
        tree[position].seg.join(tree[left(position)].seg, tree[right(position)].seg);
        return position;
    }

    int update(int root, int a, int b, const segment_change &change) {
        assert(LAZY_PROPAGATION || b - a <= 1);
        return update_tree(root, 0, tree_n, a, b, change, true);
    }
};


const int A_MAX = 1e5 + 5;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<int> army(N);
    vector<int> type_index(N);
    vector<vector<int>> type_list(A_MAX);

    for (int i = 0; i < N; i++) {
        scanf("%d", &army[i]);
        type_index[i] = type_list[army[i]].size();
        type_list[army[i]].push_back(i);
    }

    persistent_seg_tree tree(N);
    int root = 1;

    for (int i = 0; i < N; i++)
        if (type_index[i] < K)
            root = tree.update(root, i, i + 1, {+1});

    vector<int> tree_roots(N);

    for (int i = 0; i < N; i++) {
        tree_roots[i] = root;
        root = tree.update(root, i, i + 1, {-1});

        if (type_index[i] + K < (int) type_list[army[i]].size()) {
            int next = type_list[army[i]][type_index[i] + K];
            root = tree.update(root, next, next + 1, {+1});
        }
    }

    int Q;
    scanf("%d", &Q);
    int answer = 0;

    for (int q = 0; q < Q; q++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int left = (x + answer) % N;
        int right = (y + answer) % N;

        if (left > right)
            swap(left, right);

        answer = tree.query(tree_roots[left], 0, right + 1).sum;
        printf("%d\n", answer);
    }
}