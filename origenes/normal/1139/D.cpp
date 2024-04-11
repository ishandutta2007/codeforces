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

const int MOD = 1e9 + 7;
const int maxm = 112345;

int m, dp[maxm], iv, ans;
vector<pii> G[maxm];
vector<int> lis[maxm], primes;
bool vis[maxm];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
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

void get(int n, int now) {
  int mas = n / now, upp = m / now, sz = lis[mas].size(), ret = 0;
  REP(mask, 1 << sz) {
    int p = 1;
    REP(i, sz) if (mask & (1 << i)) p *= lis[mas][i];
    ret += (__builtin_popcount(mask) & 1 ? -1 : 1) * (upp / p);
  }
  G[n].eb(now, ret);
}

int dfs(int u) {
  if (dp[u] > -1) return dp[u];
  int rec = -1;
  int &ret = dp[u];
  dp[u] = 0;
  for (auto _ : G[u]) {
    int v = _._1, prob = mul(_._2, iv);
    if (v == u) {
      rec = prob;
      continue;
    }
    dp[u] = add(dp[u], mul(dfs(v), prob));
  }
  assert(rec >= 0);
  dp[u] = mul(add(dp[u], 1), pow_mod(add(1, MOD - rec), MOD - 2));
  return dp[u];
}

int main() {
  scanf("%d", &m);
  iv = pow_mod(m, MOD - 2);
  FOR(i, 2, m) if (!vis[i]) {
    primes.eb(i);
    lis[i].eb(i);
    for (int j = 2 * i; j <= m; j += i) {
      vis[j] = true;
      lis[j].eb(i);
    }
  }
  FOR(i, 1, m) {
    int upp = sqrt(i) + 0.5;
    FOR(j, 1, upp) if (i % j == 0) {
      get(i, j);
      if (j < i / j) get(i, i / j);
    }
  }
  reset(dp, -1);
  dp[1] = 0;
  ROF(i, m, 2) if (dp[i] == -1) dfs(i);
  FOR(i, 1, m) ans = add(ans, mul(add(dp[i], 1), iv));
  printf("%d", ans);
}