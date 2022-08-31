#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int node, weight;
};

struct operation {
    int u, v, x;
};

int N;
vector<int> parent;
vector<int> depth;
vector<int> leaf;
vector<int> edge_need;
vector<vector<edge>> adj;
vector<operation> ops;

void erase_edge(int from, int to) {
    for (edge &e : adj[from])
        if (e.node == to) {
            swap(e, adj[from].back());
            adj[from].pop_back();
            return;
        }

    assert(false);
}

void dfs(int node, int par) {
    if (par >= 0)
        erase_edge(node, par);

    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;
    leaf[node] = node;

    for (edge &e : adj[node]) {
        edge_need[e.node] = e.weight;
        dfs(e.node, node);
        leaf[node] = leaf[e.node];
    }
}

void add_op(int u, int v, int x) {
    ops.push_back({u, v, x});

    while (u != v) {
        if (depth[u] < depth[v])
            swap(u, v);

        edge_need[u] -= x;
        u = parent[u];
    }
}

void solve(int node, int root) {
    int children = adj[node].size();

    if (node == root) {
        assert(children == 1);
        int child = adj[node].front().node;
        add_op(root, leaf[child], edge_need[child]);
    } else {
        assert(children != 1);

        for (int i = 0; i + 1 < children; i++) {
            int first = adj[node][i].node, second = adj[node][i + 1].node;
            int a = edge_need[first], b = edge_need[second];
            add_op(leaf[first], leaf[second], (a + b) / 2);
            add_op(root, leaf[first], (a - b) / 2);
            add_op(root, leaf[second], (b - a) / 2);
        }
    }

    for (edge &e : adj[node])
        solve(e.node, root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    parent.resize(N);
    depth.resize(N);
    leaf.resize(N);
    edge_need.assign(N, 0);
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    for (int i = 0; i < N; i++)
        if (adj[i].size() == 2) {
            cout << "NO" << '\n';
            return 0;
        }

    cout << "YES" << '\n';

    for (int i = 0; i < N; i++)
        if (adj[i].size() == 1) {
            dfs(i, -1);
            solve(i, i);
            break;
        }

    cout << ops.size() << '\n';

    for (operation &op : ops)
        cout << op.u + 1 << ' ' << op.v + 1 << ' ' << op.x << '\n';
}