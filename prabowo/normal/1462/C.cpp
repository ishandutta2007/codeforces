#include <bits/stdc++.h>
using namespace std;
 
const int N = 205;

int n;
char s[N];

int solve() {
  scanf("%d", &n);

  string ans;
  for (int d = 9; d > 0; --d) {
    if (n >= d) {
      n -= d;
      ans += d + '0';
    }
  }
  reverse(ans.begin(), ans.end());

  if (n > 0) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}