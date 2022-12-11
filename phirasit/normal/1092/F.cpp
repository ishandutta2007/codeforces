#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

vector<int> adj[N];
int A[N];
int pass[N];

long long cost[N];
long long sum[N];

void dfs1(int u, int p) {
    cost[u] = 0;
    sum[u] = A[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);

        cost[u] += cost[v] + sum[v];
        sum[u] += sum[v];
    }
}

void dfs2(int u, int p) {
    if (p != -1) {
        cost[u] += cost[p] - (cost[u] + sum[u]) + sum[p] - sum[u];
        sum[u] = sum[p];
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs2(v, u);
    }
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> A[i];

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1);


    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, cost[i]);
    }

    cout << ans << endl;

    return 0;
}