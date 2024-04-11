#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 0 << '\n';
    return;
  }
  cout << (min(n, m) == 1 ? 1 : 2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}