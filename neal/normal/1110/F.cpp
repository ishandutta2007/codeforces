#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_min[0][i] = values[i];

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = min(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return min(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};

const int INF = 1e9 + 5;
const long long LL_INF = (long long) 2e18 + 5;

struct edge {
    int node, weight;

    edge(int _node = -INF, int _weight = -INF) : node(_node), weight(_weight) {}
};

struct query {
    int L, R;
    int index;
    long long answer;

    query(int _L = -INF, int _R = -INF, int _index = -INF, long long _answer = LL_INF)
        : L(_L), R(_R), index(_index), answer(_answer) {}
};

int N, Q;
vector<int> original_degree;
vector<vector<edge>> adj;
vector<vector<query>> queries;

bool is_leaf(int v) {
    return original_degree[v] == 1;
}

void add_edge(int a, int b, int weight) {
    assert(a != b);
    adj[a].emplace_back(b, weight);
    adj[b].emplace_back(a, weight);
    original_degree[a]++;
    original_degree[b]++;
}

void erase_edge(int from, int to) {
    for (edge &e : adj[from])
        if (e.node == to) {
            swap(e, adj[from].back());
            adj[from].pop_back();
            return;
        }

    assert(false);
}

vector<int> depth;
vector<long long> dist;
vector<int> subtree_size;
vector<int> node_list;

int dfs(int node, int parent = -INF) {
    if (parent < 0) {
        node_list.clear();
        dist[node] = 0;
    }

    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    node_list.push_back(node);
    subtree_size[node] = 1;

    for (edge &e : adj[node])
        if (e.node != parent) {
            dist[e.node] = dist[node] + e.weight;
            subtree_size[node] += dfs(e.node, node);
        }

    return subtree_size[node];
}

int centroid(int root) {
    int n = dfs(root);
    bool found;

    // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
    do {
        found = false;

        for (edge &e : adj[root])
            if (subtree_size[e.node] < subtree_size[root] && 2 * subtree_size[e.node] >= n) {
                root = e.node;
                found = true;
                break;
            }
    } while (found);

    return root;
}

void process_queries(int root) {
    dfs(root);
    vector<int> leaf_list;

    for (int node : node_list)
        if (is_leaf(node))
            leaf_list.push_back(node);

    sort(leaf_list.begin(), leaf_list.end());
    vector<long long> leaf_dist;

    for (int leaf : leaf_list)
        leaf_dist.push_back(dist[leaf]);

    RMQ<long long> rmq(leaf_dist);

    for (int node : node_list)
        for (query &q : queries[node]) {
            int start = lower_bound(leaf_list.begin(), leaf_list.end(), q.L) - leaf_list.begin();
            int end = lower_bound(leaf_list.begin(), leaf_list.end(), q.R) - leaf_list.begin();

            if (start < end)
                q.answer = min(q.answer, dist[node] + rmq.query(start, end));
        }
}

void solve(int root) {
    root = centroid(root);
    process_queries(root);

    for (edge &e : adj[root]) {
        // Erase the edge from e.node back to root.
        erase_edge(e.node, root);
    }

    // Recurse after solving root, so that edge erasures don't cause incorrect results.
    for (edge &e : adj[root])
        solve(e.node);
}

int main() {
    scanf("%d %d", &N, &Q);
    original_degree.assign(N, 0);
    adj.assign(N, {});
    queries.assign(N, {});
    depth.resize(N);
    dist.resize(N);
    subtree_size.resize(N);

    for (int i = 1; i < N; i++) {
        int p, weight;
        scanf("%d %d", &p, &weight);
        p--;
        add_edge(p, i, weight);
    }

    for (int i = 0; i < Q; i++) {
        int V, L, R;
        scanf("%d %d %d", &V, &L, &R);
        V--; L--;
        queries[V].emplace_back(L, R, i);
    }

    solve(0);
    vector<long long> answers(Q);

    for (int i = 0; i < N; i++)
        for (query &q : queries[i])
            answers[q.index] = q.answer;

    for (int i = 0; i < Q; i++)
        printf("%lld\n", answers[i]);
}