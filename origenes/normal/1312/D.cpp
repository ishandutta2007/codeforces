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

const int maxn = 212345;
const int MOD = 998244353;

int n, m;
int fac[maxn], ifac[maxn];

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

int C(int a, int b) {
  if (b < 0 || b > a) return 0;
  return mul(fac[a], mul(ifac[b], ifac[a - b]));
}

int main() {
  scanf("%d%d", &n, &m);
  fac[0] = ifac[0] = 1;
  FOR(i, 1, m) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
  }
  int ans = 0;
  FOR(L, 1, n - 2) ans = add(ans, C(n - 3, L - 1));
  ans = mul(ans, mul(C(m, n - 1), n - 2));
  printf("%d", ans);
}