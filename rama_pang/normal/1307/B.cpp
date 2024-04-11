#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint n, x;
    cin >> n >> x;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    lint ans = 1e9;
    for (int i = 0; i < n; i++) {
      if (a[i] == x) {
        ans = min(ans, 1ll);
      }
      if (a[i] > x) {
        ans = min(ans, 2ll);
        continue;
      }
      ans = min(ans, (lint) ceil(1.00 * x / a[i]));
    }
    
    cout << ans << "\n";
  }

}