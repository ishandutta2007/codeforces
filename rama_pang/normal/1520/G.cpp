#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, m, w;
  cin >> n >> m >> w;
  vector<int> a(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i * m + j];
    }
  }

  const long long INF = 1e18;

  const auto Bfs = [&](int s) {
    vector<long long> dist(n * m, INF);
    queue<int> q;

    const auto Relax = [&](int v, long long d) {
      if (dist[v] == INF && a[v] != -1) {
        dist[v] = d;
        q.emplace(v);
      }
    };

    q.emplace(s);
    dist[s] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int x = u / m, y = u % m;
      if (x > 0) Relax((x - 1) * m + y, dist[u] + w);
      if (x + 1 < n) Relax((x + 1) * m + y, dist[u] + w);
      if (y > 0) Relax(x * m + y - 1, dist[u] + w);
      if (y + 1 < m) Relax(x * m + y + 1, dist[u] + w); 
    }

    return dist;
  };

  auto distS = Bfs(0);
  auto distT = Bfs(n * m - 1);

  long long ans = distS[n * m - 1];
  
  long long toPortalS = INF;
  long long toPortalT = INF;
  for (int i = 0; i < n * m; i++) {
    if (a[i] > 0) {
      toPortalS = min(toPortalS, distS[i] + a[i]);
      toPortalT = min(toPortalT, distT[i] + a[i]);
    }
  }

  ans = min(ans, toPortalS + toPortalT);

  if (ans == INF) ans = -1;
  cout << ans << '\n';
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