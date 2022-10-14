#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (j + 1 < n && ((a[i] < 0 && a[j + 1] < 0) || (a[i] > 0 && a[j + 1] > 0))) {
        j++;
      }
      int mx = -1e9;
      for (int k = i; k <= j; k++) {
        mx = max(mx, a[k]);
      }
      ans += mx;
      i = j;
    }
    cout << ans << "\n";
  }
  return 0;
}