#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    sum += u;
  }
  if (sum % n == 0) cout << 0 << '\n';
  else cout << 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}