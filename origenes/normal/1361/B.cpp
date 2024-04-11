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

const int maxn = 1123456;
const int MOD = 1e9 + 7;
const double eps = 1e-9;

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

inline int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

int n, p;
int k[maxn];

void solve() {
  scanf("%d%d", &n, &p);
  FOR(i, 1, n) scanf("%d", k + i);
  sort(k + 1, k + n + 1, greater<>());
  int ans = 0;
  double have = 0;
  FOR(i, 1, n) {
    if (!ans && dcmp(have) == 0) {
      ans = add(ans, pow_mod(p, k[i]));
      have = 1;
    } else {
      ans = add(ans, MOD - pow_mod(p, k[i]));
      have = have * pow(p, k[i - 1] - k[i]) - 1;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}