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
const int maxn = 5123;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}

int n, m, k;
int f[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  f[0] = 1;
  REP(i, k) {
    vector<int> g(k + 2);
    REP(j, k + 1) {
      g[j + 1] = add(g[j + 1], f[j]);
      g[j] = add(g[j], mul(j, f[j]));
    }
    REP(j, k + 1) f[j] = g[j];
  }
  int ans = 0, now = 1;
  m = pow_mod(m, MOD - 2);
  REP(i, min(n + 1, k + 1)) {
    ans = add(ans, mul(mul(f[i], now), pow_mod(m, i)));
    now = mul(now, n - i);
  }
  printf("%d", ans);
}