#include <bits/stdc++.h>
using namespace std;

const int N = 255;

int n, m;
int a[N];

int dp[N][N][N * 2];
int f(int x, int lst, int debt) {
  if (x == n) return debt == 0 ? 0 : 1e9;
  int &ret = dp[x][lst][debt + N];
  if (~ret) return ret;

  ret = 1e9;
  int maxi = min(lst, m / (x + 1));
  for (int i = 0; i <= maxi; ++i) {
    int ndebt = debt + (a[x] - i);
    ret = min(ret, abs(ndebt) + f(x + 1, i, ndebt));
  }

  return ret;
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(0, 250, 0));
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
}