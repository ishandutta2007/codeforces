#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<string> G(N);
  for (int i = 0; i < N; i++) {
    cin >> G[i];
  }
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }

  int nodes = 0;
  vector<vector<int>> X(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (G[i][j] == '#') {
        X[i][j] = nodes++;
      } else {
        X[i][j] = -1;
      }
    }
  }
  vector<vector<int>> radj(nodes);
  vector<vector<int>> adj(nodes);
  const auto AddEdge = [&](int u, int v) {
    adj[u].emplace_back(v);
    radj[v].emplace_back(u);
  };
  vector<int> last(M, -1);
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        if (j > 0 && last[j - 1] != -1) {
          AddEdge(X[i][j], last[j - 1]);
        }
        if (last[j] != -1) {
          AddEdge(X[i][j], last[j]);
        }
        if (j + 1 < M && last[j + 1] != -1) {
          AddEdge(X[i][j], last[j + 1]);
        }
      }
    }
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        last[j] = X[i][j];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (X[i][j] != -1) {
        if (i > 0 && X[i - 1][j] != -1) {
          AddEdge(X[i][j], X[i - 1][j]);
        }
        if (i + 1 < N && X[i + 1][j] != -1) {
          AddEdge(X[i][j], X[i + 1][j]);
        }
        if (j > 0 && X[i][j - 1] != -1) {
          AddEdge(X[i][j], X[i][j - 1]);
        }
        if (j + 1 < M && X[i][j + 1] != -1) {
          AddEdge(X[i][j], X[i][j + 1]);
        }
      }
    }
  }

  vector<int> vis(nodes), comp(nodes, -1), topo;
  const auto Dfs1 = [&](const auto &self, int u) -> void {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) self(self, v);
    topo.emplace_back(u);
  };
  for (int i = 0; i < nodes; i++) {
    if (!vis[i]) {
      Dfs1(Dfs1, i);
    }
  }

  reverse(begin(topo), end(topo));
  const auto Dfs2 = [&](const auto &self, int u, int c) -> void {
    comp[u] = c;
    for (auto v : radj[u]) if (comp[v] == -1) self(self, v, c);
  };

  int scc = 0;
  for (auto i : topo) {
    if (comp[i] == -1) {
      Dfs2(Dfs2, i, scc++);
    }
  }

  vector<int> indeg(scc);
  vector<vector<int>> sccadj(scc);
  for (int i = 0; i < nodes; i++) {
    for (auto j : adj[i]) {
      if (comp[i] == comp[j]) continue;
      sccadj[comp[i]].emplace_back(comp[j]);
      indeg[comp[j]]++;
    }
  }

  vis.assign(scc, 0);
  vector<int> mark(scc, -1);

  {
    vector<vector<int>> occ(M);
    for (int i = N - 1; i >= 0; i--) {
      for (int j = 0; j < M; j++) {
        if (X[i][j] != -1) {
          occ[j].emplace_back(X[i][j]);
        }
      }
    }
    for (int i = 0; i < M; i++) if (A[i] > 0) {
      int id = occ[i][A[i] - 1];
      mark[comp[id]] = i;
    }
  }

  const auto Dfs3 = [&](const auto &self, int u) -> void {
    vis[u] = 1;
    for (auto v : sccadj[u]) {
      if (mark[v] != -1) {
        mark[v] = -1;
      }
      if (!vis[v]) {
        self(self, v);
      }
    }
  };

  for (int i = 0; i < scc; i++) {
    if (mark[i] != -1) {
      Dfs3(Dfs3, i);
    }
  }

  const int INF = 1e9;
  vector<int> dpmin(scc, +INF);
  vector<int> dpmax(scc, -INF);

  vis.assign(scc, 0);
  const auto Dfs4 = [&](const auto &self, int u) -> void {
    vis[u] = 1;
    if (mark[u] != -1) {
      dpmin[u] = dpmax[u] = mark[u];
    }
    for (auto v : sccadj[u]) {
      if (!vis[v]) {
        self(self, v);
      }
      dpmin[u] = min(dpmin[u], dpmin[v]);
      dpmax[u] = max(dpmax[u], dpmax[v]);
    }
  };

  vector<int> coords;
  for (int i = 0; i < scc; i++) {
    Dfs4(Dfs4, i);
    if (mark[i] != -1) {
      coords.emplace_back(mark[i]);
    }
  }


  vector<pair<int, int>> inter;
  for (int i = 0; i < scc; i++) {
    if (indeg[i] == 0) {
      if (dpmin[i] != INF) {
        inter.emplace_back(dpmin[i], dpmax[i]);
      }
    }
  }

  sort(begin(coords), end(coords));
  coords.resize(unique(begin(coords), end(coords)) - begin(coords));
  int K = coords.size();
  for (auto &x : inter) {
    x.first = lower_bound(begin(coords), end(coords), x.first) - begin(coords);
    x.second = lower_bound(begin(coords), end(coords), x.second) - begin(coords);
  }

  vector<vector<pair<int, int>>> distadj(K + 1);
  for (auto x : inter) {
    distadj[x.first].emplace_back(x.second + 1, 1);
  }
  for (int i = 1; i <= K; i++) {
    distadj[i].emplace_back(i - 1, 0);
  }

  vector<int> dist(K + 1, -1);
  priority_queue<pair<int, int>> pq;

  dist[0] = 0;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop(); d *= -1;
    if (dist[u] != d) continue;
    for (auto [v, w] : distadj[u]) {
      if (dist[v] == -1 || dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.emplace(-dist[v], v);
      }
    }
  }

  cout << dist[K] << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}