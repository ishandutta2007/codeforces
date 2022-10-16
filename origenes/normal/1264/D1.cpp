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
const int maxn = 2123;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n;
char s[maxn];
int fac[maxn], ifac[maxn], inv[maxn], pw2[maxn];
int qs[maxn], l[maxn], r[maxn], sum[maxn][maxn];

int C(int a, int b) {
  if (b < 0 || b > a) return 0;
  return mul(fac[a], mul(ifac[b], ifac[a - b]));
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  fac[0] = ifac[0] = pw2[0] = fac[1] = ifac[1] = inv[1] = 1;
  pw2[1] = 2;
  FOR(i, 2, n) {
    fac[i] = mul(fac[i - 1], i);
    pw2[i] = mul(pw2[i - 1], 2);
    inv[i] = add(0, MOD - mul(MOD / i, inv[MOD % i]));
    ifac[i] = mul(ifac[i - 1], inv[i]);
  }
  FOR(i, 1, n) {
    qs[i] = qs[i - 1] + (s[i] == '?');
    l[i] = l[i - 1] + (s[i] == '(');
    r[i] = r[i - 1] + (s[i] == ')');
  }
  sum[0][0] = 1;
  FOR(i, 1, n) {
    sum[i][0] = 1;
    FOR(j, 1, n) sum[i][j] = add(sum[i][j - 1], C(i, j));
  }
  int ans = 0;
  FOR(dep, 1, n / 2) FOR(i, 1, n) {
    if (s[i] == ')' || l[i] > dep) continue;
    int wl, wr = 0;
    if (s[i] == '(') {
      int need = dep - l[i];
      wl = C(qs[i], need);
    } else {
      int need = dep - l[i] - 1;
      wl = C(qs[i] - 1, need);
    }
    int need = dep - (r[n] - r[i]), ops = qs[n] - qs[i];
    if (need > 0 && need <= ops) wr = add(pw2[ops], MOD - sum[ops][need - 1]);
    if (need <= 0) wr = pw2[ops];
    ans = add(ans, mul(wl, wr));
  }
  printf("%d", ans);
}