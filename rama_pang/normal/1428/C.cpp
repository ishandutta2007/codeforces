#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  
  string s;
  cin >> s;
  int ans = 0;
  for (auto i : s) {
    if (i == 'B') {
      if (ans > 0) {
        ans--;
      } else {
        ans++;
      }
    } else {
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}