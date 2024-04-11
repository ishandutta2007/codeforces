#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint calc(lint x, lint y, lint z) {
  lint a = x - y;
  lint b = x - z;
  lint c = y - z;
  // cout << x << " " << y << " " << z << " calc\n";
  return a * a + b * b + c * c;
}

void solve() {
  int n[3] = {};
  vector<lint> a[3];
  vector<pair<int, int>> all;
  
  for (int i = 0; i < 3; i++) cin >> n[i];
  for (int i = 0; i < 3; i++) {
    a[i].resize(n[i]);
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      all.emplace_back(a[i][j], i);
    }
    sort(begin(a[i]), end(a[i]));
  }
  
  sort(begin(all), end(all));
  vector<array<array<int, 3>, 2>> other(all.size(), {-1, -1, -1});
  array<int, 3> cur = {-1, -1, -1};
  for (int i = 0; i < (int) all.size(); i++) {
    cur[all[i].second] = i;
    other[i][0] = cur;
  }

  cur = {-1, -1, -1};
  for (int i = (int) all.size() - 1; i >= 0; i--) {
    cur[all[i].second] = i;
    other[i][1] = cur;
  }

  lint ans = 8e18;
  for (int i = 0; i < all.size(); i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          if (other[i][a][0] == -1 || other[i][b][1] == -1 || other[i][c][2] == -1) continue;
          ans = min(ans, calc(all[other[i][a][0]].first, all[other[i][b][1]].first, all[other[i][c][2]].first));
        }
      }
    }
  }
  cout << ans << "\n";
  // int p[3] = {0, 0, 0};
  // for (int i = 0; i < 3; i++) {
  //   while (all[p[i]].second != i) p[i]++;
  // }
  // lint ans = 8e18;
  // while (max({p[0], p[1], p[2]}) < all.size()) {
  //   ans = min(ans, calc(all[p[0]].first, all[p[1]].first, all[p[2]].first));
  //   if (p[0] < min(p[1], p[2])) {
  //     p[0]++;
  //     while (p[0] < all.size() && all[p[0]].second != 0) p[0]++;
  //   } else if (p[1] < min(p[0], p[2])) {
  //     p[1]++;
  //     while (p[1] < all.size() && all[p[1]].second != 1) p[1]++;
  //   } else {
  //     p[2]++;
  //     while (p[2] < all.size() && all[p[2]].second != 2) p[2]++;
  //   }
  // }

  // reverse(begin(all), end(all));
  // p[0] = p[1] = p[2] = 0;
  // for (int i = 0; i < 3; i++) {
  //   while (all[p[i]].second != i) p[i]++;
  // }

  // while (max({p[0], p[1], p[2]}) < all.size()) {
  //   ans = min(ans, calc(all[p[0]].first, all[p[1]].first, all[p[2]].first));
  //   if (p[0] < min(p[1], p[2])) {
  //     p[0]++;
  //     while (p[0] < all.size() && all[p[0]].second != 0) p[0]++;
  //   } else if (p[1] < min(p[0], p[2])) {
  //     p[1]++;
  //     while (p[1] < all.size() && all[p[1]].second != 1) p[1]++;
  //   } else {
  //     p[2]++;
  //     while (p[2] < all.size() && all[p[2]].second != 2) p[2]++;
  //   }
  // }
  
  // cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  
  int t;
  cin >> t;
  while (t--) solve();

}