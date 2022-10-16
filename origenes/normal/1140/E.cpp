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

const int maxn = 212345;
const int MOD = 998244353;

int n, k, a[maxn], tot, dp[maxn][2];
bool vis[maxn][2];
vector<int> lis;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int dfs(int len, bool same) {
  if (vis[len][same]) return dp[len][same];
  vis[len][same] = true;
  if (same) dp[len][same] = mul(dfs(len - 1, false), k - 1);
  else dp[len][same] = add(dfs(len - 1, true), mul(dfs(len - 1, false), max(k - 2, 0)));
  return dp[len][same];
}

int solve(int op) {
  int pre = -op, ret = 1;
  for (auto now : lis) {
    if (now == pre + 2 ) {
      if (pre > 0 && a[now] == a[pre]) return 0;
      pre = now;
      continue;
    }
    int len = (now - pre >> 1) - 1;
    if (len > 0) {
      if (pre > 0) {
        ret = mul(ret, dfs(len, a[now] == a[pre]));
      } else {
        if (len == 1) ret = mul(ret, k - 1);
        else {
          int tmp = add(dfs(len - 1, true), mul(dfs(len - 1, false), k - 1));
          ret = mul(ret, tmp);
        }
      }
    }
    if (!ret) return 0;
    pre = now;
  }
  int en = tot * 2 + 2 - op;
  if (en == pre + 2) {
    if (pre > 0 && a[en] == a[pre]) return 0;
    return ret;
  }
  int len = (en - pre >> 1) - 1;
  if (len > 0) {
    if (pre > 0) {
      if (len == 1) ret = mul(ret, k - 1);
      else {
        int tmp = add(dfs(len - 1, true), mul(dfs(len - 1, false), k - 1));
        ret = mul(ret, tmp);
      }
    } else {
      if (len == 1) ret = mul(ret, k);
      else if (len == 2) ret = mul(mul(ret, k), k - 1);
      else {
        int tmp = add(mul(dfs(len - 2, true), k), mul(dfs(len - 2, false), mul(k, k - 1)));
        ret = mul(ret, tmp);
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  for (int i = 1; i <= n; i += 2) {
    if (a[i] != -1) lis.eb(i);
    tot++;
  }
  vis[1][1] = true; dp[1][1] = k - 1;
  vis[1][0] = true; dp[1][0] = max(k - 2, 0);
  vis[2][1] = true; dp[2][1] = mul(k - 1, max(k - 2, 0));
  int ans = solve(1);
  lis.clear();
  tot = 0;
  for (int i = 2; i <= n; i += 2) {
    if (a[i] != -1) lis.eb(i);
    tot++;
  }
  ans = mul(ans, solve(0));
  printf("%d", ans);
}