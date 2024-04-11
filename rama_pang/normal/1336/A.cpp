#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;
int n, k;
vector<int> adj[MAXN];
int depth[MAXN], sz[MAXN];
int par[MAXN], deg[MAXN];

void dfs(int n, int p) {
  sz[n] = 1;
  for (auto i : adj[n]) if (i != p) {
    depth[i] = depth[n] + 1;
    par[i] = n;
    dfs(i, n);
    sz[n] += sz[i];
    // dfs(i, n);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    deg[u]++, deg[v]++;
  }

  depth[1] = 1;
  dfs(1, 0);

  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) pq.emplace(depth[i] - sz[i], i);
  }
  lint ans = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    ans += d;
    k--;
    // cout << u << " " << d << " cur\n";
    if (k == 0) break;
    if (u == 1) break;
    deg[par[u]]--;
    if (deg[par[u]] == 1) {
      pq.emplace(depth[par[u]] - sz[par[u]], par[u]);
    }
  }
  cout << ans << "\n";

}