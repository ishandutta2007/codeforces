#include<bits/stdc++.h>

using namespace std;

const int MAXN = 500050;
const int MAXLOG = 20;

int n, k, m, cnt;

int par[MAXN];
int depth[MAXN];
int visit[MAXN];
int jump[MAXN][MAXLOG];
vector < int > g[MAXN];
map < pair < int, int >, int > answer, mark;

void dfs_prepare(int v, int p = 0) {
  visit[v] = cnt;
  for(int s : g[v]) if(s != p) {
    depth[s] = depth[v] + 1;
    par[s] = jump[s][0] = v;
    for(int i = 1; i < MAXLOG; ++i) {
      jump[s][i] = jump[jump[s][i - 1]][i - 1];
    }
    dfs_prepare(s, v);
  }
}

int lca(int u, int v) {
  if(depth[u] < depth[v]) swap(u, v);
  for(int i = MAXLOG - 1; i >= 0; --i) if(depth[jump[u][i]] >= depth[v]) {
    u = jump[u][i];
  }
  if(u == v) return u;
  for(int i = MAXLOG - 1; i >= 0; --i) if(jump[u][i] != jump[v][i]) {
    u = jump[u][i];
    v = jump[v][i];
  }
  return par[u];
}

int lab[MAXN];

int find(int v) {
  return lab[v] < 0 ? v : lab[v] = find(lab[v]);
}

void join(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(lab[u] > lab[v]) swap(u, v);
  lab[u] += lab[v];
  lab[v] = u;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  fill(lab, lab + MAXN, -1);
  cin >> n >> k >> m;

  for(int i = 0; i < k; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    if(u > v) swap(u, v);
    g[v].push_back(u);
    g[u].push_back(v);
    mark[make_pair(u, v)] = 1;
    join(u, v);
  }

  vector < pair < pair < int, int >, int > > edges;

  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    edges.emplace_back(make_pair(u, v), w);
    if(find(u) != find(v)) {
      g[u].push_back(v);
      g[v].push_back(u);
      join(u, v);
    }
  }

  for(int i = 0; i < n; ++i) if(!visit[i]) {
    ++cnt;
    dfs_prepare(i);
  }


  fill(lab, lab + MAXN, -1);

  for(int i = 0; i < m; ++i) {
    int u, v, w;
    u = edges[i].first.first; v = edges[i].first.second;
    w = edges[i].second;

    if(visit[u] != visit[v]) continue;
    int p = lca(u, v);

    while(true) {
      int x = find(u);
      if(x == find(p)) break;
      for(int i = MAXLOG - 1; i >= 0; --i) {
        if(find(jump[u][i]) == find(u)) u = jump[u][i];
      }

      if(u < par[u]) answer[make_pair(u, par[u])] = w;
      else answer[make_pair(par[u], u)] = w;
      join(u, par[u]);
      u = par[u];
    }

    while(true) {
      int x = find(v);
      if(x == find(p)) break;
      for(int i = MAXLOG - 1; i >= 0; --i) {
        if(find(jump[v][i]) == find(v)) v = jump[v][i];
      }
      if(v < par[v]) answer[make_pair(v, par[v])] = w;
      else answer[make_pair(par[v], v)] = w;
      join(v, par[v]);
      v = par[v];
    }
  }

  long long total = 0;
  for(int i = 0; i < n; ++i) {
    for(int j : g[i]) if(mark[make_pair(i, j)]){
      if(!answer[make_pair(i, j)]) return cout << -1, 0;
      total += answer[make_pair(i, j)];
    }
  }

  cout << total << "\n";

  return 0;
}