#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }  
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        adj[j].emplace_back(i);
      }
    }
  }
  vector<pair<int, int>> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (adj[i].empty()) {
      continue;
    }
    sort(begin(adj[i]), end(adj[i]), [&](int p, int q) {
      return a[p] < a[q];
    });
    for (auto j : adj[i]) {
      ans.emplace_back(j, i);
      swap(a[j], a[i]);
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}