#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (auto &i : s) {
      if (i == 'L') {
        cnt++;
      } else {
        cnt = 0;
      }
      ans = max(ans, cnt);
    }
    cout << (ans + 1) << "\n";
  }
}