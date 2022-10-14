#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ans(n);
    const auto Solve = [&](const auto &self, int l, int r, int d) {
      if (l > r) return;
      if (l == r) {
        ans[l] = d;
        return;
      }
      pair<int, int> mx = {-1, -1};
      for (int i = l; i <= r; i++) {
        mx = max(mx, {a[i], i});
      }
      ans[mx.second] = d;
      self(self, l, mx.second - 1, d + 1);
      self(self, mx.second + 1, r, d + 1);
    };
    Solve(Solve, 0, n - 1, 0);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}