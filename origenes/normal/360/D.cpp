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

const int maxn = 112345;

int n, m, p;

inline int mul(int a, int b) {
  return ll(a) * b % p;
}

int pow_mod(int a, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = mul(ret, a);
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

int a[maxn], b[maxn], q[maxn], f[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  REP(i, n) scanf("%d", a + i);
  REP(i, m) {
    scanf("%d", b + i);
    b[i] %= p;
  }
  int g = p - 1, ans = 0;
  REP(i, m) g = __gcd(g, b[i]);
  vector<int> fac;
  for (int i = 1; i * i <= p - 1; i++) if ((p - 1) % i == 0) {
    fac.eb(i);
    if (i * i != p - 1) fac.eb((p - 1) / i);
  }
  sort(all(fac));
  REP(i, n) {
    a[i] = pow_mod(a[i], g);
    for (auto j : fac) if (pow_mod(a[i], j) == 1) {
      q[i] = (p - 1) / j;
      break;
    }
  }
  sort(q, q + n);
  n = unique(q, q + n) - q;
  ROF(i, int(fac.size()) - 1, 0) {
    bool ok = false;
    REP(j, n) if (fac[i] % q[j] == 0) {
      ok = true;
      FOR(k, i + 1, int(fac.size()) - 1) if (fac[k] % fac[i] == 0) f[i] -= f[k];
      break;
    }
    if (ok) {
      f[i] += (p - 1) / fac[i];
      ans += f[i];
    }
  }
  printf("%d", ans);
}