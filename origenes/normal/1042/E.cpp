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

const int maxn = 1123;
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

int n, m, R, C;
int a[maxn][maxn], e[maxn * maxn], r[maxn * maxn], r2[maxn * maxn], c[maxn * maxn], c2[maxn * maxn];
int es, rs, r2s, cs, c2s;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  scanf("%d%d", &R, &C);
  vector<pair<int, pii>> tab(n * m + 1);
  FOR(i, 1, n) FOR(j, 1, m) tab[(i - 1) * m + j] = {a[i][j], mp(i, j)};
  sort(all(tab));
  int pre = 0;
  FOR(i, 1, n * m) {
    int v = tab[i]._1, x = tab[i]._2._1, y = tab[i]._2._2;
    if (v != tab[i - 1]._1) {
      FOR(j, pre, i - 1) {
        es = add(es, e[j]);
        rs = add(rs, r[j]);
        r2s = add(r2s, r2[j]);
        cs = add(cs, c[j]);
        c2s = add(c2s, c2[j]);
      }
      pre = i;
    }
    r[i] = x, c[i] = y;
    r2[i] = mul(x, x), c2[i] = mul(y, y);
    if (v == tab[1]._1) continue;
    e[i] = add(add(es, r2s), c2s);
    e[i] = add(add(e[i], MOD - mul(2 * x, rs)), MOD - mul(2 * y, cs));
    e[i] = add(mul(e[i], pow_mod(pre - 1, MOD - 2)), add(r2[i], c2[i]));
  }
  FOR(i, 1, n * m) if (tab[i]._2 == mp(R, C)) {
    printf("%d", e[i]);
    return 0;
  }
}