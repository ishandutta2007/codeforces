#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
struct fenwick_tree {
    int tree_n;
    vector<T> tree;

    fenwick_tree(int n = 0) : tree_n(n) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
    int find_last_prefix(T sum) {
        if (sum < 0)
            return -1;

        int log = 32 - __builtin_clz(tree_n);
        int prefix = 0;

        for (int k = log - 1; k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


struct operation {
    int node, d, x;
};

int N, M;
vector<vector<int>> adj, levels;
vector<int> depth;
vector<int> tour_start, tour_end;
int tour;

vector<operation> ops;

void dfs(int node, int parent) {
    if (parent == -1)
        tour = 0;

    tour_start[node] = tour++;
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;
    levels[depth[node]].push_back(node);

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);

    tour_end[node] = tour;
}

int get_bottom(const operation &op) {
    return depth[op.node] + op.d;
}

bool compare_ops(const operation &op1, const operation &op2) {
    return get_bottom(op1) > get_bottom(op2);
}

int main() {
    scanf("%d", &N);
    adj.assign(N, {});
    levels.assign(N, {});
    depth.assign(N, -1);
    tour_start.assign(N, -1);
    tour_end.assign(N, -1);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    scanf("%d", &M);
    ops.resize(M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &ops[i].node, &ops[i].d, &ops[i].x);
        ops[i].node--;
    }

    sort(ops.begin(), ops.end(), compare_ops);
    int pos = 0;

    fenwick_tree<long long> tree(N + 1);
    vector<long long> answers(N, 0);

    for (int level = N - 1; level >= 0; level--) {
        while (pos < M && get_bottom(ops[pos]) >= level) {
            int node = ops[pos].node;
            int x = ops[pos].x;
            tree.update(tour_start[node], x);
            tree.update(tour_end[node], -x);
            pos++;
        }

        for (int node : levels[level])
            answers[node] = tree.query(tour_start[node] + 1);
    }

    for (int i = 0; i < N; i++)
        printf("%lld%c", answers[i], i < N - 1 ? ' ' : '\n');
}