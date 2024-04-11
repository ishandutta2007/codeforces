#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct edge {
    int node, weight;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N;
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

vector<int> parent;
vector<int> depth;
vector<int> subtree_size;

int dfs(int node, int par = -INF, long long current_weight = 0) {
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    subtree_size[node] = 1;

    for (edge &e : adj[node])
        if (e.node != par)
            subtree_size[node] += dfs(e.node, node, current_weight + e.weight);

    return subtree_size[node];
}

int get_centroid(int root) {
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


vector<int> node_value;

void assign_values(vector<int> nodes, vector<int> goal) {
    int front = 0, goal_front = 0;

    while (front < (int) nodes.size()) {
        int top = nodes[front++];
        node_value[top] = goal[goal_front++];

        for (edge &e : adj[top])
            if (e.node != parent[top])
                nodes.push_back(e.node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N, {});
    parent.resize(N);
    depth.resize(N);
    subtree_size.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        add_edge(u, v, 0);
    }

    int centroid = get_centroid(0);
    dfs(centroid);
    vector<int> side, other_side;
    int side_sum = 0;

    for (edge &e : adj[centroid])
        if (side_sum + subtree_size[e.node] <= 2 * (N - 1) / 3) {
            side.push_back(e.node);
            side_sum += subtree_size[e.node];
        } else {
            other_side.push_back(e.node);
        }

    int A = side_sum, B = N - 1 - A;
    node_value.assign(N, 0);
    vector<int> A_goal, B_goal;

    for (int i = 1; i <= A; i++)
        A_goal.push_back(i);

    for (int i = 1; i <= B; i++)
        B_goal.push_back((A + 1) * i);

    assign_values(side, A_goal);
    assign_values(other_side, B_goal);

    for (int i = 0; i < N; i++)
        if (parent[i] >= 0)
            cout << i + 1 << ' ' << parent[i] + 1 << ' ' << node_value[i] - node_value[parent[i]] << '\n';
}