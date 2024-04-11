#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  int num = 0;
  for (auto &u : a) {
    cin >> u;
    num += u;
  }
  int res = 0;
  for (int i = 0; i < n - num; i++) {
    res += a[i];
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