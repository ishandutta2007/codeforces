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

struct Segtree {
  vector<int> seg, lazy, iDeb, iFin;
  const int INF = -1e18;

  Segtree(int nbVals) {
    int p = 0;
    while ((1 << p) < nbVals)
      ++p;
    int deb = 1 << p;
    seg.resize(2 * deb + 1);
    lazy.resize(2 * deb + 1);
    iDeb.resize(2 * deb + 1);
    iFin.resize(2 * deb + 1);
    buildTree(1, 0, nbVals - 1);
  }

  void buildTree(int iNoeud, int l, int r) {
    iDeb[iNoeud] = l, iFin[iNoeud] = r;
    seg[iNoeud] = lazy[iNoeud] = INF;
    if (l == r)
      return;
    buildTree(iNoeud * 2, l, (l + r) / 2);
    buildTree(2 * iNoeud + 1, (l + r) / 2 + 1, r);
  }

  void pull(int iNoeud) {
    seg[iNoeud] = max(seg[2 * iNoeud], seg[2 * iNoeud + 1]);
  }

  void push(int iNoeud) {
    if (lazy[iNoeud] == INF)
      return;
    seg[iNoeud] = max(seg[iNoeud], lazy[iNoeud]);
    if (iDeb[iNoeud] < iFin[iNoeud]) {
      lazy[2 * iNoeud] = max(lazy[2 * iNoeud], lazy[iNoeud]);
      lazy[2 * iNoeud + 1] = max(lazy[2 * iNoeud + 1], lazy[iNoeud]);
    }
    lazy[iNoeud] = INF;
  }

  void upd(int iNoeud, int deb, int fin, int v) {
    push(iNoeud);
    if (deb > iFin[iNoeud] or fin < iDeb[iNoeud])
      return;
    if (deb <= iDeb[iNoeud] and iFin[iNoeud] <= fin) {
      lazy[iNoeud] = v;
      push(iNoeud);
      return;
    }
    upd(2 * iNoeud, deb, fin, v);
    upd(2 * iNoeud + 1, deb, fin, v);
    pull(iNoeud);
  }

  int query(int iNoeud, int pos) {
    push(iNoeud);
    if (iDeb[iNoeud] > pos or iFin[iNoeud] < pos)
      return INF;
    if (iDeb[iNoeud] == iFin[iNoeud])
      return seg[iNoeud];
    return max(query(2 * iNoeud, pos), query(2 * iNoeud + 1, pos));
  }
};

const int MAXN = 3e5;
const int MAXP = 19;
vector<pair<int, int>> adj[MAXN];
int par[MAXP][MAXN], parWeight[MAXP][MAXN];
int tin[MAXN], tout[MAXN];
int curT;
int depth[MAXN];
struct Edge {
  int u, v, w;
};

void dfs(int u, int p = 0, int x = 0) {
  tin[u] = curT++;
  par[0][u] = p, parWeight[0][u] = x;
  for (int i = 0; i < MAXP - 1; ++i) {
    int pp = par[i][u];
    par[i + 1][u] = par[i][pp];
    parWeight[i + 1][u] = parWeight[i][u] ^ parWeight[i][pp];
  }

  for (auto [v, w] : adj[u])
    if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u, w);
    }
  tout[u] = curT++;
}

pair<int, int> lcaWeight(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);
  int diff = depth[u] - depth[v];
  int ret = 0;
  for (int p = 0; p < MAXP; ++p)
    if ((1 << p) & diff) {
      ret ^= parWeight[p][u];
      u = par[p][u];
    }
  if (u == v)
    return {u, ret};
  for (int p = MAXP - 1; p >= 0; --p)
    if (par[p][u] != par[p][v]) {
      ret ^= parWeight[p][u] ^ parWeight[p][v];
      u = par[p][u];
      v = par[p][v];
    }
  ret ^= parWeight[0][u] ^ parWeight[0][v];
  return {par[0][u], ret};
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSommets, nbRequetes;
  cin >> nbSommets >> nbRequetes;
  vector<Edge> edges(nbRequetes);
  for (auto &[u, v, w] : edges) {
    cin >> u >> v >> w;
    --u, --v;
  }

  vector<int> sol(nbRequetes);
  vector<int> restant;
  UnionFind uf(nbSommets);
  for (int iArete = 0; iArete < nbRequetes; ++iArete) {
    auto [u, v, w] = edges[iArete];
    if (uf.merge(u, v)) {
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
      sol[iArete] = 1;
    } else
      restant.push_back(iArete);
  }

  if (restant.empty()) {
    while (nbRequetes--)
      cout << "YES\n";
    return 0;
  }
  for (int i = 0; i < nbSommets; ++i)
    if (!tout[i])
      dfs(i, i);

  Segtree seg(curT);
  for (int iArete : restant) {
    auto [u, v, weight] = edges[iArete];
    auto [lca, Xor] = lcaWeight(u, v);
    Xor ^= weight;
    // cout << u + 1 << ' ' << v + 1 << ' ' << Xor << endl;
    if (Xor != 1 or seg.query(1, tin[u]) > depth[lca] or
        seg.query(1, tin[v]) > depth[lca])
      continue;
    sol[iArete] = 1;
    while (u != lca) {
      seg.upd(1, tin[u], tout[u], depth[u]);
      u = par[0][u];
    }
    assert(depth[v] >= depth[lca]);
    while (v != lca) {
      seg.upd(1, tin[v], tout[v], depth[v]);
      v = par[0][v];
    }
    // seg.upd(1, tin[lca], tout[lca], depth[lca]);
  }
  for (int x : sol)
    cout << (x ? "YES" : "NO") << '\n';
}