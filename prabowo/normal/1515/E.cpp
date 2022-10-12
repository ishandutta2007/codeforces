#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
 
int n, MOD;
 
int dp[N][N][3];
int f(int x, int cc, int en) {
  if (x > n) return 0;
  if (x == n) return cc == 0;
  int &ret = dp[x][cc][en];
  if (~ret) return ret;
 
  ret = 0;
 
  // new cc
  if (cc > 0) {
    ret = (1LL * cc * f(x + 1, cc + 1, en) + ret) % MOD;
  }
 
  // no new cc
  if (cc > 0) {
    ret = (1LL * (2*cc - en) * f(x + 1, cc, en) + ret) % MOD;
    ret = (1LL * (2*cc - en) * f(x + 2, cc, en) + ret) % MOD;
    if (en > 0) ret = (1LL * en * f(x + 1, cc, en - 1) + ret) % MOD;
  }
 
  // if (x == 1 && cc == 1 && en == 1) cerr << "adsf " << ret << endl;
 
  // erase cc
  if (cc > 0) {
    if (cc == 1 && en == 2) {
      ret = (f(x + 1, cc - 1, 0) + ret) % MOD;
    } else {
      // ret = (1LL * (cc - en) * f(x + 1, cc - 1, en) + ret) % MOD;
      if (en > 0) ret = (1LL * en * f(x + 1, cc - 1, en - 1) + ret) % MOD;
 
      ret = (2LL * (cc - en) * f(x + 2, cc - 1, en) + ret) % MOD;
      if (en > 0) ret = (1LL * en * f(x + 2, cc - 1, en - 1) + ret) % MOD;
 
      ret = (1LL * (cc - en) * f(x + 3, cc - 1, en) + ret) % MOD;
    }
  }
 
  return ret;
}
 
int solve() {
  scanf("%d %d", &n, &MOD);
 
  memset(dp, -1, sizeof dp);
  // cerr << f(1, 1, 1) << endl;
  // cerr << f(2, 1, 0) << endl;
  // cerr << f(2, 1, 1) << endl;
  printf("%d\n", f(0, 1, 2));
  return 0;
}
 
int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}