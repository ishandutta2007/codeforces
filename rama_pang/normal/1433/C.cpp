#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = a[n + 1] = 1e9;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      if (mx == a[i]) {
        if (a[i] > a[i - 1] || a[i] > a[i + 1]) {
          ans = i;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0; 
}