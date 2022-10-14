#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (max(count(begin(s), end(s), 'L'), count(begin(s), end(s), 'R')) == n) {
      cout << (n + 2) / 3 << "\n";
    } else {
      for (int i = 0; i + 1 < n; i++) {
        if (s[i] != s[i + 1]) {
          rotate(begin(s), begin(s) + i + 1, end(s));
          break;
        }
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && s[i] == s[j + 1]) {
          j++;
        }
        ans += (j - i + 1) / 3;
        i = j;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}