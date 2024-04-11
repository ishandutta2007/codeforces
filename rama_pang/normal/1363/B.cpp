#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    int ans = n;
    for (int z = 0; z <= n; z++) {
      int cur = 0;
      for (int i = 0; i < z; i++) {
        if (s[i] == '1') cur++;
      }
      for (int i = z; i < n; i++) {
        if (s[i] == '0') cur++;
      }
      ans = min(ans, cur);
    }
    for (int z = 0; z <= n; z++) {
      int cur = 0;
      for (int i = 0; i < z; i++) {
        if (s[i] == '0') cur++;
      }
      for (int i = z; i < n; i++) {
        if (s[i] == '1') cur++;
      }
      ans = min(ans, cur);
    }
    cout << ans << "\n";
  }
}