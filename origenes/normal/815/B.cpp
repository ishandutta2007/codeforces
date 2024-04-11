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

const int maxn = 212345;
const int MOD = 1e9 + 7;

int a[maxn], n, fac[maxn], ifac[maxn];

inline int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}

int inv(int a) {
  int pw = MOD - 2, ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  fac[0] = ifac[0] = 1;
  FOR(i, 1, n) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = inv(fac[i]);
  }
  if (n & 1) {
    FOR(i, 1, n - 1) a[i] = add(a[i], (i & 1) ? a[i + 1] : (MOD - a[i + 1]));
    n--;
  }
  int ans = 0;
  for (int i = 1; i <= n; i += 2) ans = add(ans, mul(C(n / 2 - 1, i / 2), a[i]));
  if (n % 4 == 0)
    for (int i = 2; i <= n; i += 2) ans = add(ans, MOD - mul(C(n / 2 - 1, (i - 1) / 2), a[i]));
  else
    for (int i = 2; i <= n; i += 2) ans = add(ans, mul(C(n / 2 - 1, (i - 1) / 2), a[i]));
  printf("%d", ans);
}