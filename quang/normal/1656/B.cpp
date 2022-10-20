#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n, k;
  cin >> n >> k;
  set<int> s;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    if (s.count(u + k) || s.count(u - k)) {
      ok = true;
    }
    s.insert(u);
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}