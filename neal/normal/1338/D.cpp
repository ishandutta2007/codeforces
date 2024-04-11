#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> adj;

// `dp_on[node]` = the best path going through `node` where `node` is selected.
// `dp_off[node]` = the best path going through `node` where `node` is not selected.
vector<int> dp_on, dp_off;

int either(int node) {
    return max(dp_on[node], dp_off[node]);
}

int dfs(int node, int parent) {
    int extra = max((int) adj[node].size() - 2, 0);
    dp_on[node] = 1;
    dp_off[node] = extra;
    int best = either(node);

    for (int neighbor : adj[node]) {
        if (neighbor == parent)
            continue;

        best = max(best, dfs(neighbor, node));
        best = max(best, dp_on[node] + dp_off[neighbor]);
        best = max(best, dp_off[node] + either(neighbor));
        dp_on[node] = max(dp_on[node], dp_off[neighbor] + 1);
        dp_off[node] = max(dp_off[node], either(neighbor) + extra);
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp_on.resize(N);
    dp_off.resize(N);
    cout << dfs(0, -1) << '\n';
}