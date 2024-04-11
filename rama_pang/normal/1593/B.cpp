#include <bits/stdc++.h>
using namespace std;

void Main() {
  string S;
  cin >> S;
  int ans = 20;
  for (auto s : {"00", "25", "50", "75"}) {
    int ok = 1;
    int x = int(S.size());
    while (ok >= 0 && x >= 0) {
      if (S[x - 1] == s[ok]) {
        ok--;
      }
      x--;
    }
    if (ok == -1) {
      ans = min(ans, int(S.size()) - x - 2);
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