#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 500005;
const int BITS = 20;
const lint INF = 1e18;

int N, K, M;
vector<int> adj[MAXN];
array<int, 3> E[MAXN];

int par[MAXN][BITS];
int depth[MAXN];

int p[MAXN];
int Find(int x) {
  return p[x] == x ? x : p[x] = Find(p[x]);
}

int GetAncestor(int x, int y) {
  for (int i = 0; i < BITS; i++) {
    if (y >> i & 1) {
      x = par[x][i];
    }
  }
  return x;
}

int Lca(int x, int y) {
  if (depth[x] > depth[y]) swap(x, y);
  y = GetAncestor(y, depth[y] - depth[x]);
  if (x == y) return x;
  for (int i = BITS - 1; i >= 0; i--) {
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  }
  return par[x][0];
}

void DfsInit(int u, int p) {
  depth[u] = depth[p] + 1;
  par[u][0] = p;
  for (int i = 1; i < BITS; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : adj[u]) if (v != p) DfsInit(v, u);
}

lint ans = 0;
multiset<int> cost[MAXN];
vector<int> events[MAXN];

void DfsSolve(int u, int p) {
  for (auto v : adj[u]) if (v != p) {
    DfsSolve(v, u);
    if (cost[u].size() < cost[v].size()) {
      swap(cost[u], cost[v]);
    }
    for (auto i : cost[v]) {
      cost[u].emplace(i);
    }
    cost[v].clear();
  }
  for (auto e : events[u]) {
    if (e > 0) {
      cost[u].emplace(e);
    } else {
      cost[u].erase(cost[u].find(-e));
    }
  }
  if (p != 0 && cost[u].empty()) {
    ans = INF;
  } else {
    ans += *begin(cost[u]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  iota(p, p + MAXN, 0);

  cin >> N >> K >> M;
  for (int i = 0; i < K; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    p[Find(u)] = Find(v);
  }

  for (int i = 0; i < M; i++) {
    cin >> E[i][2] >> E[i][1] >> E[i][0]; 
  }

  sort(E, E + M);
  for (int i = 0; i < M; i++) {
    if (Find(E[i][1]) != Find(E[i][2])) {
      p[Find(E[i][1])] = Find(E[i][2]);
      adj[E[i][1]].emplace_back(E[i][2]);
      adj[E[i][2]].emplace_back(E[i][1]);
      ans -= E[i][0];
    }
  }

  DfsInit(1, 0);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    u = E[i][1], v = E[i][2], w = E[i][0];
    int uv = Lca(u, v);
    if (uv == 0) continue;
    events[u].emplace_back(w);
    events[v].emplace_back(w);
    events[uv].emplace_back(-w);
    events[uv].emplace_back(-w);
  }

  DfsSolve(1, 0);
  if (ans >= INF) ans = -1;

  cout << ans << "\n";
  return 0;
}