#include <bits/stdc++.h>

const long long INF = 1E18;

int N, M;
std::vector <std::pair <int, int>> edge[110000];
int anc[110000][20], d[110000], vis[110000];
long long ancd[110000][20];
std::vector <int> spec;
long long dist[100][110000];

void dfs (int n, int f = 1) {
  vis[n] = true;
  for (auto e : edge[n]) if (e.first != f) {
    if (!vis[e.first]) {
      anc[e.first][0] = n; d[e.first] = d[n] + 1; ancd[e.first][0] = e.second;
      dfs (e.first, n);
    } else spec.push_back (n), spec.push_back (e.first);
  }
}

std::pair <int, long long> lca (int u, int v) {
  long long res = 0;
  for (int t = 19; t >= 0; --t) if (d[u] - (1 << t) >= d[v]) res += ancd[u][t], u = anc[u][t];
  for (int t = 19; t >= 0; --t) if (d[v] - (1 << t) >= d[u]) res += ancd[v][t], v = anc[v][t];
  if (u == v) return std::make_pair (u, res);
  for (int t = 19; t >= 0; --t) if (anc[u][t] != anc[v][t])
    res += ancd[u][t] + ancd[v][t], u = anc[u][t], v = anc[v][t];
  return std::make_pair (anc[u][0], res + ancd[u][0] + ancd[v][0]);
}

int main () {
  std::ios::sync_with_stdio (0);
  std::cin >> N >> M;
  while (M > 100000);
  for (int i = 0; i < M; ++i) {
    int u, v, c; std::cin >> u >> v >> c;
    edge[u].push_back (std::make_pair (v, c));
    edge[v].push_back (std::make_pair (u, c));
  }
  anc[1][0] = 1; ancd[1][0] = 0;
  dfs (1);
  std::sort (spec.begin (), spec.end ()); spec.resize (std::unique (spec.begin (), spec.end ()) - spec.begin ());
  while (spec.size () > 100);
  for (int t = 1; t < 20; ++t) for (int i = 1; i <= N; ++i)
    anc[i][t] = anc[anc[i][t - 1]][t - 1], ancd[i][t] = ancd[i][t - 1] + ancd[anc[i][t - 1]][t - 1];
  for (int i = 0; i < spec.size (); ++i) {
    int begin = spec[i]; std::priority_queue <std::pair <long long, int>> pq;
    for (int j = 1; j <= N; ++j) dist[i][j] = INF; dist[i][begin] = 0; pq.push (std::make_pair (0, begin));
    while (!pq.empty ()) {
      long long d = -pq.top ().first; int n = pq.top ().second; pq.pop (); if (d > dist[i][n]) continue;
      for (auto e : edge[n]) if (dist[i][e.first] > dist[i][n] + e.second) {
        dist[i][e.first] = dist[i][n] + e.second; pq.push (std::make_pair (-dist[i][e.first], e.first));
      }
    }
  }
  int Q; std::cin >> Q;
  for (int qq = 0; qq < Q; ++qq) {
    int u, v; std::cin >> u >> v;
    long long res = lca (u, v).second;
    for (int i = 0; i < spec.size (); ++i) res = std::min (res, dist[i][u] + dist[i][v]);
    std::cout << res << "\n";
  }
}