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
    int maximum;

    segment(int _maximum = 0) : maximum(_maximum) {}

    void apply(int, const segment_change &change) {
        maximum += change.to_add;
    }

    void join(const segment &other) {
        maximum = max(maximum, other.maximum);
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

int N, K;
vector<int> A;
vector<int> parent;
vector<vector<int>> children;
vector<int> depth;
vector<int> tour_start, tour_end;

void dfs(int node) {
    static int tour = 0;
    depth[node] = parent[node] < 0 ? 1 : depth[parent[node]] + 1;
    tour_start[node] = tour++;

    for (int child : children[node])
        dfs(child);

    tour_end[node] = tour;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    A.resize(N);
    parent.assign(N, -1);
    children.assign(N, {});
    depth.assign(N, -1);
    tour_start.assign(N, -1);
    tour_end.assign(N, -1);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<pair<int, int>> stack;

    for (int i = N - 1; i >= 0; i--) {
        while (!stack.empty() && A[i] >= stack.back().first)
            stack.pop_back();

        if (!stack.empty()) {
            parent[i] = stack.back().second;
            children[parent[i]].push_back(i);
        }

        stack.emplace_back(A[i], i);
    }

    for (int i = N - 1; i >= 0; i--)
        if (parent[i] < 0)
            dfs(i);

    seg_tree tree(N);
    vector<int> answers(N - K + 1, 0);

    for (int i = N - 1; i >= N - K; i--)
        tree.update(tour_start[i], tour_start[i] + 1, segment_change(depth[i]));

    answers[N - K] = tree.query(0, N).maximum;

    for (int i = N - K - 1; i >= 0; i--) {
        tree.update(tour_start[i], tour_start[i] + 1, segment_change(depth[i]));
        tree.update(tour_start[i + K], tour_end[i + K], segment_change(-1));
        answers[i] = tree.query(0, N).maximum;
    }

    for (int i = 0; i <= N - K; i++)
        cout << answers[i] << (i < N - K ? ' ' : '\n');
}