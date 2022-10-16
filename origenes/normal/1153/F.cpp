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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 2123;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = mul(ret, a);
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

int dp[maxn << 1][maxn], fac[maxn];
int n, k, l;

int main() {
  scanf("%d%d%d", &n, &k, &l);
  int dis = mul(l, pow_mod(2 * n + 1, MOD - 2)), ans = 0;
  fac[0] = 1;
  FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
  dp[0][0] = 1;
  REP(i, 2 * n) ROF(j, min(n, i), 0) {
    dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
    if (j) dp[i + 1][j - 1] = add(dp[i + 1][j - 1], mul(dp[i][j], j));
  }
  FOR(i, 1, 2 * n) FOR(j, k, n) ans = add(ans, mul(mul(dp[i][j], dp[2 * n - i][j]), fac[j]));
  ans = mul(ans, mul(dis, pow_mod(dp[2 * n][0], MOD - 2)));
  printf("%d", ans);
}