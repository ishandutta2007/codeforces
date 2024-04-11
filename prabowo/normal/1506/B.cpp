#include <bits/stdc++.h>
using namespace std;
 
const int N = 55;

int n, k;
char s[N];

int frst, lst;
int dp[N][N];
int f(int x, int lft) {
  if (x - lft > k) return 1000;
  if (x == lst) return 1;
  if (~dp[x][lft]) return dp[x][lft];
  int ret = f(x + 1, lft);
  if (s[x] == '*') ret = min(ret, 1 + f(x + 1, x));
  return dp[x][lft] = ret;
}

int solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);

  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      frst = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '*') {
      lst = i;
      break;
    }
  }

  if (frst == lst) return 0 * printf("1\n");

  memset(dp, -1, sizeof dp);
  int ans = f(frst, frst) + 1;
  printf("%d\n", ans);
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