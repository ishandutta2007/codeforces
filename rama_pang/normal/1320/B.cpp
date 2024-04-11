#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> adj[n]; // transpose graph
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[v].emplace_back(u);
  }

  int k;
  cin >> k;
  vector<int> path(k);
  for (auto &i : path) {
    cin >> i;
    i--;
  }

  vector<int> twoReachable(n);
  vector<int> dist(n, -1);

  queue<int> q;
  q.emplace(path.back());
  dist[path.back()] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.emplace(v);
      } else if (dist[v] == dist[u] + 1) {
        twoReachable[v] = 1;
      }
    }
  }

  int ansMin = 0, ansMax = 0;
  for (int i = 0; i + 1 < k; i++) {
    if (dist[path[i]] - 1 != dist[path[i + 1]]) {
      ansMin++;
      ansMax++;
    } else {
      if (twoReachable[path[i]] == 1) {
        ansMax++;
      }
    }
  }

  cout << ansMin << " " << ansMax << "\n";
  return 0;

}