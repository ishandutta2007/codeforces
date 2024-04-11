#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  bool has_0 = 0;
  for (int &u : a) {
    cin >> u;
    u = abs(u);
    has_0 |= (u == 0);
  }
  if (has_0) {
    cout << "YES\n";
    return;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (mask >> i & 1) {
        cur += a[i];
      }
    }
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
      if (mask & mask1) continue;
      int now = 0;
      for (int i = 0; i < n; i++) {
        if (mask1 >> i & 1) {
          now += a[i];
        }
      }
      for (int i = 0; i < n; i++) {
        if ((mask >> i & 1) || (mask1 >> i & 1)) continue;
        if (abs(cur - now) == a[i]) {
          cout << "YES\n";
          return;
        }
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}