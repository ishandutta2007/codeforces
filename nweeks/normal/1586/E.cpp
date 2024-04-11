#include <bits/stdc++.h>
#define int long long
using namespace std;

struct UnionFind {
  vector<int> id;

  UnionFind() {}
  UnionFind(int N) { id.assign(N, -1); }

  int find(int u) {
    if (id[u] < 0)
      return u;
    return id[u] = find(id[u]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (id[u] > id[v])
      swap(u, v);
    id[u] += id[v];
    id[v] = u;
    return true;
  }
};

const int MAXN = 3e5;
vector<int> adj[MAXN];

int toAdd;
int depth[MAXN], par[MAXN];

int parityPar[MAXN];

void dfs(int u, int p) {
  par[u] = p;
  for (int v : adj[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
}

int solve(int u) {
  int cntAdd = 0;
  for (int v : adj[u])
    if (v != par[u]) {
      int hasEnd = solve(v);
      if (parityPar[v])
        cntAdd++;
      else if (hasEnd)
        toAdd++;
    }

  toAdd += cntAdd / 2;
  return cntAdd % 2;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (uf.merge(u, v)) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  dfs(0, 0);

  int nbRequetes;
  cin >> nbRequetes;
  vector<pair<int, int>> requetes(nbRequetes);
  vector<int> lca(nbRequetes);

  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    requetes[iRequete] = pair(u, v);

    while (u != v) {
      if (depth[u] < depth[v])
        swap(u, v);
      parityPar[u] ^= 1;
      u = par[u];
    }
    lca[iRequete] = u;
  }
  bool ok = true;
  for (int u = 1; u < n; ++u)
    if (parityPar[u]) {
      ok = false;
    }

  if (ok) {
    cout << "YES\n";

    for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
      auto [u, v] = requetes[iRequete];
      vector<int> path;
      int l = lca[iRequete];
      while (u != l) {
        path.push_back(u);
        u = par[u];
      }
      path.push_back(l);
      vector<int> path2;
      while (v != l) {
        path2.push_back(v);
        v = par[v];
      }
      reverse(path2.begin(), path2.end());
      for (int x : path2)
        path.push_back(x);
      cout << path.size() << '\n';
      for (int x : path)
        cout << x + 1 << ' ';
      cout << '\n';
    }
    return 0;
  }

  cout << "NO\n";
  cout << toAdd + solve(0) << endl;
}