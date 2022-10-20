#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    long long cur = a[i];
    long long rest = 0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        int u = a[j];
        while (u % 2 == 0) {
          u /= 2;
          cur *= 2;
        }
        rest += u;
      }
    }
    res = max(res, cur + rest);
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