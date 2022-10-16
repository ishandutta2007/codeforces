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

const int MOD = 998244353;
const int maxn = 212345;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
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

int fac[maxn], ifac[maxn];

int C(int n, int m) {
  if (m > n || m < 0) return 0;
  return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}

int main() {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);
  if (k >= n) {
    puts("0");
    return 0;
  }
  fac[0] = ifac[0] = 1;
  FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
  FOR(i, 1, n) ifac[i] = pow_mod(fac[i], MOD - 2);
  if (k == 0) {
    printf("%d", fac[n]);
    return 0;
  }
  int ans = 0;
  REP(i, n - k) {
    int now = mul(pow_mod(n - k - i, n), C(n - k, i));
    if (i & 1) now = MOD - now;
    ans = add(ans, now);
  }
  printf("%d", mul(add(ans, ans), C(n, n - k)));
}