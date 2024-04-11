// Solution to https://codeforces.com/contest/293/problem/E
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct edge {
    int node, weight;

    edge(int _node = -INF, int _weight = 0) : node(_node), weight(_weight) {}
};

int N, D, W;
vector<vector<edge>> adj;

void add_edge(int a, int b, int w) {
    assert(a != b);
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
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
vector<int> subtree_size;
vector<pair<int, int>> weight_depth;

int dfs(int node, bool prepare_list = false, int parent = -INF, int current_weight = 0) {
    if (parent < 0)
        weight_depth.clear();

    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    subtree_size[node] = 1;

    if (prepare_list)
        weight_depth.emplace_back(current_weight, depth[node]);

    for (edge &e : adj[node])
        if (e.node != parent)
            subtree_size[node] += dfs(e.node, prepare_list, node, current_weight + e.weight);

    if (parent < 0 && prepare_list)
        sort(weight_depth.begin(), weight_depth.end());

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

int tree_n;
vector<int> tree;

void tree_update(int num, int change) {
    for (int i = num + 1; i <= tree_n; i += i & -i)
        tree[i] += change;
}

int tree_query(int num) {
    int sum = 0;

    for (int i = min(num, tree_n); i > 0; i -= i & -i)
        sum += tree[i];

    return sum;
}

long long count_pairs(int root, int depth_max, int weight_max) {
    int n = dfs(root, true);
    tree_n = n;

    for (int i = 0; i <= tree_n; i++)
        tree[i] = 0;

    long long pairs = 0;

    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j < n && weight_depth[i].first + weight_depth[j].first <= weight_max)
            tree_update(weight_depth[j++].second, +1);

        pairs += tree_query(depth_max - weight_depth[i].second + 1);

        // Don't count i paired with itself.
        if (2 * weight_depth[i].first <= weight_max && 2 * weight_depth[i].second <= depth_max)
            pairs--;
    }

    return pairs;
}

long long solve(int root) {
    root = centroid(root);

    // We will compute the crossing pairs by counting all pairs and then subtracting pairs within the same subtree.
    long long pairs = count_pairs(root, D, W);

    for (edge &e : adj[root]) {
        // Erase the edge from e.node back to root.
        erase_edge(e.node, root);
        pairs -= count_pairs(e.node, D - 2, W - 2 * e.weight);
    }

    // Recurse after solving root, so that edge erasures don't cause incorrect results.
    for (edge &e : adj[root])
        pairs += solve(e.node);

    return pairs;
}

int main() {
    scanf("%d %d %d", &N, &D, &W);
    adj.resize(N);
    depth.resize(N);
    subtree_size.resize(N);
    weight_depth.resize(N);
    tree.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int p, w;
        scanf("%d %d", &p, &w);
        p--;
        add_edge(p, i, w);
    }

    printf("%lld\n", solve(0) / 2);
}