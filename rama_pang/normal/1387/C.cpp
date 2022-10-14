#include <bits/stdc++.h>
using namespace std;

class AhoCorasick {
 public:
  int sz;
  vector<int> sl; // suffix link
  vector<int> bad; // bad prefixes
  vector<array<int, 2>> d; // transition
  vector<array<int, 2>> c; // trie

  AhoCorasick() : sz(1), sl(1, 0), bad(1, 0), d(1, {0, 0}), c(1, {0, 0}) {}

  int NewNode() {
    sl.emplace_back(0);
    bad.emplace_back(0);
    d.push_back({0, 0});
    c.push_back({0, 0});
    return sz++;
  }

  void InsertString(vector<int> s) {
    int u = 0;
    for (auto i : s) {
      if (!c[u][i]) {
        int nw = NewNode();
        c[u][i] = nw;
      }
      u = c[u][i];
    }
    bad[u] = 1;
  }

  void Build() {
    for (queue<int> q({0}); !q.empty(); q.pop()) {
      int u = q.front();
      bad[u] |= bad[sl[u]];
      for (int i = 0; i < 2; i++) {
        int v = c[u][i];
        if (v != 0) {
          sl[v] = d[sl[u]][i];
          d[u][i] = v;
          bad[v] |= bad[u];
          q.emplace(v);
        } else {
          d[u][i] = d[sl[u]][i];
        }
      }
    }
  }

  bool IsBadPrefix(int x) {
    return bad[x];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int G, N, M;
  cin >> G >> N >> M;

  vector<vector<vector<int>>> adj(G);
  for (int rep = 0; rep < N; rep++) {
    int u, k;
    cin >> u >> k;
    vector<int> v;
    while (k--) {
      v.emplace_back();
      cin >> v.back();
    }
    while ((int) v.size() > 2) {
      int v2 = v.back(); v.pop_back();
      int v1 = v.back(); v.pop_back();
      int new_node = (int) adj.size();
      adj.emplace_back();
      adj[new_node].emplace_back();
      adj[new_node].back().emplace_back(v1);
      adj[new_node].back().emplace_back(v2);
      v.emplace_back(new_node);
    }
    adj[u].emplace_back();
    for (auto vi : v) {
      adj[u].back().emplace_back(vi);
    }
  }

  vector<vector<pair<int, int>>> radj(adj.size());
  for (int u = 0; u < (int) adj.size(); u++) {
    for (int vid = 0; vid < (int) adj[u].size(); vid++) {
      for (auto v : adj[u][vid]) {
        radj[v].emplace_back(u, vid);
      }
    }
  }

  AhoCorasick ac;
  for (int rep = 0; rep < M; rep++) {
    int l;
    cin >> l;
    vector<int> s;
    while (l--) {
      s.emplace_back();
      cin >> s.back();
    }
    ac.InsertString(s);
  }
  ac.Build();

  const unsigned long long INF = 1ull << 63;
  vector<vector<vector<unsigned long long>>> dist(adj.size(), 
      vector<vector<unsigned long long>>(ac.sz, vector<unsigned long long>(ac.sz, INF)));

  struct State {
    int u, st, et;
    unsigned long long d;
    State() {}
    State(int u, int st, int et, unsigned long long d) : u(u), st(st), et(et), d(d) {}
    const bool operator < (const State &o) const { return d > o.d; }
  };

  priority_queue<State> pq;
  auto Relax = [&](int x, int y, int z, unsigned long long w) {
    if (!ac.IsBadPrefix(y) && !ac.IsBadPrefix(z) && dist[x][y][z] > w) {
      dist[x][y][z] = w;
      pq.emplace(x, y, z, w);
    }
  };

  // Base Case
  for (int st = 0; st < ac.sz; st++) {
    Relax(0, st, ac.d[st][0], 1);
    Relax(1, st, ac.d[st][1], 1);
  }
  
  // Dijkstra
  while (!pq.empty()) {
    State s = pq.top();
    pq.pop();
    if (dist[s.u][s.st][s.et] != s.d || dist[s.u][s.st][s.et] == INF) {
      continue;
    }
    for (auto r : radj[s.u]) {
      int par = r.first;
      int id = r.second;
      if ((int) adj[par][id].size() == 1) {
        Relax(par, s.st, s.et, dist[s.u][s.st][s.et]);
      }
      if ((int) adj[par][id].size() == 2 && adj[par][id][0] == s.u) {
        int v = adj[par][id][1];
        for (int i = 0; i < ac.sz; i++) {
          Relax(par, s.st, i, dist[s.u][s.st][s.et] + dist[v][s.et][i]);
        }
      }
      if ((int) adj[par][id].size() == 2 && adj[par][id][1] == s.u) {
        int v = adj[par][id][0];
        for (int i = 0; i < ac.sz; i++) {
          Relax(par, i, s.et, dist[v][i][s.st] + dist[s.u][s.st][s.et]);
        }
      }
    }
  }

  for (int i = 2; i < G; i++) {
    unsigned long long ans = INF;
    for (int j = 0; j < ac.sz; j++) {
      if (!ac.IsBadPrefix(j) && ans > dist[i][0][j]) {
        ans = dist[i][0][j];
      }
    }
    if (ans == INF) {
      cout << "YES\n";
    } else {
      cout << "NO " << ans << "\n";
    }
  }
  return 0;
}