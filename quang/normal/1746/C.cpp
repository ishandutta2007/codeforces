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
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i] - 1] = i;
  }
  for (int i = 0; i < n; i++) {
    cout << pos[n - i - 1] + 1 << ' ';
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