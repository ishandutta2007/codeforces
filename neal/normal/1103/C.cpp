#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M, K, P;
vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;
vector<bool> visited;
vector<int> leaves;

void dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;
    depth[node] = par < 0 ? 1 : depth[par] + 1;
    bool leaf = true;

    for (int neighbor : adj[node])
        if (!visited[neighbor]) {
            dfs(neighbor, node);
            leaf = false;
        }

    if (leaf)
        leaves.push_back(node);
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    adj.assign(N, {});
    depth.resize(N);
    parent.resize(N);
    P = (N + K - 1) / K;

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(N, false);
    dfs(0, -1);

    int deepest = max_element(depth.begin(), depth.end()) - depth.begin();

    if (depth[deepest] >= P) {
        puts("PATH");
        printf("%d\n", depth[deepest]);

        for (int node = deepest; node >= 0; node = parent[node])
            printf("%d%c", node + 1, parent[node] >= 0 ? ' ' : '\n');

        return 0;
    }

    assert((int) leaves.size() >= K);
    puts("CYCLES");

    for (int k = 0; k < K; k++) {
        int leaf = leaves[k];
        int a = -1, b = -1;

        for (int neighbor : adj[leaf])
            if (neighbor != parent[leaf]) {
                if (a == -1)
                    a = neighbor;
                else
                    b = neighbor;
            }

        int top = -1, bottom = -1;

        if ((depth[leaf] - depth[a]) % 3 != 2) {
            top = a;
            bottom = leaf;
        } else if ((depth[leaf] - depth[b]) % 3 != 2) {
            top = b;
            bottom = leaf;
        } else {
            top = a;
            bottom = b;

            if (depth[top] > depth[bottom])
                swap(top, bottom);
        }

        vector<int> cycle;

        if (bottom != leaf)
            cycle.push_back(leaf);

        for (int node = bottom; node != parent[top]; node = parent[node])
            cycle.push_back(node);

        assert(cycle.size() % 3 != 0);
        printf("%d\n", (int) cycle.size());

        for (int i = 0; i < (int) cycle.size(); i++)
            printf("%d%c", cycle[i] + 1, i < (int) cycle.size() - 1 ? ' ' : '\n');
    }
}