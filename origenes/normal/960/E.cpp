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
const int MOD = 1e9 + 7;

vector<int> G[maxn];
ll sum[maxn][2], cnt[maxn][2], ans;
int n, val[maxn], ch[maxn];

inline ll add(ll a, ll b) {
  return ((a + b) % MOD + MOD) % MOD;
}

inline ll mul(ll a, ll b) {
  return (a * b % MOD + MOD) % MOD;
}

void dfs(int u, int par) {
  for (int v : G[u]) if (v != par) {
      dfs(v, u);
      sum[u][1] = add(sum[u][1], mul(val[u], cnt[v][0]));
      sum[u][1] = add(sum[u][1], sum[v][0]);
      sum[u][0] = add(sum[u][0], mul(-val[u], cnt[v][1]));
      sum[u][0] = add(sum[u][0], sum[v][1]);
      cnt[u][0] = add(cnt[u][0], cnt[v][1]);
      cnt[u][1] = add(cnt[u][1], cnt[v][0]);
    }
  cnt[u][1] = add(cnt[u][1], 1);
  sum[u][1] = add(sum[u][1], val[u]);
  ll way = add(cnt[u][0], cnt[u][1]);
  for (int v : G[u]) if (v != par) {
      ll tmp = ((sum[u][1] - sum[v][0] - sum[u][0] + sum[v][1]) % MOD + MOD) % MOD;
      tmp = add(tmp, mul(val[u], add(-cnt[v][0], -cnt[v][1])));
      ans = add(ans, mul(cnt[v][0], tmp));
      ans = add(ans, mul(sum[v][0], add(way, -cnt[v][0] - cnt[v][1])));
      tmp = ((sum[u][0] + sum[v][0] - sum[u][1] - sum[v][1]) % MOD + MOD) % MOD;
      tmp = add(tmp, mul(val[u], add(cnt[v][0], cnt[v][1])));
      ans = add(ans, mul(cnt[v][1], tmp));
      ans = add(ans, mul(sum[v][1], add(way, -cnt[v][0] - cnt[v][1])));
    }
  ans = add(ans, val[u]);
  for (int v : G[u]) if (v != par) {
    ans = add(ans, mul(val[u], add(cnt[v][0], cnt[v][1])));
    ans = add(ans, -sum[v][1]);
    ans = add(ans, sum[v][0]);
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", val + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  ch[1] = G[1].size();
  FOR(i, 2, n) ch[i] = G[i].size() - 1;
  dfs(1, 0);
  printf("%lld", ans);
}