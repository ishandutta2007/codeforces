#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int last = -1;
    string ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (last != 1) {
          ans.push_back('1');
        } else {
          ans.push_back('0');
        }
      } else {
        if (last != 2) {
          ans.push_back('1');
        } else {
          ans.push_back('0');
        }
      }
      last = s[i] - '0' + ans.back() - '0';
    }
    cout << ans << '\n';
  }
  return 0;
}