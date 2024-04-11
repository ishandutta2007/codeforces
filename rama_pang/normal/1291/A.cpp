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
    string s, t;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if ((s[i] - '0') % 2 == 0) {
        continue;
      }
      t.push_back(s[i]);
      if (t.size() == 2) {
        break;
      }
    }
    if (t.size() < 2) {
      cout << -1 << "\n";
    } else {
      cout << t << "\n";
    }
  }  
  return 0;
}