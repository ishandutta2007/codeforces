#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 600;
const int INF = 2e9;

struct Arete {
  int point, cost;

  bool operator<(Arete other) const {
    if (cost == other.cost)
      return point < other.point;
    return cost < other.cost;
  }
};
int nbSommets, nbAretes;

vector<Arete> adj[MAXN];
int weightEdge[MAXN][MAXN];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> nbSommets >> nbAretes;
  for (int iArete = 0; iArete < nbAretes; ++iArete) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
  }

  auto calcWeightEdges = [&](int mod, int iStart) {
    vector<int> weightEdges(nbSommets, INF);
    priority_queue<pair<int, int>> pq;
    for (auto [point, cost] : adj[iStart]) {
      int nxt = (point + mod) % nbSommets;
      weightEdges[nxt] = cost;
      pq.emplace(-cost, nxt);
    }
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      d = -d;
      if (d > weightEdges[u])
        continue;
      int v = (u + 1) % nbSommets;
      if (weightEdges[v] > d + 1) {
        weightEdges[v] = d + 1;
        pq.emplace(-d - 1, v);
      }
    }

    return weightEdges;
  };

  for (int i(0); i < nbSommets; ++i) {
    auto w = calcWeightEdges(0, i);
    for (int j = 0; j < nbSommets; ++j) {
      weightEdge[i][j] = w[j];
    }
  }

  vector<bool> seen(nbSommets);
  for (int iStart(0); iStart < nbSommets; ++iStart) {
    priority_queue<pair<int, int>> pq;
    vector<int> dis(nbSommets, INF);
    dis[iStart] = 0;
    for (int i(0); i < nbSommets; ++i)
      if (i != iStart) {
        dis[i] = weightEdge[iStart][i];
        pq.emplace(-dis[i], i);
      }

    while (!pq.empty()) {
      auto [d, iSommet] = pq.top();
      pq.pop();
      d = -d;
      int dmod = d % nbSommets;
      if (d != dis[iSommet])
        continue;

      for (int nxtSommet = 0; nxtSommet < nbSommets; ++nxtSommet) {
        int bef = nxtSommet - dmod;
        if (bef < 0)
          bef += nbSommets;
        int w = d + weightEdge[iSommet][bef];
        if (dis[nxtSommet] > w) {
          dis[nxtSommet] = w;
          pq.emplace(-dis[nxtSommet], nxtSommet);
        }
      }
    }
    for (int i = 0; i < nbSommets; ++i) {
      cout << dis[i] << ' ';
    }
    cout << '\n';
  }
}