#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5;
vector<pair<int, int>> adj[MAXN], revAdj[MAXN];
vector<int> order;
int scc[MAXN];
int gcdScc[MAXN];
int depth[MAXN];
bitset<MAXN> seen;

void dfs(int u) {
  if (seen[u])
    return;
  seen[u] = true;
  for (auto [v, l] : adj[u])
    dfs(v);
  order.push_back(u);
}

void revDfs(int u, int id) {
  if (seen[u])
    return;
  scc[u] = id;
  seen[u] = true;
  for (auto [v, l] : revAdj[u])
    revDfs(v, id);
}

void dfsScc(int u) {
  seen[u] = true;
  for (auto [v, l] : adj[u]) {
    if (scc[v] != scc[u])
      continue;
    if (!seen[v]) {
      depth[v] = depth[u] + l;
      dfsScc(v);
    } else
      gcdScc[scc[u]] = gcd(gcdScc[scc[u]], depth[u] - depth[v] + l);
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbSommets, nbAretes;
  cin >> nbSommets >> nbAretes;
  for (int iArete = 0; iArete < nbAretes; ++iArete) {
    int u, v, l;
    cin >> u >> v >> l;
    --u, --v;
    adj[u].emplace_back(v, l);
    revAdj[v].emplace_back(u, l);
  }

  for (int i = 0; i < nbSommets; ++i)
    dfs(i);
  seen.reset();
  int nbScc = 0;
  for (int i = nbSommets - 1; i >= 0; --i) {
    if (!seen[order[i]])
      revDfs(order[i], nbScc++);
  }
  seen.reset();
  for (int i = 0; i < nbSommets; ++i)
    if (!seen[i])
      dfsScc(i);

  int nbRequetes;
  cin >> nbRequetes;
  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int v, s, t;
    cin >> v >> s >> t;
    --v;
    if (s % gcd(gcdScc[scc[v]], t) == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}