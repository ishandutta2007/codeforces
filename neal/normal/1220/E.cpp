#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M, S;
vector<long long> W;
vector<vector<int>> adj;
vector<int> depth;
vector<int> highest;
vector<bool> visited;
vector<bool> subtree_has_cycle;

void dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    highest[node] = depth[node];
    subtree_has_cycle[node] = false;

    for (int &neighbor : adj[node]) {
        if (neighbor == parent)
            continue;

        if (visited[neighbor]) {
            // neighbor is our tree ancestor, so it's a candidate for highest.
            highest[node] = min(highest[node], depth[neighbor]);
        } else {
            dfs(neighbor, node);
            subtree_has_cycle[node] = subtree_has_cycle[node] || subtree_has_cycle[neighbor];
            // neighbor is part of our subtree.
            highest[node] = min(highest[node], highest[neighbor]);
        }
    }

    subtree_has_cycle[node] = subtree_has_cycle[node] || highest[node] < depth[node];
}

vector<array<long long, 2>> dp;

void score_dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;

    dp[node][0] = subtree_has_cycle[node] ? W[node] : 0;
    dp[node][1] = W[node];
    long long path_not_chosen = W[node];

    for (int &neighbor : adj[node]) {
        if (neighbor == parent)
            continue;

        if (!visited[neighbor]) {
            score_dfs(neighbor, node);
            dp[node][0] += dp[neighbor][0];
            dp[node][1] = max(dp[node][1] + dp[neighbor][0], path_not_chosen + dp[neighbor][1]);
            path_not_chosen += dp[neighbor][0];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    W.resize(N);
    adj.assign(N, {});

    for (long long &w : W)
        cin >> w;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> S;
    S--;

    depth.resize(N);
    highest.resize(N);
    subtree_has_cycle.assign(N, false);
    visited.assign(N, false);
    dfs(S, -1);

    dp.assign(N, {0, 0});
    visited.assign(N, false);
    score_dfs(S, -1);
    cout << dp[S][1] << '\n';
}