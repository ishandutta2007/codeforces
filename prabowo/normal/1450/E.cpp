#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int M = 2005;
const int INF = 1e9;

int n, m;
int a[N];
int u[M], v[M], w[M];

int dist[N][N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) dist[i][j] = INF;
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &u[i], &v[i], &w[i]);
    --u[i], --v[i];

    dist[u[i]][v[i]] = 1;
    dist[v[i]][u[i]] = (w[i] == 0 ? 1 : -1);
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
      if (dist[i][i] < 0) return 0 * printf("NO\n");
    }
  }

  pair<int, int> furthest = {0, 0};
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (dist[i][j] > dist[furthest.first][furthest.second]) {
      furthest = make_pair(i, j);
    }
  }

  for (int i = 0; i < m; ++i) {
    if (dist[furthest.first][u[i]] == dist[furthest.first][v[i]]) {
      // Not bipartite
      return 0 * printf("NO\n");
    }
  }

  printf("YES\n%d\n", dist[furthest.first][furthest.second]);
  for (int i = 0; i < n; ++i) printf("%d ", dist[furthest.first][i]);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}