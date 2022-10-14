#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Solve() {
  int n, m, a, b, c;
  cin >> n >> m >> a >> b >> c;
  a--, b--, c--;
  vector<vector<int>> adj(n);

  vector<lint> p(m);
  for (auto &i : p) cin >> i;
  sort(begin(p), end(p));
  for (int i = 1; i < m; i++) p[i] += p[i - 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<vector<int>> dist(3, vector<int>(n, -1));
  {
    for (int s = 0; s < 3; s++) {
      queue<int> q;
      if (s == 0) q.emplace(a);
      if (s == 1) q.emplace(b);
      if (s == 2) q.emplace(c);
      dist[s][q.front()] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) if  (dist[s][v] == -1) {
          dist[s][v] = dist[s][u] + 1;
          q.emplace(v);
        }
      }
    }
  }

  lint ans = 1e18;
  for (int pv = 0; pv < n; pv++) {
    lint cur;
    int cnt = dist[0][pv] + dist[2][pv] + dist[1][pv];
    if (cnt > m) continue;
    cur = (cnt > 0 ? p[cnt - 1] : 0);
    cur += (dist[1][pv] > 0 ? p[dist[1][pv] - 1] : 0);
    ans = min(ans, cur);
  }
  
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    Solve();
  }  
}