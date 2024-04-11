#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;

int n, k;
char s[N];

string dp[N];

string miniChar(char c) {
  char ret = (c + 1 == 'a' + k ? 'a' : (c == 'a' ? 'a' : c - 1));
  string r; r += ret;
  return r;
}

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  dp[0] = "";
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + miniChar(s[i]);
    if (i > 1) {
      string t = dp[i - 1] + s[i];
      swap(t[i - 2], t[i - 1]);
      dp[i] = min(dp[i], t);

      t = dp[i - 2] + miniChar(s[i]) + s[i - 1];
      dp[i] = min(dp[i], t);
    }
    if (i > 2) {
      string t = (dp[i - 2] + s[i]) + s[i - 1];
      swap(t[i - 3], t[i - 2]);
      dp[i] = min(dp[i], t);
    }
  }
  cout << dp[n] << endl;
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