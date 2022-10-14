#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

class StronglyConnected {
 public:
  lint n;
  vector<pair<lint, lint>> edge;
  vector<pair<lint, lint>> redge;
  
  lint scc = 0;
  vector<lint> comp;
  vector<pair<lint, lint>> sccedge;
 
  StronglyConnected() {}
  StronglyConnected(lint n) : n(n), comp(n) {}
 
  void AddEdge(lint u, lint v) {
    edge.emplace_back(u, v);
    redge.emplace_back(v, u);
  }
 
  vector<lint> st, et;

  vector<lint> vis;
  void Dfs1(lint u, vector<lint> &vec) {
    vis[u] = 1;
    for (lint i = st[u]; i <= et[u]; i++) if (i != -1) {
      lint v = edge[i].second;
      if (!vis[v]) Dfs1(v, vec);
    }
    vec.emplace_back(u);
  }

  void Dfs2(lint u, lint color) {
    vis[u] = 1;
    comp[u] = color;
    for (lint i = st[u]; i <= et[u]; i++) if (i != -1) {
      lint v = redge[i].second;
      if (!vis[v]) Dfs2(v, color);
    }
  }

  void Kosaraju() {
    sort(begin(edge), end(edge));
    sort(begin(redge), end(redge));
 
    st.assign(n, -1);
    et.assign(n, -1);
    for (lint i = 0; i < lint(edge.size()); i++) {
      if (st[edge[i].first] == -1) {
        st[edge[i].first] = i;
      }
      et[edge[i].first] = i;
    }
    
    vector<lint> topo;
    vis.assign(n, 0);
    for (lint i = 0; i < n; i++) {
      if (!vis[i]) {
        Dfs1(i, topo);
      }
    }

    st.assign(n, -1);
    et.assign(n, -1);
    for (lint i = 0; i < lint(redge.size()); i++) {
      if (st[redge[i].first] == -1) {
        st[redge[i].first] = i;
      }
      et[redge[i].first] = i;
    }

    vis.assign(n, 0);
    reverse(begin(topo), end(topo));
    for (auto i : topo) if (!vis[i]) {
      Dfs2(i, i);
    }
 
    for (auto [u, v] : edge) {
      if (comp[u] != comp[v]) {
        sccedge.emplace_back(comp[u], comp[v]);
      }
    }
    sort(begin(sccedge), end(sccedge));
    sccedge.resize(unique(begin(sccedge), end(sccedge)) - begin(sccedge));
  }
};

lint Gcd(lint a, lint b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return __gcd(a, b);
}

void Main() {
  lint N, M;
  cin >> N >> M;

  // T * k - S = C1 * x1 + C2 * x2 + .. 
  // If there is cycle C1, C2 with Gcd == 1: YES
  // We want to calc Gcd of all cycles
  // Otherwise, S % Gcd(cycleGcd, T) == 0

  StronglyConnected G(N);
  vector<array<lint, 3>> edge;
  for (lint i = 0; i < M; i++) {
    lint u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edge.push_back({u, v, w});
    G.AddEdge(u, v);
  }
  G.Kosaraju();
  vector<int> depth(N);
  vector<lint> dist(N, -1);
  vector<vector<pair<lint, lint>>> adj(N);
  for (lint i = 0; i < M; i++) {
    auto [u, v, w] = edge[i];
    if (G.comp[u] == G.comp[v]) {
      adj[u].emplace_back(v, w);
    }
  }

  for (lint s = 0; s < N; s++) if (G.comp[s] == s) {
    assert(dist[s] == -1);
    priority_queue<pair<lint, lint>> pq;
    dist[s] = 0;
    depth[s] = 0;
    pq.emplace(-dist[s], s);
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop(); d *= -1;
      if (dist[u] != d) continue;
      for (auto [v, w] : adj[u]) {
        if (dist[v] == -1 || dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          depth[v] = depth[u] + 1;
          pq.emplace(-dist[v], v);
        }
      }
    }
  }

  vector<lint> gcdCycle(N, 0);
  for (lint i = 0; i < M; i++) {
    auto [u, v, w] = edge[i];
    if (G.comp[u] != G.comp[v]) continue;
    // dist[v] <= dist[u] + w
    lint g = (dist[u] - dist[v]) + w;
    gcdCycle[G.comp[u]] = Gcd(gcdCycle[G.comp[u]], g);
  }

  lint Q;
  cin >> Q;
  while (Q--) {
    lint v, S, T;
    cin >> v >> S >> T;
    v--;
    if (S % Gcd(T, gcdCycle[G.comp[v]]) == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  lint T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}