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

int n, ans;
int l[maxn], r[maxn], isz[maxn], diff[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", l + i);
  FOR(i, 1, n) scanf("%d", r + i);
  FOR(i, 1, n + 1) isz[i] = pow_mod(r[i] - l[i] + 1, MOD - 2);
  FOR(i, 1, n) {
    int L = max(l[i], l[i + 1]), R = min(r[i], r[i + 1]);
    if (L <= R) diff[i] = mul(mul(R - L + 1, isz[i]), isz[i + 1]);
    diff[i] = add(1, MOD - diff[i]);
    ans = add(ans, diff[i]);
  }
  ans = mul(ans, ans);
  FOR(i, 1, n) ans = add(add(ans, diff[i]), MOD - mul(diff[i], diff[i]));
  FOR(i, 1, n - 1) {
    ans = add(ans, MOD - mul(2 * diff[i], diff[i + 1]));
    int d = add(add(diff[i], diff[i + 1]), MOD - 1);
    int L = max(max(l[i], l[i + 1]), l[i + 2]), R = min(min(r[i], r[i + 1]), r[i + 2]);
    if (L <= R) d = add(d, mul(mul(R - L + 1, isz[i]), mul(isz[i + 1], isz[i + 2])));
    ans = add(add(ans, d), d);
  }
  printf("%d", ans);
}