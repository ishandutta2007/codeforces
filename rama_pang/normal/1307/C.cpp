#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  lint ans = 0;

  for (int i = 0; i < 26; i++) {
    // lint cnt = 0;
    for (int j = 0; j < 26; j++) {
      lint cnt = 0, sum = 0;
      for (int k = 0; k < s.size(); k++) {
        if (s[k] - 'a' == j) {
          sum += cnt;
        }
        if (s[k] - 'a' == i) {
          cnt++;
        }
      }
      ans = max(ans, sum);
      ans = max(ans, cnt);
    }
  }


  cout << ans << "\n";

}