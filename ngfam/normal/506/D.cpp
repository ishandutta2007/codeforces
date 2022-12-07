/**
  First dumb shit: Graph has less than sqrt edges can brute forces to precalculate
                   Graph has more than sqrt edges can keep track of dsu info
  256mb?
  :pray:

  sqrt log does not seems to work
  fuck...

  can actually reduce the log
**/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int MAXB = 400;

struct dsu{
  int par[MAXN];
  dsu() {
    memset(par, -1, sizeof par);
  }
  int find(int x) {
    return par[x] < 0 ? x : par[x] = find(par[x]);
  }
  void join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
  }
}dsu[MAXN / MAXB + 1];

int n, m;
vector<pair<int, int>> edges[MAXN];

vector<int> g[MAXN];

int main() {

  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u, v, c;
     cin >> u >> v >> c;
     edges[--c].emplace_back(--u, --v);
  }

  int count = 1;
  for(int i = 0; i < m; ++i) {
    vector<int> vertices;
    for(auto e : edges[i]) {
      vertices.push_back(e.first);
      vertices.push_back(e.second);
    }
    sort(vertices.begin(), vertices.end());
    vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());

    if(vertices.size() < MAXB) {
      for(auto &e : edges[i]) {
        dsu[0].join(e.first, e.second);
      }
      for(int u : vertices) {
        for(int v : vertices) {
          if(u != v && dsu[0].find(u) == dsu[0].find(v)) {
            g[u].push_back(v);
          }
        }
      }
      for(int u : vertices) dsu[0].par[u] = -1;
    }
    else {
      for(auto &e : edges[i]) {
        dsu[count].join(e.first, e.second);
      }
      ++count;
    }
  }

  for(int v = 0; v < n; ++v) {
    sort(g[v].begin(), g[v].end());
  }

  int q; cin >> q;
  while(q--) {
    int u, v; cin >> u >> v;
    --u; --v;
    int ans = 0;
    for(int i = 1; i < count; ++i) {
      ans += (dsu[i].find(u) == dsu[i].find(v));
    }
    ans += upper_bound(g[u].begin(), g[u].end(), v) - lower_bound(g[u].begin(), g[u].end(), v);
    cout << ans << "\n";
  }

  return 0;
}