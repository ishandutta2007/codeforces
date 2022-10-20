#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n, a, b;
  cin >> n >> a >> b;
  auto x = (n - 1) / 2;
  auto y = (n - 2) / 2;
  bool flip = false;
  if (a < b) {
    swap(a, b);
    flip = true;
  }
  if (a > x || b > y) {
    cout << -1 << '\n';
    return;
  }
  if (a > b + 1) {
    cout << -1 << '\n';
    return;
  }
  vector<int> res(n, -1);
  if (a == b) {
    for (int i = 0; i < a; i++) {
      res[i * 2 + 1] = n - i - 1;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (res[i] == -1) {
        res[i] = cur++;
      }
    }
  } else {
    for (int i = 0; i < a; i++) {
      res[i * 2 + 1] = n - i - 1;
    }
    int cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (res[i] == -1) {
        res[i] = cur++;
      }
    }
  }
  if (flip) {
    for (auto &u : res) {
      u = n - u - 1;
    }
  }
  for (auto &u : res) {
    cout << u + 1 << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}