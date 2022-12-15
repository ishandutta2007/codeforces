#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
int par[MAXN];
int depth[MAXN];

void dfs(int u, int p, const vector<vector<int>> &adj) {
  par[u] = p;
  for (int v : adj[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u, adj);
    }
}

void solve() {
  int nbSommets;
  cin >> nbSommets;
  vector<vector<int>> adj(nbSommets);
  for (int i = 1; i < nbSommets; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> sizes;
  dfs(0, 0, adj);

  vector<bool> blocked(nbSommets);
  vector<int> order(nbSommets);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(),
       [&](int u, int v) { return depth[u] > depth[v]; });

  // cout << "--------\n";
  for (int u : order) {
    if (!u)
      break;
    // cout << u + 1 << ' ' << depth[u] << endl;
    int cntSons = 0;
    for (int v : adj[u])
      if (v != par[u] and !blocked[v])
        cntSons++;
    if (cntSons > 0) {
      sizes.push_back(cntSons), blocked[u] = true;
      // cout << "!" << endl;
    }
  }
  int rem = 0;
  for (int u : adj[0])
    if (!blocked[u])
      rem++;
  int tot = 0;
  for (int x : sizes)
    tot += x;
  tot += rem;
  tot -= rem ? sizes.size() : sizes.size() - 1;
  cout << tot << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}