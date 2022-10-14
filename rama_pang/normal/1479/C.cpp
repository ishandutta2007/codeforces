#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int L, R;
  cin >> L >> R;

  int origL = L, origR = R;

  int last_edge = L - 1;
  R -= L - 1;

  vector<array<int, 3>> edges;
  const auto AddEdge = [&](int u, int v, int w) {
    edges.push_back({u, v, w});
  };

  // node 30: has paths [0, 0]:
  // node 29: has paths [1, 1]: 
  // - connect to node 30 with weight 1 to make [1, 1]
  // node 28: has paths [1, 2]: 
  // - connect to node 30 with weight 1 to make [1, 1]
  // - connect to node 29 with weight 1 to make [2, 2] 
  // node 27: has paths [1, 4]:
  // - connect to node 30 with weight 1 to make [1, 1]
  // - connect to node 29 with weight 1 to make [2, 2]
  // - connect to node 28 with weight 2 to make [3, 4]
  // node 26: has paths [1, 8]:
  // - connect to node 30 with weight 1 to make [1, 1]
  // - connect to node 29 with weight 1 to make [2, 2]
  // - connect to node 28 with weight 2 to make [3, 4]
  // - connect to node 27 with weight 4 to make [5, 8]
  // and so on.
  //
  // Then, we can get arbitrary [1, X]:

  vector<pair<int, int>> interval(31, {-1, -1});
  interval[30] = {0, 0};
  for (int i = 29;; i--) {
    interval[i] = {1, 1};
    AddEdge(i, 30, 1);
    for (int j = i + 1; j < 30; j++) {
      if (interval[i].second > R) break;
      AddEdge(i, j, interval[i].second);
      interval[i].second += interval[j].second;
    }
    if (interval[i].second > R) {
      interval[i] = {-1, -1};
      break;
    }
  }

  pair<int, int> cur = {1, 1};
  AddEdge(0, 30, 1);
  for (int i = 1; i < 30; i++) {
    if (interval[i].first == -1) continue;
    if (cur.second + interval[i].second <= R) {
      AddEdge(0, i, cur.second);
      cur.second += interval[i].second;
    }
  }

  if (last_edge != 0) {
    AddEdge(30, 31, last_edge);
  }

  int sz = 0;
  for (auto [u, v, w] : edges) {
    sz = max({sz, u, v});
  }

  cout << "YES\n";
  cout << sz + 1 << ' ' << edges.size() << '\n';
  for (auto [u, v, w] : edges) {
    cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
  }
  return 0;
}