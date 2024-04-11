#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

long long dp[N];
long long f(int x) {
  if (x >= n) return 0;
  if (~dp[x]) return dp[x];
  return dp[x] = a[x] + f(x + a[x]);
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    dp[i] = -1;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) ans = max(ans, f(i));

  printf("%lld\n", ans);
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