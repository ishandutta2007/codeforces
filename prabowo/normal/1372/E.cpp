#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m;
int lft[N][N], rgt[N][N];

int dp[N][N];
int f(int l, int r) {
  if (l > r) return 0;
  if (~dp[l][r]) return dp[l][r];

  int ret = 0;
  for (int j = l; j <= r; ++j) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (lft[i][j] >= l && rgt[i][j] <= r) ++cnt;
    }
    ret = max(ret, cnt*cnt + f(l, j-1) + f(j+1, r));
  }

  return dp[l][r] = ret;
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int l, r;
      scanf("%d %d", &l, &r);
      --l, --r;

      for (int j = l; j <= r; ++j) {
        lft[i][j] = l;
        rgt[i][j] = r;
      }
    }
  }

  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, m-1));
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}