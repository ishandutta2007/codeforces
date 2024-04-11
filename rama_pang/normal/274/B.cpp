#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

int n;
vector<int> adj[200005];
int V[200005];
lint dp[200005][2]; // (neg, pos)

void dfs(int n, int p) {
  dp[n][0] = dp[n][1] = 0;
  lint mn = 0, mx = 0;
  for (auto i : adj[n]) if (i != p) {
    dfs(i, n);
    mn = max(mn, dp[i][0]);
    mx = max(mx, dp[i][1]);
  }
  if (V[n] >= 0) {
    dp[n][0] = max(mn, mx - V[n]);
    dp[n][1] = max(mx, V[n] + mn);    
  }
  if (V[n] <= 0) {
    V[n] *= -1;
    dp[n][1] = max(mx, mn - V[n]);
    dp[n][0] = max(mn, V[n] + mx);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  } 
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }

  dfs(1, 0);

  cout << (dp[1][0] + dp[1][1]) << "\n";
  return 0;
}