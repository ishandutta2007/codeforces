#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
const int MAXP = 20;

int par[MAXP][MAXN];
int depth[MAXN];
int longestType[2][MAXN];

int lca(int u, int v) {
  if (par[MAXP - 1][u] != par[MAXP - 1][v])
    return -1;
  if (depth[u] < depth[v])
    swap(u, v);
  int d = depth[u] - depth[v];
  for (int p(0); p < MAXP; ++p)
    if ((1 << p) & d)
      u = par[p][u];
  if (u == v)
    return u;
  for (int p(MAXP - 1); p >= 0; --p)
    if (par[p][u] != par[p][v])
      u = par[p][u], v = par[p][v];
  return par[0][u];
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int nbSommets;
  cin >> nbSommets;
  for (int iSommet = 0; iSommet < nbSommets; ++iSommet) {
    int p, t;
    cin >> p >> t;
    if (p == -1) {
      par[0][iSommet] = iSommet;
      continue;
    }
    --p;
    par[0][iSommet] = p;
    depth[iSommet] = 1 + depth[p];
    if (t != -1)
      longestType[t][iSommet] = 1 + longestType[t][p];
  }
  for (int p = 0; p < MAXP - 1; ++p) {
    for (int i = 0; i < nbSommets; ++i) {
      par[p + 1][i] = par[p][par[p][i]];
    }
  }

  int nbRequetes;
  cin >> nbRequetes;
  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int t, u, v;
    cin >> t >> u >> v;
    --u, --v;
    int l = lca(u, v);

    if (t == 1) {
      if (u == v or l != u or longestType[0][v] < depth[v] - depth[u])
        cout << "NO";
      else
        cout << "YES";
    } else {
      if (l == -1 or l == v or longestType[1][v] < depth[v] - depth[l] or
          longestType[0][u] < depth[u] - depth[l])
        cout << "NO";
      else
        cout << "YES";
    }
    cout << '\n';
  }
}