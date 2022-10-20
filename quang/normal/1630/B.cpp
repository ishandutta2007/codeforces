#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  auto b = a;
  sort(b.begin(), b.end());
  pair<int, int> res(n, 1);
  int need = (n + k + 1) / 2;
  for (int i = 0; i + need - 1 < n; i++) {
    int sz = b[i + need - 1] - b[i] + 1;
    if (sz < res.first) {
      res = {sz, b[i]};
    }
  }
  int l = res.second, r = res.second + res.first - 1;
  cout << l << ' ' << r << '\n';
  int now = 0;
  for (int i = 0; i < k - 1; i++) {
    int cur = 0;
    int nxt = now;
    while (cur != 1) {
      cur += (l <= a[nxt] && a[nxt] <= r) * 2 - 1;
      nxt++;
    }
    cout << now + 1 << ' ' << nxt << '\n';
    now = nxt;
  }
  cout << now + 1 << ' ' << n << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}