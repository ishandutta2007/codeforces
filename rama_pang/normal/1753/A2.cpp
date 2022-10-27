#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint n;
  cin >> n;
  lint total = 0;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  if (total % 2 != 0) {
    cout << -1 << '\n';
    return;
  }
  lint target = total / 2;
  vector<lint> dpmax(n);
  vector<lint> dpmin(n);
  for (int i = 1; i < n; i++) {
    dpmax[i] = max(dpmax[i - 1], a[i] + (i == 1 ? 0 : dpmax[i - 2]));
    dpmin[i] = min(dpmin[i - 1], a[i] + (i == 1 ? 0 : dpmin[i - 2]));
  }
  vector<pair<int, int>> ans;
  if (dpmin[n - 1] <= target && target <= dpmax[n - 1]) {
    for (int i = n - 1; i >= 0; i--) {
      if (i == 0) {
        ans.emplace_back(i, i);
        continue;
      }
      lint lo = (i == 1 ? a[i] : (dpmin[i - 2] + a[i]));
      lint hi = (i == 1 ? a[i] : (dpmax[i - 2] + a[i]));
      if (lo <= target && target <= hi) {
        target -= a[i];
        ans.emplace_back(i - 1, i);
        i--;
      } else {
        ans.emplace_back(i, i);
      }
    }
  } else {
    cout << "-1\n";
    return;
  }
  assert(target == 0);
  sort(begin(ans), end(ans));
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