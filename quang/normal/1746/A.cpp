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
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  if (*max_element(a.begin(), a.end()) == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}