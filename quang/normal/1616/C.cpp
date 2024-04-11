#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  int res = n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }
        cnt += (a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i);
      }
      res = min(res, cnt);
    }
  }
  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}