#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;
  string A, B;
  cin >> A >> B;
  int M = 20;
  vector<vector<int>> adj(M);
  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      if (A[i] > B[i]) {
        cout << -1 << '\n';
        return;
      }
      adj[A[i] - 'a'].push_back(B[i] - 'a');
      adj[B[i] - 'a'].push_back(A[i] - 'a');
    }
  }

  int ans = 0;
  vector<int> vis(M);
  for (int i = 0; i < M; i++) {
    if (adj[i].empty() || vis[i]) continue;
    vector<int> que = {i}; vis[i] = 1;
    for (int j = 0; j < int(que.size()); j++) {
      int u = que[j];
      for (auto v : adj[u]) if (!vis[v]) {
        vis[v] = 1;
        que.emplace_back(v);
      }
    }
    ans += int(que.size()) - 1;
  }

  cout << ans << '\n';
  return;
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