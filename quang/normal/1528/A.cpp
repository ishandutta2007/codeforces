#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
vector<int> adj[N];
int a[2][N];
long long dp[2][N];


void dfs(int u, int p) {
  dp[0][u] = dp[1][u] = 0;
  for (int v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    for (int i = 0; i < 2; i++) {
      long long max_val = 0;
      for (int j = 0; j < 2; j++) {
        max_val = max(max_val, dp[j][v] + abs(a[i][u] - a[j][v]));
      }
      dp[i][u] += max_val;
    }
  }
  // cout << "# " << u << endl;
  // cout << dp[0][u] << ' ' << dp[1][u] << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[0][i] >> a[1][i];
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[0][1], dp[1][1]) << '\n';
  }
  return 0;
}