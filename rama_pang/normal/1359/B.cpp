#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '.') {
          int k = j;
          while (k + 1 < m && s[k + 1] == '.') {
            k++;
          }
          ans += (k - j + 1) / 2 * y;
          if ((k - j + 1) % 2 == 1) {
            ans += x;
          }
          j = k;
        }
      }
    }
    cout << ans << "\n";
  }
}