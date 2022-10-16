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

namespace modular_arithmetic {
  int MOD;
  vector<int> fac, ifac;

  inline void set(int m) { MOD = m; }

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

  int inv(int a) {
    return pow_mod(a, MOD - 2);
  }

  void get_fac(int n) {
    fac.resize(n + 1), ifac.resize(n + 1);
    fac[0] = 1;
    FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
    ifac[n] = inv(fac[n]);
    ROF(i, n - 1, 0) ifac[i] = mul(ifac[i + 1], i + 1);
  }

  int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return mul(fac[n], mul(ifac[m], ifac[n - m]));
  }
}

const int maxn = 1123;
const int maxa = 11234;

int n;
int f[maxn][2 * maxa], a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  modular_arithmetic::MOD = 1e9 + 7;
  FOR(i, 1, n) {
    FOR(j, -1e4 + maxa, 1e4 + maxa) {
      int pre = j - maxa;
      if (pre + a[i] <= 1e4) f[i][j + a[i]] = modular_arithmetic::add(f[i][j + a[i]], f[i - 1][j]);
      if (pre - a[i] >= -1e4) f[i][j - a[i]] = modular_arithmetic::add(f[i][j - a[i]], f[i - 1][j]);
    }
    f[i][maxa + a[i]] = modular_arithmetic::add(f[i][maxa + a[i]], 1);
    f[i][maxa - a[i]] = modular_arithmetic::add(f[i][maxa - a[i]], 1);
  }
  int ans = 0;
  FOR(i, 1, n) ans = modular_arithmetic::add(ans, f[i][maxa]);
  printf("%d", ans);
}