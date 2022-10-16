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

vector<int> G[maxn];
int n;
ll f[maxn][2];
ll h[maxn], t[maxn];

void dfs(int u, int par) {
  vector<ll> g;
  ll s = 0;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    s += f[v][0];
    g.eb(f[v][1] - f[v][0]);
  }
  sort(all(g));
  if (u == 1 || h[u] <= h[par]) {
    ll now = s;
    f[u][0] = now + t[u] * max(int(g.size()), 1);
    REP(i, int(g.size())) {
      now += g[i];
      chkmin(f[u][0], now + t[u] * max(int(g.size()) - i - 1, i + 1 + (u != 1)));
    }
  } else f[u][0] = 1e12;
  if (u == 1 || h[u] >= h[par]) {
    ll now = s;
    f[u][1] = now + t[u] * (g.size() + (u != 1));
    REP(i, int(g.size())) {
      now += g[i];
      chkmin(f[u][1], now + t[u] * max(int(g.size()) - i - (u == 1), i + 1));
    }
  } else f[u][1] = 1e12;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", t + i);
  FOR(i, 1, n) scanf("%lld", h + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  printf("%lld", min(f[1][0], f[1][1]));
}