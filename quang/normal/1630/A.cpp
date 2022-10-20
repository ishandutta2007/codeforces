#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n, k;
  cin >> n >> k;
  if (k < n - 1) {
    vector<pair<int, int>> res;
    vector<bool> used(n, 0);
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      used[i] = used[(n - 1) ^ i] = true;
      res.push_back({i, (n - 1) ^ i});
    }

    auto Get = [&](int u) {
      if (u == 0) return k;
      if (u == k) return 0;
      return u;
    };

    for (auto &u : res) {
      cout << Get(u.first) << ' ' << Get(u.second) << '\n';
    }
    return;
  }
  if (n <= 4) {
    cout << -1 << '\n';
    return;
  }


  vector<pair<int, int>> res;
  vector<bool> used(n, 0);
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    used[i] = used[(n - 1) ^ i] = true;
    res.push_back({i, (n - 1) ^ i});
  }

  auto Get = [&](int u) {
    if (u == 0) return n - 2;
    if (u == n - 2) return 3;
    if (u == 3) return 0;
    return u;
  };

  for (auto &u : res) {
    cout << Get(u.first) << ' ' << Get(u.second) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}