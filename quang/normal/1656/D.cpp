#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  long long n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 2 << '\n';
    return;
  }
  long long x = 1;
  while (n % 2 == 0) {
    x *= 2;
    n /= 2;
  }
  if (n == 1) {
    cout << -1 << '\n';
  } else {
    if (x * 2 < n) {
      cout << x * 2 << '\n';
    } else {
      cout << n << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}