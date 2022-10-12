#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const long long INFLL = 1e18;

int n, m, k;

vector<pair<int, int>> edges[N];

bool vis[N][55];
long long dist[N][55];

void dijkstra(int u) {
  priority_queue<tuple<long long, int, int>> pq;
  pq.emplace(0LL, u, 0);

  for (int i = 0; i < n; ++i) for (int j = 0; j <= 50; ++j) {
    dist[i][j] = INFLL;
  }

  dist[u][0] = 0LL;

  while (pq.size()) {
    int u; long long d; int lw;
    tie(d, u, lw) = pq.top();
    pq.pop();
    d = -d;

    if (dist[u][lw] != d) continue;

    for (int i = 0; i < edges[u].size(); ++i) {
      int v, w;
      tie(v, w) = edges[u][i];

      if (lw == 0) {
        long long nd = d;
        if (dist[v][w] > nd) {
          pq.emplace(-nd, v, w);
          dist[v][w] = nd;
        }
      } else {
        long long nd = d + (w + lw) * (w + lw);
        if (dist[v][0] > nd) {
          pq.emplace(-nd, v, 0);
          dist[v][0] = nd;
        }
      }
    }
  }
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    --u, --v;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
  }

  dijkstra(0);

  for (int i = 0; i < n; ++i) {
    if (dist[i][0] == INFLL) printf("-1 ");
    else printf("%lld ", dist[i][0]);
  }

  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}