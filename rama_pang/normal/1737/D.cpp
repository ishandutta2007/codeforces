#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<vector<lint>> edge(N, vector<lint>(N, INF));
  vector<vector<lint>> A(N, vector<lint>(N, INF));
  vector<vector<lint>> best(N, vector<lint>(N, INF));
  while (M--) {
    lint u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edge[u][v] = edge[v][u] = 1;
    A[u][v] = A[v][u] = min(A[u][v], w);    
    best[u][v] = best[v][u] = min(best[u][v], w);        
  }
  for (int u = 0; u < N; u++) edge[u][u] = best[u][u] = 0;
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
      }
    }
  }
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (A[u][v] == INF) continue;
      for (int k = 0; k < N; k++) {
        best[u][k] = min(best[u][k], (edge[v][k] + 1) * A[u][v]);
      }
    }
  }
  vector<lint> opt(N, INF);
  for (int u = 0; u < N; u++) {
    for (int v = 0; v < N; v++) {
      if (A[u][v] == INF) continue;
      best[0][N - 1] = min(best[0][N - 1], (edge[0][u] + edge[v][N - 1] + 1) * A[u][v]);
      for (int k = 0; k < N; k++) {
        best[0][N - 1] = min(best[0][N - 1], (edge[k][0] + edge[k][N - 1] + edge[k][u] + 2) * A[u][v]);
      }
    }
  }
  // for (int s = 0; s < N; s++) {
  //   vector<pair<lint, lint>> lines;

  //     // lines.emplace_back(edge[s][u] + 2, edge[s][u] * opt);      
    
  //   // sort(begin(lines), end(lines));
  //   // vector<pair<lint, lint>> hull;
  //   // for (auto [a, b] : lines) {
  //   //   while (!hull.empty() && end(hull)[-2])
  //   //   hull.emplace_back(a, b);
  //   // }
  //   // best[u][v] min= (edge[s][u] + edge[s][v] + edge[s][w] + 2) * opt[w]
  //   // 
  //   for (auto [d, u, v] : pairs) {
  //     for (int w = 0; w < N; w++) {
  //       if (opt[w] == INF) continue;
  //       best[u][v] = min(best[u][v], (edge[s][u] + edge[s][v] + edge[s][w] + 2) * opt[w]);
  //     }
  //   }
  // }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        best[i][j] = min(best[i][j], best[i][k] + best[k][j]);
      }
    }
  }
  cout << best[0][N - 1] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T =1 ;
  cin >> T;
  while (T--) Main();
}