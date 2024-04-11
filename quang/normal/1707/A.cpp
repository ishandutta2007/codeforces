#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<bool> res(n);
  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= cur) {
      res[i] = 1;
    } else {
      if (cur < q) {
        cur++;
        res[i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (int)res[i];
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