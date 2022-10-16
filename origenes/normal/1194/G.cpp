#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 112;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, ans, dp[maxn][2][20][1 << 4][1 << 4], xx, yy;
char s[maxn];

int dfs(int pos, bool small, int rem, int mask1, int mask2) {
  if (pos > n) return !rem && (mask1 & mask2);
  int &ret = dp[pos][small][rem][mask1][mask2];
  if (ret != -1) return ret;
  ret = 0;
  REP(x, 10) REP(y, small ? 10 : s[pos] + 1) {
    int nrem = rem * 10 - yy * x + xx * y, nmask1 = 0, nmask2 = 0;
    if (nrem <= -xx || nrem >= yy) continue;
    if (x && x % xx == 0 && x <= 9 / yy * xx) nmask1 = 1 << x / xx - 1;
    if (y && y % yy == 0) nmask2 = 1 << y / yy - 1;
    ret = add(ret, dfs(pos + 1, small | (y < s[pos]), nrem, mask1 | nmask1, mask2 | nmask2));
  }
  return ret;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n) {
    s[i] -= '0';
    ans = add(mul(ans, 10), s[i]);
  }
  FOR(x, 1, 9) FOR(y, x + 1, 9) if (__gcd(x, y) == 1) {
    reset(dp, -1);
    xx = x, yy = y;
    ans = add(ans, mul(dfs(1, false, 0, 0, 0), 2));
  }
  printf("%d", ans);
}