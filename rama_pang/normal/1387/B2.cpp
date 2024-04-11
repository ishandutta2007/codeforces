#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];

int ans[MAXN];
int identity[MAXN];
long long score = 0;

int sz[MAXN];
int par[MAXN];

void Calc(int u, int p) {
  sz[u] = 1;
  for (auto v : adj[u]) if (v != p) {
    Calc(v, u);
    sz[u] += sz[v];
    score += 2 * min(sz[v], N - sz[v]);
  }
}

void Dfs(int u, int p) {
  par[u] = p, sz[u] = 1;
  for (auto v : adj[u]) if (v != p) {
    Dfs(v, u);
    sz[u] += sz[v];
  }
}

int Centroid(int u) {
  Dfs(u, 0);
  int total_sz = sz[u];
  while (true) {
    pair<int, int> mx = {-1, -1};
    for (auto v : adj[u]) if (v != par[u]) {
      mx = max(mx, {sz[v], v});
    }
    if (mx.first * 2 <= total_sz) {
      return u;
    }
    u = mx.second;
  }
  return -1;
}

void GetNodes(int u, int p, vector<int> &nodes) {
  nodes.emplace_back(u);
  for (auto v : adj[u]) if (v != p) {
    GetNodes(v, u, nodes);
  }
}

void Solve() {
  int u = Centroid(1);
  Dfs(u, 0);
  vector<int> nodes = {u};
  pair<int, int> mx = {1, u};
  for (auto v : adj[u]) {
    mx = max(mx, {sz[v], v});
    GetNodes(v, u, nodes);
  }
  vector<int> old_id(nodes.size());
  for (int i = 0; i < (int) nodes.size(); i++) {
    old_id[i] = identity[nodes[i]];
  }
  for (int i = 0; i < (int) nodes.size(); i++) {
    identity[nodes[i]] = old_id[(i - mx.first + (int) nodes.size()) % nodes.size()];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  iota(identity + 1, identity + N + 1, 1);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  Calc(1, 0);
  Solve();
  for (int i = 1; i <= N; i++) {
    ans[identity[i]] = i;
  }

  cout << score << "\n";
  for (int i = 1; i <= N; i++) {
    assert(ans[i] != i);
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}