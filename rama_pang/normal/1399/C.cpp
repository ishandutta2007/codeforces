#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int w = 0; w <= 2 * n; w++) {
      int cur = 0;
      vector<int> done(n, 0);
      for (int k = 0; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          if (!done[k] && !done[l] && a[k] + a[l] == w) {
            done[k] = done[l] = 1;
            cur++;
          }
        }
      }
      ans = max(ans, cur); 
    }
    cout << ans << "\n";
  }
  return 0;
}