#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int node, index;

    edge() {}

    edge(int _node, int _index) : node(_node), index(_index) {}
};

int N, M;
vector<pair<int, int>> edges;
vector<vector<edge>> adj;
vector<int> depth;
vector<int> highest;
vector<bool> visited;
vector<bool> is_bridge;
vector<bool> oriented;

void dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    highest[node] = depth[node];

    for (edge &e : adj[node]) {
        if (e.node == parent)
            continue;

        if (visited[e.node]) {
            // e.node is our tree ancestor, so it's a candidate for highest.
            highest[node] = min(highest[node], depth[e.node]);
        } else {
            dfs(e.node, node);

            if (highest[e.node] == depth[e.node])
                is_bridge[e.index] = true;

            // e.node is part of our subtree.
            highest[node] = min(highest[node], highest[e.node]);
        }
    }
}

int scc_dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    int size = 1;

    for (edge &e : adj[node]) {
        if (e.node == parent)
            continue;

        if (!visited[e.node] && !is_bridge[e.index])
            size += scc_dfs(e.node, node);
    }

    return size;
}

void orient_edge(int index, int u, int v) {
    assert(!oriented[index]);
    oriented[index] = true;

    if (edges[index].first != u)
        swap(edges[index].first, edges[index].second);

    assert(edges[index].first == u && edges[index].second == v);
}

void orient_dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    depth[node] = parent < 0 ? 0 : depth[parent] + 1;

    for (edge &e : adj[node]) {
        if (e.node == parent)
            continue;

        if (is_bridge[e.index])
            orient_edge(e.index, e.node, node);
        else if (!visited[e.node] || depth[e.node] < depth[node])
            orient_edge(e.index, node, e.node);

        if (!visited[e.node])
            orient_dfs(e.node, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});
    edges.resize(M);
    depth.resize(N);
    highest.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[i] = {u, v};
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    visited.assign(N, false);
    is_bridge.assign(M, false);
    dfs(0, -1);

    visited.assign(N, false);
    int largest = 0, largest_index = -1;

    for (int i = 0; i < N; i++)
        if (!visited[i]) {
            int size = scc_dfs(i, -1);

            if (size > largest) {
                largest = size;
                largest_index = i;
            }
        }

    visited.assign(N, false);
    oriented.assign(M, false);
    orient_dfs(largest_index, -1);

    cout << largest << '\n';

    for (int i = 0; i < M; i++)
        cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
}