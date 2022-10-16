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

const int maxn = 1123;
const int MOD = 1e9 + 7;

ll dp[maxn][maxn], a, b, ib;
int n, prob[2];

ll inv(ll a) {
  int pw = MOD - 2;
  ll ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    pw >>= 1;
  }
  return ret;
}

inline ll add(ll a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline ll mul(ll a, ll b) {
  return a * b % MOD;
}

int main() {
  scanf("%d%d%d", &n, &prob[0], &prob[1]);
  a = prob[0] * inv(prob[0] + prob[1]) % MOD, b = prob[1] * inv(prob[0] + prob[1]) % MOD, ib = inv(prob[1]);
  dp[0][1] = 1;
  ll ans = 0;
  REP(i, n) FOR(j, 1, n - i - 1) {
      dp[i][j + 1] = add(dp[i][j + 1], mul(a, dp[i][j]));
      if (i + j < n) dp[i + j][j] = add(dp[i + j][j], mul(b, dp[i][j]));
    }
  REP(i, n) FOR(j, n - i, n) {
      ll now = mul(prob[0], ib);
      now = add(now, i + j);
      ans = add(ans, mul(now, dp[i][j]));
    }
  printf("%lld", ans);
}