#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int n;
vector<int> adj[N];
int dp[2][N];
int res = 0;
 
void dfs(int u, int p) {
    dp[0][u] = 0;
    dp[1][u] = 1;
    pair<int, int> maxVal(0, 0);
    pair<int, int> maxZero(0, 0);
    int numChild = (int)adj[u].size() - (u != 1);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[0][u] = max(dp[0][u], numChild - 1 + max(dp[0][v], dp[1][v]));
        dp[1][u] = max(dp[1][u], 1 + dp[0][v]);
        int now = max(dp[0][v], dp[1][v]);
        if (maxVal.second < now) swap(maxVal.second, now);
        if (maxVal.first < maxVal.second) swap(maxVal.first, maxVal.second);

        if (maxZero.second < dp[0][v]) maxZero.second = dp[0][v];
        if (maxZero.first < maxZero.second) swap(maxZero.first, maxZero.second);
    }
    if (adj[u].size() >= 2) {
        res = max(res, (int)adj[u].size() - 2 + maxVal.first + maxVal.second);
        res = max(res, maxZero.first + maxZero.second + 1);
    }
    res = max(res, dp[0][u]);
    res = max(res, dp[1][u]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    res = 0;
    dfs(1, 0);
    cout << res << endl;
    return 0;
}