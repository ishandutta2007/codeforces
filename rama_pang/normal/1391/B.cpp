#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (i + 1 == n && c == 'D') {
          ans++;
        }
        if (j + 1 == m && c == 'R') {
          ans++;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}