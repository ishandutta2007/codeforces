#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  lint ans = 1e18;
  vector<pair<int, int>> a(n);
  vector<vector<int>> ls(m);

  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].first--;
    ls[a[i].first].emplace_back(a[i].second);
  }

  for (int i = 0; i < m; i++) {
    sort(begin(ls[i]), end(ls[i]));
  }

  for (int vote = 1; vote <= n; vote++) {
    vector<int> coins;
    int cur = ls[0].size();
    lint cost = 0;
    for (int i = 1; i < m; i++) {
      int take = int(ls[i].size()) - vote + 1;
      for (int j = 0; j < take; j++) {
        cur++;
        cost += ls[i][j];
      }
      for (int j = max(take, 0); j < ls[i].size(); j++) {
        coins.emplace_back(ls[i][j]);
      }
    }
    int need = max(0, vote - cur);
    if (need > 0) {
      nth_element(begin(coins), begin(coins) + need - 1, end(coins));
      for (int i = 0; i < need; i++) {
        cost += coins[i];
      }      
    }

    ans = min(ans, cost);
  }

  cout << ans << "\n";
  return 0;
}