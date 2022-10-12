#include <bits/stdc++.h>
using namespace std;

int d, m;
int msb;

int dp[31];
int dfs(int x) {
  if (x < 0) return 1;
  if (~dp[x]) return dp[x];

  int bit = (d >> x & 1);
  int ret = dfs(x-1);
  ret = (1LL * (x == msb ? (d & ((1 << x) - 1)) + 1 : (1 << x)) * dfs(x-1) + ret) % m;

  // cerr << x << " " << lim << " " << ret << endl;
  return dp[x] = ret % m;
}

int solve() {
  scanf("%d %d", &d, &m);
  memset(dp, -1, sizeof dp);
  msb = 31 - __builtin_clz(d);
  int ans = (dfs(msb) + m - 1) % m;
  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}