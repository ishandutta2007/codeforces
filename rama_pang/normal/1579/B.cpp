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
  vector<array<int, 3>> ans;
  const auto Shift = [&](int l, int r, int d) {
    if (l < r && d > 0) {
      ans.push_back({l, r, d});
      vector<int> b = a;
      for (int i = 0; i <= r - l; i++) {
        a[i + l] = b[l + (i + d + (r - l + 1)) % (r - l + 1)];
      }
    }
  };
  for (int r = 0; r < n - 1; r++) {
    pair<int, int> mn = {2e9, -1};
    for (int i = r; i < n; i++) {
      mn = min(mn, {a[i], i});
    }
    Shift(r, mn.second, mn.second - r);
  }
  cout << ans.size() << '\n';
  for (auto [l, r, d] : ans) {
    cout << l + 1 << ' ' << r  + 1 << ' ' << d << '\n';
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