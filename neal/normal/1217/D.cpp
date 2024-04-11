#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < (int) order.size()) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<bool> color(M, false);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        color[i] = u < v;
        adj[u].push_back(v);
    }

    if ((int) topological_sort(adj).size() == N) {
        cout << 1 << '\n';

        for (int i = 0; i < M; i++)
            cout << 1 << (i < M - 1 ? ' ' : '\n');

        return 0;
    }

    cout << 2 << '\n';

    for (int i = 0; i < M; i++)
        cout << (color[i] ? 1 : 2) << (i < M - 1 ? ' ' : '\n');
}