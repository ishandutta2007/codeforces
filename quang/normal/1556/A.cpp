#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int c, d;
  cin >> c >> d;
  if ((c + d) % 2) {
    cout << -1 << '\n';
    return;
  }
  if (c == 0 && d == 0) {
    cout << 0 << '\n';
    return;
  }
  if (c == d) cout << 1 << '\n';
  else cout << 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}