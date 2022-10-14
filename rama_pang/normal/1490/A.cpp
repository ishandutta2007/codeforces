#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (max(a[i], a[i + 1]) <= 2 * min(a[i], a[i + 1]))
        continue;
      int mx = max(a[i], a[i + 1]);
      int mn = min(a[i], a[i + 1]);
      while (2 * mn < mx) {
        mn *= 2;
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}