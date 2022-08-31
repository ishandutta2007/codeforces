#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int node;
    long long weight;

    edge() {}

    edge(int _node, long long _weight) : node(_node), weight(_weight) {}
};

int N, K;
vector<vector<edge>> adj;
vector<long long> dp[2];

void dfs(int node, int parent) {
    // Erase edge to parent.
    for (edge &e : adj[node])
        if (e.node == parent) {
            swap(e, adj[node].back());
            adj[node].pop_back();
            break;
        }

    vector<long long> differences;
    long long sum = 0;

    for (edge &e : adj[node]) {
        dfs(e.node, node);
        sum += dp[0][e.node];
        differences.push_back(e.weight + dp[1][e.node] - dp[0][e.node]);
    }

    sort(differences.rbegin(), differences.rend());
    dp[0][node] = dp[1][node] = sum;

    for (int i = 0; i < (int) differences.size(); i++) {
        sum += differences[i];

        if (i < K)
            dp[0][node] = max(dp[0][node], sum);

        if (i < K - 1)
            dp[1][node] = max(dp[1][node], sum);
    }
}

void solve_case() {
    cin >> N >> K;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dp[0].assign(N, -1);
    dp[1].assign(N, -1);
    dfs(0, -1);
    cout << dp[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}