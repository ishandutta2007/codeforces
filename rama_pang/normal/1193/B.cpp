#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n, -1);
  vector<pair<int, int>> a(n);
  vector<map<int, long long>> dif(n);
  for (int i = 1; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < m; i++) {
    int v, d, w;
    cin >> v >> d >> w;
    a[--v] = {d, w};
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].first) {
      dif[i][a[i].first] += a[i].second;
      auto it = dif[i].upper_bound(a[i].first);
      int totaldif = a[i].second;
      while (it != end(dif[i])) {
        if (totaldif >= it->second) {
          totaldif -= it->second;
          auto del = it++;
          dif[i].erase(del);
        } else {
          it->second -= totaldif;
          break;
        }
      }
    }
    if (p[i] != -1) {
      if (dif[p[i]].size() < dif[i].size()) {
        swap(dif[p[i]], dif[i]);
      }
      for (auto j : dif[i]) {
        dif[p[i]][j.first] += j.second;
      }
      dif[i].clear();
    }
  }
  long long ans = 0;
  for (auto i : dif[0]) {
    ans += i.second;
  }
  cout << ans << "\n";
  return 0;
}