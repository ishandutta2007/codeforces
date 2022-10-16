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

const int maxn = 312345;

int dep[maxn], n, m;
ll fen[maxn], ans[maxn], now;
vector<int> G[maxn];
vector<pii> qry[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, ll d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll sum(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  for (auto q : qry[u]) {
    int d = q._1, x = q._2;
    now += x;
    add(min(dep[u] + d + 1, n + 1), x);
  }
  ans[u] = now - sum(dep[u]);
  for (int v : G[u]) if (v != par) dfs(v, u);
  for (auto q : qry[u]) {
    int d = q._1, x = q._2;
    now -= x;
    add(min(dep[u] + d + 1, n + 1), -x);
  }
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  scanf("%d", &m);
  FOR(i, 1, m) {
    int u, d, x;
    scanf("%d%d%d", &u, &d, &x);
    qry[u].eb(d, x);
  }
  dfs(1, 0);
  FOR(i, 1, n) printf("%lld ", ans[i]);
}