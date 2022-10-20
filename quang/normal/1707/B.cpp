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
  for (auto &u : a) {
    cin >> u;
  }
  map<int, int> x;
  for (auto &u : a) {
    x[u]++;
  }
  for (int i = 0; i + 1 < n; i++) {
    map<int, int> y;
    for (auto it = x.begin(); it != x.end(); it++) {
      if (it->second > 1) {
        y[0] += it->second - 1;
      }
      auto it2 = next(it);
      if (it2 != x.end()) {
        y[it2->first - it->first]++;
      }
    }
    debug(i, y);
    x.swap(y);
  }
  cout << x.begin()->first << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}