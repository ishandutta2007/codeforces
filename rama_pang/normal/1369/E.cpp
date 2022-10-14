#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  vector<int> need(N);
  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    need[x]++, need[y]++;
    adj[x].emplace_back(i, y);
    adj[y].emplace_back(i, x);
  }
  vector<int> done(M);
  vector<int> vis(N);
  vector<int> ans;
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (need[i] <= W[i]) {
      q.emplace(i);
      vis[i] = 1;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto i : adj[u]) {
      int v = i.second;
      int id = i.first;
      if (done[id]) {
        continue;
      }
      done[id] = 1;
      ans.emplace_back(id);
      need[u]--, need[v]--;
      if (need[v] <= W[v] && !vis[v]) {
        vis[v] = 1;
        q.emplace(v);
      }
    }
  }
  reverse(begin(ans), end(ans));
  if (ans.size() != M) {
    cout << "DEAD\n";
  } else {
    cout << "ALIVE\n";
    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}