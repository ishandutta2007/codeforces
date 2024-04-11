#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    int x;
    cin >> s >> x;
    int n = s.size();
    string ans(n, '-');
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i - x >= 0) {
          ans[i - x] = '0';
        }
        if (i + x < n) {
          ans[i + x] = '0';
        }
      }
    }
    int can = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if ((i - x < 0 || ans[i - x] == '0') && (i + x >= n || ans[i + x] == '0')) {
          can = 0;
        } else {
          if (i - x >= 0 && ans[i - x] == '-') {
            ans[i - x] = '1';
          }
          if (i + x < n && ans[i + x] == '-') {
            ans[i + x] = '1';
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (ans[i] == '-') {
        ans[i] = '0'; 
      }
    }
    if (!can) {
      cout << -1 << "\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}