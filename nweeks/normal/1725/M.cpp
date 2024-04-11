#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5;
const int INF = 1e18;
vector<pair<int, int>> G[MAXN], RG[MAXN];

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    G[u].emplace_back(v, c);
    RG[v].emplace_back(u, c);
  }

  vector<int> dis(N, INF);
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, 0);
  dis[0] = 0;
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    d = -d;
    if (d > dis[u])
      continue;
    for (auto [v, c] : G[u])
      if (d + c < dis[v]) {
        dis[v] = d + c;
        pq.emplace(-dis[v], v);
      }
  }
  vector<int> dis2(N, INF);
  for (int i = 0; i < N; ++i)
    if (dis[i] < INF) {
      dis2[i] = dis[i];
      pq.emplace(-dis2[i], i);
    }
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    d = -d;
    if (d > dis2[u])
      continue;
    for (auto [v, c] : RG[u])
      if (d + c < dis2[v]) {
        dis2[v] = d + c;
        pq.emplace(-dis2[v], v);
      }
  }
  for (int u = 1; u < N; ++u) {
    cout << (dis2[u] == INF ? -1 : dis2[u]) << ' ';
  }
  cout << endl;
}