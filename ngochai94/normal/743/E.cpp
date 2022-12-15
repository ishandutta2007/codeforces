#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1000003

int n, lis[1111], dp[1111][1 << 8];

int solve(int x) {
  REP (i, 1010) FOR (j, 1, (1 << 8) - 1) dp[i][j] = -mod;
  // BUG(dp[2][0]);
  if (!x) {
    int cntt[8];
    reset(cntt, 0);
    FOR (i, 1, n) cntt[lis[i]] = 1;
    int ans = 0;
    REP (i, 8) ans += cntt[i];
    return ans;
  }

  FOR (i, 1, n) REP (mask, (1 << 8)) REP (las, 8) if ((1 << las) & mask) {
    int p = i;
    int cnt = 0;
    // if (i == 18 && mask == 255 && las == 0) BUG(p);
    while (p) {
      if (lis[p] == las) cnt++;
      if (cnt == x) break;
      p--;
    }
    // if (i == 18 && mask == 255 && las == 0) BUG(p);
    if (p) {
      dp[i][mask] = max(dp[i][mask], x + dp[p - 1][mask ^ (1 << las)]);
      // if (i == 18 && mask == 255 && las == 0) BUG(p);
      p--;

      while (p) {
        if (lis[p] == las) break;
        p--;
      }
      // if (i == 18 && mask == 255 && las == 0) BUG(x + 1 + dp[p - 1][mask ^ (1 << las)]);
      if (p) dp[i][mask] = max(dp[i][mask], x + 1 + dp[p - 1][mask ^ (1 << las)]);
      // if (i == 18 && mask == 255 && las == 0) BUG(dp[18][255]);
    }
    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
    // BUG(dp[18][255]);
  }
  // BUG(dp[18][255]);
  return max(0, dp[n][(1 << 8) - 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  FOR (i, 1, n) {
    cin >> lis[i];
    lis[i]--;
  }
  // cout << solve(1) << endl; 
  // BUG(dp[18][255]);
  // return 0;
  int high = n / 8+ 3;
  int low = 0;
  int ans = 0;
  while (low < high) {
    int chs = (high + low) / 2;
    int tmp = solve(chs);
    ans = max(ans, tmp);
    // cout << chs << ' ' << tmp << endl;
    if (tmp) low = chs + 1;
    else high = chs;
  }
  cout << ans;
}