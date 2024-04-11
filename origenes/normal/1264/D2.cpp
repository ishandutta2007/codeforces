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
const int maxn = 1123456;

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
int fac[maxn], ifac[maxn], inv[maxn];
int qs[maxn], l[maxn], r[maxn], Q[maxn], Q1[maxn];

int C(int a, int b) {
  if (b < 0 || b > a) return 0;
  return mul(fac[a], mul(ifac[b], ifac[a - b]));
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
  FOR(i, 2, n) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = add(0, MOD - mul(MOD / i, inv[MOD % i]));
    ifac[i] = mul(ifac[i - 1], inv[i]);
  }
  FOR(i, 1, n) {
    qs[i] = qs[i - 1] + (s[i] == '?');
    l[i] = l[i - 1] + (s[i] == '(');
    r[i] = r[i - 1] + (s[i] == ')');
  }
  REP(i, qs[n] + 1) Q[i] = C(qs[n], i);
  REP(i, qs[n]) Q1[i] = C(qs[n] - 1, i);
  ROF(i, qs[n] - 1, 0) Q[i] = add(Q[i], Q[i + 1]);
  ROF(i, qs[n] - 2, 0) Q1[i] = add(Q1[i], Q1[i + 1]);
  int ans = 0;
  FOR(i, 1, n) if (s[i] != ')') {
    int x = l[i] + qs[i] - r[n] + r[i];
    chkmax(x, 0);
    if (s[i] == '(' && x <= qs[n]) ans = add(ans, Q[x]);
    if (s[i] == '?' && x < qs[n]) ans = add(ans, Q1[x]);
  }
  printf("%d", ans);
}