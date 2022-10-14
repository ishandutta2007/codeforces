#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 998244353;
const lint MAXN = 300005;

int n;
vector<int> adj[MAXN];
lint dp[MAXN][2][2]; // dp[n][does parent edge exist?][is parent in independent set?]

void dfs(int n, int p) {
  for (auto &i : adj[n]) if (i != p) dfs(i, n);
  
  // current node is in independent set

  { // n is in set
    dp[n][0][0] = 1; // n is in set, parent edge doesn't exist, then one child must have an edge
    dp[n][1][0] = 1; // n is in set, parent edge exist and parent not in set, child can have edge or not
    lint all_not_take = 1;
    
    for (auto &i : adj[n]) if (i != p) {
      dp[n][0][0] = dp[n][0][0] * (dp[i][1][1] + dp[i][0][0]) % MOD; // can choose not to take
      dp[n][1][0] = dp[n][1][0] * (dp[i][1][1] + dp[i][0][0]) % MOD;
      all_not_take = all_not_take * dp[i][0][0] % MOD;
    }
    dp[n][0][0] = (dp[n][0][0] + MOD - all_not_take) % MOD; // can not have an empty set (not take edge child)
  }

  // current node is not in independent set
  {
    lint res = 1;
    for (auto &i : adj[n]) if (i != p) {
      res = res * (dp[i][0][0] + dp[i][1][0]) % MOD; // not take edge
    }

    dp[n][0][0] += res;
    dp[n][1][0] += res;
    dp[n][1][1] += res;
    dp[n][0][0] %= MOD;
    dp[n][1][0] %= MOD;
    dp[n][1][1] %= MOD;
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

  dfs(1, 0);
  lint ans = dp[1][0][0] - 1;
  ans %= MOD;
  ans += MOD;
  ans %= MOD;

  cout << ans << "\n";
  return 0;
}