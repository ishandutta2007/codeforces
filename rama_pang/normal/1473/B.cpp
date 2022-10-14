#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    string cur;
    string ans = "-1";
    for (int rep = 0; rep < 30; rep++) {
      for (auto i : s) cur.push_back(i);
      if (cur.size() % t.size() != 0) {
        continue;
      }
      bool can = true;
      for (int i = 0; i < (int) cur.size(); i++) {
        if (cur[i] != t[i % t.size()]) {
          can = false;
          break;
        }
      }
      if (can) {
        ans = cur;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}