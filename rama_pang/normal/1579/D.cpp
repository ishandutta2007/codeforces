#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  int sum = 0;
  pair<int, int> mx = {-1, -1};
  for (int i = 0; i < n; i++) {
    sum += a[i];
    mx = max(mx, {a[i], i});
  }
  if (mx.first > sum - mx.first) {
    for (int i = 0; i < n; i++) {
      if (i != mx.second) {
        while (a[i] > 0) {
          a[i]--;
          ans.emplace_back(i, mx.second);
        }
      }
    }
  } else {
    if (sum & 1) {
      mx.first--;
      a[mx.second]--;
      sum--;
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
      while (a[i] > 0) {
        b.emplace_back(i);
        a[i]--;
      }
    }
    for (int i = 0; i < int(b.size()) / 2; i++) {
      ans.emplace_back(b[i], b[i + b.size() / 2]);
    }
  }

  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
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