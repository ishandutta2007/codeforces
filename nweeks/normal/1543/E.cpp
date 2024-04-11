#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> getInv(vector<int> p) {
  vector<int> ret((int)p.size());
  for (int i = 0; i < (int)p.size(); ++i)
    ret[p[i]] = i;
  return ret;
}

void solve() {
  int n;
  cin >> n;
  int nbSommets = (1 << n);
  int nbAretes = n * nbSommets / 2;
  vector<vector<int>> adj(nbSommets);
  for (int iArete = 0; iArete < nbAretes; ++iArete) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  queue<int> q;
  vector<int> dis(nbSommets, -1);
  q.push(0);
  dis[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
  }

  vector<int> perm(nbSommets);
  int nbVus = 0;
  for (int i = 1; i < nbSommets; ++i)
    if (dis[i] == 1)
      perm[i] = 1 << (nbVus++);
  for (int d = 2; d <= n; ++d) {
    for (int i = 0; i < nbSommets; ++i)
      if (dis[i] == d) {
        for (int j : adj[i])
          if (dis[j] == d - 1)
            perm[i] |= perm[j];
      }
  }
  vector<int> invPerm = getInv(perm);
  for (auto v : invPerm)
    cout << v << ' ';
  cout << endl;
  for (int i = 0; i < nbSommets; ++i)
    for (int j : adj[i])
      assert(__builtin_popcount(perm[i] ^ perm[j]) == 1);
  if (__builtin_popcount(n) == 1) {
    for (int i = 0; i < nbSommets; ++i) {
      int x = perm[i];
      int c = 0;
      for (int j = 0; j < n; ++j)
        if ((1 << j) & x)
          c ^= j;
      cout << c << ' ';
    }
  } else
    cout << -1;
  cout << endl;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}