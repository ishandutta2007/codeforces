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

const int maxn = 5123;
const int MOD = 998244353;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int inv(int a) {
  int ret = 1, pw = MOD - 2;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

int n, ans;
int a[maxn], dp[maxn][maxn], iv[maxn], cnt[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    cnt[a[i]]++;
  }
  FOR(i, 1, n) iv[i] = inv(i);
  dp[0][0] = 1;
  REP(i, n) {
    vector<int> rec(n + 1);
    REP(j, n + 1) {
      if (j) ans = add(ans, mul(dp[i][j], mul(cnt[j] - 1, iv[n - i])));
      if (j != n) rec[j + 1] = add(rec[j + 1], mul(dp[i][j], iv[n - i]));
    }
    int s = 0;
    REP(j, n + 1) {
      s = add(s, rec[j]);
      dp[i + 1][j] = mul(s, cnt[j]);
    }
  }
  printf("%d", ans);
}