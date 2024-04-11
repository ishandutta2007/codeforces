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
const int MOD = 1e9 + 7;
const int inv2 = 5e8 + 4;

ll t[maxn], T;
int n, pw2[maxn], fac[maxn], ifac[maxn];

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

int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(mul(fac[n], ifac[m]), ifac[n - m]);
}

int main() {
  scanf("%d%lld", &n, &T);
  fac[0] = ifac[0] = pw2[0] = 1;
  FOR(i, 1, n) {
    scanf("%lld", t + i);
    t[i] += t[i - 1];
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
    pw2[i] = mul(pw2[i - 1], inv2);
  }
  t[n + 1] = T + 2;
  int j = n, ans = 0;
  REP(i, n + 1) {
    while (j > 0 && t[j] > T - i) j--;
    if (j == 0) break;
    if (t[j + 1] == T - i + 1) ans = add(ans, mul(mul(j, C(j, i - 1)), pw2[j + 1]));
    ans = add(ans, mul(mul(j, C(j, i)), pw2[j]));
  }
  printf("%d", ans);
}