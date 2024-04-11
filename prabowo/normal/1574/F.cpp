#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

int n, m, k;

int indeg[N];
vector<int> adj[N];

int dp[N];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    int c;
    scanf("%d", &c);
    int lst;
    scanf("%d", &lst); --lst;
    for (int j = 1; j < c; ++j) {
      int u;
      scanf("%d", &u); --u;
      adj[lst].push_back(u);
      lst = u;
    }
  }

  for (int i = 0; i < k; ++i) {
    if (adj[i].size() == 0) continue;
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    for (int j : adj[i]) ++indeg[j];
  }

  vector<bool> vis(k);
  vector<int> cnt(k + 1);
  for (int i = 0; i < k; ++i) {
    if (indeg[i] > 0) continue;
    for (int j = i, len = 1; ; ++len) {
      if (vis[j] || indeg[j] > 1 || adj[j].size() > 1) break;
      vis[j] = true;
      if (adj[j].empty()) {
        ++cnt[len];
        break;
      }
      j = adj[j][0];
    }
  }

  vector<int> chains;
  for (int i = 1; i <= k; ++i) {
    if (cnt[i] > 0) chains.push_back(i);
  }

  dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int c : chains) {
      if (c <= i) dp[i] = (dp[i] + 1LL * cnt[c] * dp[i - c]) % MOD;
    }
  }
  printf("%d\n", dp[m]);

  return 0;
}