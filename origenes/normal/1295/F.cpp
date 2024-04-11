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

const int maxn = 55;

int n, L[maxn], R[maxn];
int f[maxn][maxn * 2], l[maxn], r[maxn], len[maxn * 2], g[maxn * 2][maxn];
bool good[maxn][maxn][maxn * 2];

int main() {
  modular_arithmetic::set(998244353);
  scanf("%d", &n);
  vector<int> lis;
  FOR(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    L[i] = l[i], R[i] = r[i];
    r[i]++;
    lis.eb(l[i]); lis.eb(r[i]);
  }
  sort(all(lis)); uni(lis);
  {
    map<int, int> tmp;
    REP(i, int(lis.size())) tmp[lis[i]] = i;
    FOR(i, 1, n) l[i] = tmp[l[i]], r[i] = tmp[r[i]] - 1;
  }
  int m = int(lis.size()) - 1;
  REP(i, m) len[i] = lis[i + 1] - lis[i];
  REP(i, m) FOR(j, 1, n) {
    g[i][j] = 1;
    int st = (len[i] + j - 1), k = 0;
    while (k < j) {
      g[i][j] = modular_arithmetic::mul(g[i][j], st);
      k++, st--;
      g[i][j] = modular_arithmetic::mul(g[i][j], modular_arithmetic::inv(k));
    }
  }
  FOR(i, 1, n) FOR(j, i, n) REP(k, m) {
    if (j == i) good[i][j][k] = l[i] <= k && k <= r[i];
    else good[i][j][k] = good[i][j - 1][k] && (l[j] <= k && k <= r[j]);
  }
  f[0][m] = 1;
  REP(i, n) ROF(j, m, 1) FOR(ni, i + 1, n) ROF(nj, j - 1, 0) if (good[i + 1][ni][nj])
    f[ni][nj] = modular_arithmetic::add(f[ni][nj], modular_arithmetic::mul(f[i][j], g[nj][ni - i]));
  int ans = 0;
  REP(j, m) ans = modular_arithmetic::add(ans, f[n][j]);
  FOR(i, 1, n) ans = modular_arithmetic::mul(ans, modular_arithmetic::inv(R[i] - L[i] + 1));
  printf("%d", ans);
}