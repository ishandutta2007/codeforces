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
using namespace modular_arithmetic;

const int maxn = 1123456;

inline int lowbit(int x) {
  return x & -x;
}

int n;
int fen[maxn], p[maxn], pre[maxn], f[maxn], rk[maxn];

void update(int x, int v) {
  while (x <= n) {
    fen[x] += v;
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  modular_arithmetic::set(1e9 + 7);
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", p + i);
  get_fac(n);
  FOR(i, 2, n) f[i] = add(mul(f[i - 1], i), mul(fac[i - 1], mul(mul(i - 1, i), ifac[2])));
  ROF(i, n, 1) {
    rk[i] = query(p[i]) + 1;
    update(p[i], 1);
  }
  FOR(i, 1, n) pre[i] = add(pre[i - 1], rk[i] - 1);
  int ans = 0;
  FOR(i, 1, n) {
    ans = add(ans, mul(f[n - i], rk[i] - 1));
    ans = add(ans, mul(mul(pre[i - 1], fac[n - i]), rk[i] - 1));
    ans = add(ans, mul(fac[n - i], mul(mul(rk[i] - 1, rk[i] - 2), ifac[2])));
  }
  ans = add(ans, pre[n]);
  printf("%d", ans);
}