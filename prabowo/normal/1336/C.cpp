#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int MOD = 998244353;

int n, m;
char s[N], t[N];

int dp[N][N];
int f(int x, int y) {
  if (x < 0) return 1;
  if (~dp[x][y]) return dp[x][y];

  int ret = 0;
  if (y >= m || t[y] == s[x]) ret += f(x-1, y+1);
  if (x+y >= m || t[x+y] == s[x]) ret += f(x-1, y);
  return dp[x][y] = ret % MOD;
}

int main() {
  scanf("%s", s);
  scanf("%s", t);

  n = strlen(s); m = strlen(t);
  memset(dp, -1, sizeof dp);

  long long ans = 0;
  for (int i = m-1; i < n; ++i) {
    ans += f(i, 0);
  }

  printf("%lld\n", ans % MOD);
  return 0;
}