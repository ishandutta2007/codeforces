#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> rblack(N);
  vector<vector<int>> rwhite(N);
  for (int i = 0; i < M; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--, v--;
    if (t == 0) {
      rwhite[v].emplace_back(u);
    } else {
      rblack[v].emplace_back(u);
    }
  }
  const int INF = 1e9;
  vector<int> state(N, 0);
  vector<int> dist(N, -1);
  string ans(N, '-');
  queue<int> q;
  q.emplace(N - 1);
  state[N - 1] = 7;
  dist[N - 1] = 0;
  ans[N - 1] = '0';
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : rblack[u]) {
      state[v] |= 1;
      if (state[v] == 3) {
        state[v] = 7;
        dist[v] = dist[u] + 1;
        q.emplace(v);
        ans[v] = '1';
      }
    }
    for (auto v : rwhite[u]) {
      state[v] |= 2;
      if (state[v] == 3) {
        state[v] = 7;
        dist[v] = dist[u] + 1;
        q.emplace(v);
        ans[v] = '0';
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (ans[i] == '-') {
      if (state[i] == 2) {
        ans[i] = '1';
      } else {
        ans[i] = '0';
      }
    }
  }
  cout << dist[0] << "\n" << ans << "\n";
  return 0;
}