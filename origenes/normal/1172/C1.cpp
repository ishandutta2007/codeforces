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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int MOD = 998244353;
const int maxn = 212345;
const int maxm = 3123;

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

int n, m, s[2], tot;
int a[maxn], w[maxn], inv[maxm * 2], dp[maxm][maxm], dp2[maxm][maxm];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) {
    scanf("%d", w + i);
    s[a[i]] += w[i];
    tot += w[i];
  }
  FOR(i, max(0, m - s[0]), 2 * m) inv[i] = pow_mod((tot + i - m) % MOD, MOD - 2);
  ROF(i, m, 0) {
    dp[i][m - i] = dp2[i][m - i] = 1;
    ROF(j, min(m - i - 1, s[0]), 0) {
      dp[i][j] = add(mul(s[1] + i + 1, dp[i + 1][j]), mul(s[0] - j, dp[i][j + 1]));
      dp2[i][j] = add(mul(s[1] + i, dp2[i + 1][j]), mul(s[0] - j - 1, dp2[i][j + 1]));
      dp[i][j] = mul(dp[i][j], inv[i - j + m]);
      dp2[i][j] = mul(dp2[i][j], inv[i - j + m]);
    }
  }
  FOR(i, 1, n) printf("%d\n", mul(w[i], a[i] ? dp[0][0] : dp2[0][0]));
}