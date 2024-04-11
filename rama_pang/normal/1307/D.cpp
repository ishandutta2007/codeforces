#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 200005;

int N, M, K;
int spec[MAXN];
vector<int> adj[MAXN];
int dist[2][MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int a;
    cin >> a;
    spec[a] = 1;
  }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  memset(dist, -1, sizeof(dist));

  for (int k = 0; k < 2; k++) {
    queue<int> q;
    if (k == 0) {
      q.emplace(1);
    } else {
      q.emplace(N);
    }
    dist[k][q.front()] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : adj[u]) {
        if (dist[k][v] == -1) {
          dist[k][v] = dist[k][u] + 1;
          q.emplace(v);
        }
      }
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   cout << dist[0][i] << " \n"[i == N];
  // }

  int ans = dist[0][N];

  int mx = 0;
  vector<pair<int, int>> dt;
  for (int i = 1; i <= N; i++) {
    if (spec[i]) {
      dt.emplace_back(dist[0][i], i);
    }
  }
  sort(begin(dt), end(dt));
  for (int i = 1; i < dt.size(); i++) {
    int u = dt[i].second;
    int v = dt[i - 1].second;
    mx = max(mx, min(dist[0][u] + dist[1][v], dist[0][v] + dist[1][u]) + 1);
  }
  
  // cout << mx << "\n";
  // if (mx < 1e8) {
  //   ans = min(ans, ans - mx);
  // }
  ans = min(ans, mx);
  cout << ans << "\n";

}