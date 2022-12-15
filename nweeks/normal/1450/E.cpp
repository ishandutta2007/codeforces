#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200;

int dis[MAXN][MAXN];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int nbSommets, nbAretes;
  cin >> nbSommets >> nbAretes;
  for (int i = 0; i < nbSommets; ++i) {
    for (int j = 0; j < nbSommets; ++j) {
      dis[i][j] = 1e18;
    }
    dis[i][i] = 0;
  }

  vector<pair<int, int>> edges;
  for (int iArete = 0; iArete < nbAretes; ++iArete) {
    int u, v, b;
    cin >> u >> v >> b;
    u--, v--;
    edges.emplace_back(u, v);
    if (b == 1)
      dis[u][v] = 1, dis[v][u] = -1;
    else
      dis[u][v] = dis[v][u] = 1;
  }

  for (int k = 0; k < nbSommets; ++k) {
    for (int i = 0; i < nbSommets; ++i) {
      for (int j = 0; j < nbSommets; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int k = 0; k < nbSommets; ++k) {
    for (int i = 0; i < nbSommets; ++i) {
      for (int j = 0; j < nbSommets; ++j) {
        if (dis[i][j] > dis[i][k] + dis[k][j]) {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  int bst = -1, sol = -1;
  for (int i = 0; i < nbSommets; ++i) {
    int m = 0;
    for (int j = 0; j < nbSommets; ++j) {
      m = max(m, dis[i][j]);
    }
    if (m > sol)
      bst = i, sol = m;
  }
  vector<int> a(nbSommets);
  for (int i = 0; i < nbSommets; ++i) {
    a[i] = dis[bst][i];
  }
  for (auto [u, v] : edges)
    if (abs(a[u] - a[v]) != 1) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  cout << sol << endl;
  for (int i = 0; i < nbSommets; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
}