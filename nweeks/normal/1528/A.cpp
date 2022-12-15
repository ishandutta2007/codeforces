#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
vector<pair<int, int>> seg;
vector<array<int, 2>> dp;

void dfs(int u, int p) {
  dp[u] = {0, 0};

  for (auto v : adj[u])
    if (v != p) {
      dfs(v, u);

      dp[u][0] += max(dp[v][0] + abs(seg[u].first - seg[v].first),
                      dp[v][1] + abs(seg[u].first - seg[v].second));
      dp[u][1] += max(dp[v][0] + abs(seg[u].second - seg[v].first),
                      dp[v][1] + abs(seg[u].second - seg[v].second));
    }
}

int solve() {
  int nbSommets;
  cin >> nbSommets;
  adj.clear();
  adj.resize(nbSommets);
  seg.resize(nbSommets);
  dp.resize(nbSommets);
  for (int iSommet = 0; iSommet < nbSommets; ++iSommet) {
    cin >> seg[iSommet].first >> seg[iSommet].second;
  }
  for (int i = 0; i < nbSommets - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  return max(dp[0][0], dp[0][1]);
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';
}