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
  bool all_one = true;
  bool has_one = false;
  for (int u : a) {
    if (u == 1) has_one = true;
    if (u != 1) all_one = false;
  }
  if (!has_one || all_one) {
    cout << "YES\n";
    return;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] + 1 == a[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}