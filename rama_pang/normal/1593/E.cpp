#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N, K;
  cin >> N >> K;
  K = min(K, N);
  vector<int> deg(N);
  vector<vector<int>> adj(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    deg[u]++;
    deg[v]++;
  }
  vector<int> que;
  for (int i = 0; i < N; i++) {
    if (0 <= deg[i] && deg[i] <= 1) {
      deg[i] = -1;
      que.emplace_back(i);
    }
  }
  int ans = N;
  for (int rep = 0; rep < K; rep++) {
    vector<int> nq;
    ans -= que.size();
    for (auto u : que) {
      for (auto v : adj[u]) {
        deg[v]--;
        if (0 <= deg[v] && deg[v] <= 1) {
          deg[v] = -1;
          nq.emplace_back(v);
        }
      }
    }
    que = nq;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}