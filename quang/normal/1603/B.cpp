#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int x, y;
  cin >> x >> y;
  if (y < x) {
    cout << (x + y) << '\n';
  } else {
    auto z = y % x;
    cout << y - z / 2 << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}