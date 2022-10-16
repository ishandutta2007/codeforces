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

const int maxn = 312345;
const int maxm = 20;
const int MOD = 998244353;

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

int n, m;
int l[maxn], r[maxn], a[maxm], b[maxm], f[45][maxn], pre[maxn];
int fac[maxn], ifac[maxn];

inline int C(int n, int m) {
  if (m < 0 || m > n) return 0;
  return mul(fac[n], mul(ifac[m], ifac[n - m]));
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d%d", l + i, r + i);
    pre[l[i]]++;
    pre[r[i] + 1]--;
  }
  FOR(i, 1, n) pre[i] = pre[i - 1] + pre[i];
  REP(i, m) scanf("%d%d", a + i, b + i);
  fac[0] = ifac[0] = 1;
  FOR(i, 1, n) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
  }
  REP(i, 2 * m + 1) FOR(j, 1, n) f[i][j] = add(f[i][j - 1], C(pre[j] - i, j - i));
  int ans = 0;
  REP(mask, 1 << m) {
    vector<int> have;
    bool neg = __builtin_popcount(mask) & 1;
    REP(i, m) if (mask & (1 << i)) {
      have.eb(a[i]);
      have.eb(b[i]);
    }
    sort(all(have)); uni(have);
    int L = 1, R = n;
    for (auto u : have) {
      chkmax(L, l[u]);
      chkmin(R, r[u]);
    }
    if (L > R) continue;
    int now = add(f[have.size()][R], MOD - f[have.size()][L - 1]);
    if (neg) now = MOD - now;
    ans = add(ans, now);
  }
  printf("%d", ans);
}