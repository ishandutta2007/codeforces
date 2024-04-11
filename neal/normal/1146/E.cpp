#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct segment_change {
    // Note that to_set goes first, and flip goes after.
    bool flip;
    int to_set;

    segment_change(bool _flip = false, int _to_set = -1) : flip(_flip), to_set(_to_set) {}

    void reset() {
        flip = false;
        to_set = -1;
    }

    bool has_change() const {
        return flip || to_set >= 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        if (other.to_set >= 0)
            return other;

        return segment_change(flip ^ other.flip, to_set);
    }
};

struct segment {
    int on, off;

    segment(int _on = 0, int _off = 0) : on(_on), off(_off) {}

    void apply(int length, const segment_change &change) {
        if (change.to_set >= 0) {
            if (change.to_set) {
                on = length;
                off = 0;
            } else {
                off = length;
                on = 0;
            }
        }

        if (change.flip)
            swap(on, off);
    }

    void join(const segment &other) {
        on += other.on;
        off += other.off;
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

    // O(n) initialization of our tree.
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


seg_tree tree;

void flip(int a, int b) {
    tree.update(a, b, segment_change(true));
}

void set_all(int a, int b, bool value) {
    tree.update(a, b, segment_change(false, value));
}

struct number {
    int value, index, original;

    number(int _value = -1) : value(_value) {}

    bool operator<(const number &other) const {
        return value < other.value;
    }
};

int N, Q;
vector<number> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A[i].original = x;
        A[i].value = abs(x);
        A[i].index = i;
    }

    sort(A.begin(), A.end());
    vector<segment> initial;

    for (int i = 0; i < N; i++)
        if (A[i].original >= 0)
            initial.emplace_back(1, 0);
        else
            initial.emplace_back(0, 1);

    tree.init(N);
    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        char op;
        int x;
        cin >> op >> x;

        if (x >= 0) {
            if (op == '<') {
                int index = lower_bound(A.begin(), A.end(), x) - A.begin();
                flip(0, index);
                set_all(index, N, true);
            } else if (op == '>') {
                int index = lower_bound(A.begin(), A.end(), x + 1) - A.begin();
                set_all(index, N, false);
            } else {
                assert(false);
            }
        } else {
            x = abs(x);

            if (op == '<') {
                int index = lower_bound(A.begin(), A.end(), x + 1) - A.begin();
                set_all(index, N, true);
            } else if (op == '>') {
                int index = lower_bound(A.begin(), A.end(), x) - A.begin();
                flip(0, index);
                set_all(index, N, false);
            } else {
                assert(false);
            }
        }
    }

    vector<int> answers(N);

    for (int i = 0; i < N; i++)
        answers[A[i].index] = A[i].value * (tree.query(i, i + 1).on ? +1 : -1);

    for (int i = 0; i < N; i++)
        cout << answers[i] << (i < N - 1 ? ' ' : '\n');
}