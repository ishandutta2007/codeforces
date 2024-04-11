/***

conditions:
  - if an edge is already on the shortest path, it should be a crucial edge
  - the repairment should change the shortest path cost
  prob put a "YES" here if ans = 0
***/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int mod = 1000011011;

int n, m, s, t;
int g[2][MAXN];
long long f[2][MAXN];
vector<pair<int, int>> adj[2][MAXN];

void dijkstra(int s, int t, long long *f, int *g, vector<pair<int, int>> *adj) {
  fill(f, f + MAXN, 1LL * mod * mod);
  fill(g, g + MAXN, 0);
  set<pair<long long, int>> que;
  f[s] = 0;
  g[s] = 1;
  que.emplace(f[s], s);
  while(!que.empty()) {
    auto p = *que.begin(); que.erase(p);
    int v = p.second;
    long long w = p.first;
    if(w != f[v]) continue;
    for(auto &e : adj[v]) {
      int s = e.first, w = e.second;
      if(f[v] + w < f[s]) {
        f[s] = f[v] + w;
        g[s] = g[v];
        que.emplace(f[s], s);
      }
      else if(f[v] + w == f[s]) {
        g[s] += g[v];
        if(g[s] >= mod) g[s] -= mod;
      }
    }
  }
}

/***
Each pair of cities can have multiple roads between them.
It is guaranteed that there is a path from s to t along the roads.

the ps should kill himself
 one-way roads

 fuck you ps
***/

vector<pair<pair<int, int>, int>> edges;
map<pair<pair<int, int>, int>, int> mymap;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> s >> t;
  for(int i = 0; i < m; ++i) {
    int u, v, l; cin >> u >> v >> l;
    adj[0][u].emplace_back(v, l);
    adj[1][v].emplace_back(u, l);
    edges.emplace_back(make_pair(u, v), l);
    mymap[edges.back()]++;
  }

  dijkstra(s, t, f[0], g[0], adj[0]);
  dijkstra(t, s, f[1], g[1], adj[1]);

  for(auto &e : edges) {
    /// YES check
    int u = e.first.first, v = e.first.second, w = e.second;

    if(f[0][u] + w + f[1][v] == f[0][t] && 1LL * g[0][u] * g[1][v] % mod == g[0][t] && mymap[e] == 1) {
      cout << "YES\n";
      continue;
    }

    long long newcost = f[0][t] - 1 - f[0][u] - f[1][v];
    if(newcost > 0) {
      cout << "CAN " << w - newcost << "\n";
    }
    else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}