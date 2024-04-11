#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct segment_change {
    int value;

    segment_change(int _value = INF) : value(_value) {}

    void reset() {
        value = INF;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(min(value, other.value));
    }
};

struct segment {
    int minimum;

    segment() : minimum(INF) {}

    void apply(int start, int end, const segment_change &change) {
        minimum = min(minimum, change.value);
    }

    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
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


int N, R;
vector<int> depth;
vector<vector<int>> levels;
int euler_time;
vector<int> euler_start, euler_end;
vector<vector<int>> adj;

void dfs(int node, int parent) {
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;
    levels[depth[node]].push_back(node);
    euler_start[node] = euler_time++;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);

    euler_end[node] = euler_time;
}

int main() {
    scanf("%d %d", &N, &R);
    R--;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++)
        scanf("%d", &numbers[i]);

    adj.assign(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth.resize(N);
    levels.resize(N);
    euler_start.resize(N);
    euler_end.resize(N);
    euler_time = 0;
    dfs(R, -1);
    assert(euler_time == N);

    persistent_seg_tree tree(N);
    vector<int> tree_roots(N);

    for (int d = 0; d < N; d++) {
        tree_roots[d] = d > 0 ? tree_roots[d - 1] : 1;

        for (int node : levels[d])
            tree_roots[d] = tree.update(tree_roots[d], euler_start[node], euler_start[node] + 1, {numbers[node]});
    }

    int M;
    scanf("%d", &M);
    int answer = 0;

    for (int i = 0; i < M; i++) {
        int p, q;
        scanf("%d %d", &p, &q);

        int x = (p + answer) % N;
        int k = (q + answer) % N;
        int d = min(depth[x] + k, N - 1);
        answer = tree.query(tree_roots[d], euler_start[x], euler_end[x]).minimum;
        printf("%d\n", answer);
    }
}