#include <bits/stdc++.h>
using namespace std;
using lint = long long;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    lint n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int ans = 0;
    for (lint i = 1; i < n; i++) {
      int diff = a[i - 1] - a[i];
      if (diff <= 0) continue;
      ans = max(ans, 32 - __builtin_clz(diff));
      a[i] = max(a[i], a[i - 1]);
    }
    cout << ans << "\n";
  }


}