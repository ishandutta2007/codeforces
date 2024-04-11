#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const long long INFLL = 1e18;

int n, m, k;
vector<pair<int, int>> edges[N];

long long dist[N][4];

void dijkstra() {
  priority_queue<tuple<long long, int, int>> pq;
  pq.emplace(0LL, 0, 0);

  for (int i = 0; i < n; ++i) dist[i][0] = dist[i][1] = dist[i][2] = dist[i][3] = INFLL;
  dist[0][0] = 0;

  while (pq.size()) {
    int u, mask;
    long long d;
    tie(d, u, mask) = pq.top();
    // cerr << u << " " << d << " " << mask << endl;
    pq.pop();
    d = -d;

    if (dist[u][mask] < d) continue;

    for (int i = 0; i < edges[u].size(); ++i) {
      int v = edges[u][i].first;
      int w = edges[u][i].second;

      if (dist[v][mask] > d + w) {
        dist[v][mask] = d + w;
        pq.emplace(-(d + w), v, mask);
      }

      if ((mask & 1) == 0 && dist[v][mask | 1] > d) {
        dist[v][mask | 1] = d;
        pq.emplace(-d, v, mask | 1);
      }

      if ((mask & 2) == 0 && dist[v][mask | 2] > d + w*2) {
        dist[v][mask | 2] = d + w*2;
        pq.emplace(-(d + w*2), v, mask | 2);
      }

      if (mask == 0 && dist[v][3] > d + w) {
        dist[v][3] = d + w;
        pq.emplace(-(d + w), v, 3);
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

  dijkstra();

  for (int i = 1; i < n; ++i) printf("%lld ", dist[i][3]);
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