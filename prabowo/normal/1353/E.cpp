#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, k;
char s[N];

int dp[N][2];

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  int sum = 0;
  for (int i = 0; i < n; ++i) sum += (s[i] == '1');

  int ans = n;
  int pre = 0;
  for (int i = 0; i < n; ++i) {
    sum -= (s[i] == '1');
    dp[i][0] = (s[i] != '0') + pre + (i < k ? 0 : dp[i-k][0]);
    dp[i][1] = (s[i] != '1') + pre + (i < k ? 0 : min(dp[i-k][0], dp[i-k][1]));
    pre += (s[i] == '1');
    if (i >= k-1) pre -= (s[i-k+1] == '1');
    // cerr << dp[i][0] << " " << dp[i][1] << endl;
    ans = min(ans, sum + min(dp[i][0], dp[i][1]));
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}