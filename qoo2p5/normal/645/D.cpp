#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 123;

int n, m;
vector<pair<int, int>> g[N];
bool vis[N];
int dp[N];
int ans[N];

void dfs(int v) {
    vis[v] = true;
    dp[v] = 1;
    ans[v] = 0;
    
    for (auto &e : g[v]) {
        if (!vis[e.first]) {
            dfs(e.first);
        }
        
        if (dp[e.first] + 1 > dp[v]) {
            dp[v] = dp[e.first] + 1;
            ans[v] = max(e.second, ans[e.first]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, i});
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    
    int ind = max_element(dp, dp + n) - dp;
    if (dp[ind] != n) {
        cout << "-1\n";
    } else {
        cout << ans[ind] << "\n";
    }

    return 0;
}