#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

class Dinic {
 public:
  struct Edge {
    int u, v;
    lint cap, flow;
  };

  Dinic() {}
  Dinic(int n) : n(n) {
    adj.resize(n);
  }

  int n, s, t;
  vector<Edge> edge;
  vector<vector<int>> adj;

  vector<int> level, ptr;
  queue<int> q;

  void AddEdge(int u, int v, lint c) {
    while (n < max(u, v)) {
      n += 1;
      adj.emplace_back();
    }
    adj[u].emplace_back(edge.size() + 0);
    adj[v].emplace_back(edge.size() + 1);
    edge.push_back({u, v, c, 0});
    edge.push_back({v, u, 0, 0});
  }

  bool Bfs() {
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto e_id : adj[u]) {
        auto e = edge[e_id];
        if (e.cap - e.flow == 0 || level[e.v] != -1) {
          continue;
        }
        level[e.v] = level[u] + 1;
        q.emplace(e.v);
      }
    }
    return level[t] != -1;
  }

  lint Dfs(int u, lint fl) {
    if (fl == 0) return 0;
    if (u == t) return fl;
    for (int &p = ptr[u]; p < (int) adj[u].size(); p++) {
      int id = adj[u][p];
      auto e = edge[id];
      if (level[e.v] != level[u] + 1 || e.cap - e.flow == 0) {
        continue;
      }
      lint res = Dfs(e.v, min(fl, e.cap - e.flow));
      if (res == 0) continue;
      edge[id].flow += res;
      edge[id ^ 1].flow -= res;
      return res;
    }
    return 0;
  }

  lint MaxFlow(int s_, int t_) {
    s = s_, t = t_;
    lint f = 0;
    while (true) {
      level.assign(n, -1);
      level[s] = 0;
      q.emplace(s);
      if (!Bfs()) {
        break;
      }
      ptr.assign(n, 0);
      while (lint fl = Dfs(s, INF)) {
        f += fl;
      }
    }
    return f;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  map<int, int> color;
  map<array<int, 4>, int> name;
  set<pair<int, int>> edges;
  name[{-1, -1, -1, -1}] = 0;
  name[{-2, -2, -2, -2}] = 1;
  const auto Name = [&](int i, int j, int k, int l) {
    if (pair(i, j) > pair(k, l)) swap(i, k), swap(j, l);
    if (name.count({i, j, k, l})) return name[{i, j, k, l}];
    int res = name.size();
    name[{i, j, k, l}] = name.size();
    color[name[{i, j, k, l}]] = abs(i - k) == 1 ? 1 : 2;
    return name[{i, j, k, l}];
  };

  int cells = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) if (A[i][j] == '#') {
      cells += 1;
      if (i + 1 < N && A[i + 1][j] == '#') {
        Name(i, j, i + 1, j);
      }
      if (j + 1 < M && A[i][j + 1] == '#') {
        Name(i, j, i, j + 1);
      }
    }
  }

  const vector<int> dx = {0, 1, 0, -1};
  const vector<int> dy = {1, 0, -1, 0};

  const auto Empty = [&](int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M && A[x][y] == '#';
  };

  const auto AddEdge = [&](int u, int v) {
    if (u > v) swap(u, v);
    edges.emplace(u, v);
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) if (A[i][j] == '#') {
      for (int d1 = 0; d1 < 4; d1++) {
        for (int d2 = d1 + 1; d2 < 4; d2++) if (abs(d1 - d2) != 2) {
          if (Empty(i + dx[d1], j + dy[d1]) && Empty(i + dx[d2], j + dy[d2])) {
            AddEdge(Name(i + dx[d1], j + dy[d1], i, j), Name(i + dx[d2], j + dy[d2], i, j));
          }
        }
      }
    }
  }

  Dinic mf(name.size());
  const int SOURCE = 0;
  const int SINK = 1;

  for (int i = 2; i < name.size(); i++) {
    assert(color[i] == 1 || color[i] == 2);
    if (color[i] == 1) {
      mf.AddEdge(SOURCE, i, 1);
    } else {
      mf.AddEdge(i, SINK, 1);
    }
  }

  for (auto [u, v] : edges) {
    assert(color[u] == 1 || color[u] == 2);
    assert(color[v] == 1 || color[v] == 2);
    assert(color[u] != color[v]);
    if (color[u] == 1) {
      mf.AddEdge(u, v, 1);
    } else {
      mf.AddEdge(v, u, 1);
    }
  }

  int maxflow = mf.MaxFlow(SOURCE, SINK);
  int max_ind_set = (mf.n - 2) - maxflow; // how many borders we can delete

  cout << cells - max_ind_set << '\n';
  return 0;
}