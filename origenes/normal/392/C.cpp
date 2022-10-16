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

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
  int n = A.size();
  vector<vector<int>> ret(n, vector<int>(n));
  REP(i, n) REP(j, n) REP(k, n) ret[i][j] = modular_arithmetic::add(ret[i][j], modular_arithmetic::mul(A[i][k], B[k][j]));
  return ret;
}

vector<vector<int>> pow_mod(vector<vector<int>> &A, ll pw) {
  int n = A.size();
  vector<vector<int>> ret(n, vector<int>(n));
  REP(i, n) ret[i][i] = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, A);
    A = mul(A, A);
    pw >>= 1;
  }
  return ret;
}

int main() {
  modular_arithmetic::set(1e9 + 7);
  modular_arithmetic::get_fac(45);
  ll n;
  int k;
  scanf("%lld%d", &n, &k);
  if (n == 1) {
    puts("1");
    return 0;
  }
  vector<vector<int>> A(2 * k + 3, vector<int>(2 * k + 3));
  A[0][0] = A[0][k + 1] = 1;
  REP(i, k + 1) REP(j, i + 1) {
    A[i + 1][j + 1] = modular_arithmetic::C(i, j);
    A[i + 1][j + k + 2] = modular_arithmetic::mul(modular_arithmetic::pow_mod(2, i - j), modular_arithmetic::C(i, j));
  }
  FOR(i, k + 2, 2 * k + 2) A[i][i - k - 1] = 1;
  A = pow_mod(A, n - 2);
  vector<int> x(2 * k + 3, 1);
  REP(i, k + 2) x[i] = modular_arithmetic::pow_mod(2, i);
  int ans = 0;
  REP(i, 2 * k + 3) ans = modular_arithmetic::add(ans, modular_arithmetic::mul(A[0][i], x[i]));
  REP(i, 2 * k + 3) ans = modular_arithmetic::add(ans, modular_arithmetic::mul(A[k + 1][i], x[i]));
  printf("%d", ans);
}