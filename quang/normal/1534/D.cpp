#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  auto Ask = [&](int u) {
    vector<int> res(n + 1);
    cout << "? " << u << endl;
    for (int i = 1; i <= n; i++) {
      cin >> res[i];
    }
    return res;
  };

  set<pair<int, int>> edges;

  auto AddEdge = [&](int u, int v) {
    if (u > v) swap(u, v);
    edges.insert({u, v});
  };

  auto d = Ask(1);
  vector<int> a[2];
  for (int i = 2; i <= n; i++) {
    if (d[i] == 1) {
      AddEdge(1, i);
    }
    a[d[i] % 2].push_back(i);
  }
  if (a[0].size() > a[1].size()) a[0].swap(a[1]);
  for (auto u : a[0]) {
    auto d = Ask(u);
    for (int i = 1; i <= n; i++) {
      if (d[i] == 1) {
        AddEdge(u, i);
      }
    }
  }
  cout << "!\n";
  for (auto [u, v] : edges) {
    cout << u << ' ' << v << '\n';
  }
  cout.flush();
  return 0;
}