#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n, k;
  cin >> n >> k;
  if ((n + 1) / 2 < k) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j && i % 2 == 0 && i / 2 < k) {
        cout << 'R';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}