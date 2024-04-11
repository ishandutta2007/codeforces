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

const int maxn = 1123456;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int fac[2 * maxn], ifac[2 * maxn];

inline int C(int n, int m) {
  if (m > n || m < 0) return 0;
  return mul(fac[n], mul(ifac[m], ifac[n - m]));
}

int n;
int dp[maxn], dp2[maxn];

int main() {
  fac[0] = ifac[0] = 1;
  FOR(i, 1, 2e6) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
  }
  scanf("%d", &n);
  ROF(i, n, 1) {
    if (i * 2 > n) dp[i] = dp2[i] = 1;
    FOR(j, 2, n / i) {
      if (dp2[i * j] + 1 > dp2[i]) {
        dp2[i] = dp2[i * j] + 1;
        dp[i] = 0;
      }
      if (dp2[i * j] + 1 == dp2[i]) {
        int tmp1 = n / (i * j), tmp2 = n / i;
        dp[i] = add(dp[i], mul(dp[i * j], mul(fac[tmp2 - tmp1], C(n - tmp1 - 1, tmp2 - tmp1 - 1))));
      }
    }
  }
  printf("%d", dp[1]);
}