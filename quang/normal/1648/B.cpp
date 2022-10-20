#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n, c;
  cin >> n >> c;
  vector<int> sum(c + 1);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    sum[u] = 1;
  }
  for (int i = 1; i <= c; i++) {
    sum[i] += sum[i - 1];
  }

  auto GetSum = [&](int l, int r) {
    r = min(r, c);
    return sum[r] - (l == 0 ? 0 : sum[l - 1]);
  };

  for (int i = 1; i <= c; i++) {
    if (!GetSum(i, i)) continue;
    int last = i - 1;
    for (int j = 1; j <= c && i * j <= c; j++) {
      if (!GetSum(j, j)) continue;
      int l = i * j;
      int r = i * (j + 1) - 1;

      debug(i, j, last, l, r);
      if (last + 1 < l && GetSum(last + 1, l - 1)) {
        debug(i, j, last, l, r);
        cout << "No\n";
        return;
      }

      last = r;
    }
    if (last < c && GetSum(last + 1, c)) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}