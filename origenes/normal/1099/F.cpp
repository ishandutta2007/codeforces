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

const int maxn = 112345;
const int maxt = 1123456;

ll dp[maxn], val[maxn], dis[maxn], fen[2][maxt], T;
vector<pii> G[maxn];
int n, x[maxn], t[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(ll *fen, int x, ll v) {
  while (x < maxt) {
    fen[x] += v;
    x += lowbit(x);
  }
}

ll sum(const ll *fen, int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

ll get(int u) {
  ll rem = T - 2 * dis[u];
  if (rem <= 0) return 0;
  int lo = 1, hi = 1e6 + 5;
  while (lo <= hi) {
    int mi = lo + hi >> 1;
    ll ls = sum(fen[1], mi - 1), hs = sum(fen[1], mi);
    if (ls < rem && rem <= hs) return sum(fen[0], mi - 1) + (rem - ls) / mi;
    if (ls >= rem) hi = mi - 1;
    else lo = mi + 1;
  }
  return sum(fen[0], lo);
}

void dfs(int u) {
  add(fen[0], t[u], x[u]);
  add(fen[1], t[u], ll(t[u]) * x[u]);
  dp[u] = val[u] = get(u);
  ll mmax[2] = {};
  for (auto _v : G[u]) {
    int v = _v._1, d = _v._2;
    dis[v] = dis[u] + d;
    if (2 * dis[v] < T) {
      dfs(v);
      if (dp[v] > mmax[0]) {
        mmax[1] = mmax[0];
        mmax[0] = dp[v];
      } else if (dp[v] > mmax[1]) mmax[1] = dp[v];
    }
  }
  if (u == 1) chkmax(dp[u], mmax[0]);
  else chkmax(dp[u], mmax[1]);
  add(fen[0], t[u], -x[u]);
  add(fen[1], t[u], -x[u] * ll(t[u]));
}

int main() {
  scanf("%d%lld", &n, &T);
  FOR(i, 1, n) scanf("%d", x + i);
  FOR(i, 1, n) scanf("%d", t + i);
  FOR(i, 2, n) {
    int p, l;
    scanf("%d%d", &p, &l);
    G[p].eb(i, l);
  }
  dfs(1);
  printf("%lld", dp[1]);
}