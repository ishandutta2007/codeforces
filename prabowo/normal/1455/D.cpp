#include <bits/stdc++.h>
using namespace std;
 
const int N = 501;
 
int n, x;
int a[N];

int dp[N][N][N];
int f(int x, int prv, int lst) {
  if (x == n - 1) return 0;
  if (~dp[x][prv][lst]) return dp[x][prv][lst];

  int ret = N;
  if (x + 1 < n && a[x] <= a[x + 1]) ret = min(ret, f(x+1, a[x], lst));
  if (x + 1 < n && a[x] > lst && prv <= lst && lst <= a[x + 1]) ret = min(ret, 1 + f(x+1, lst, a[x]));
  return dp[x][prv][lst] = ret;
}

int solve() {
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j <= 500; ++j) for (int k = 0; k <= 500; ++k) dp[i][j][k] = -1;
  }
  int ans = f(0, 0, x);
  if (ans == N) ans = -1;
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