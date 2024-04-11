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

const int maxn = 512345;

int n, k;
ll f[maxn][2];
vector<pii> G[maxn];

void dfs(int u, int par) {
  vector<pair<ll, int>> ch;
  ll base = 0;
  for (auto _ : G[u]) {
    int v = _._1, w = _._2;
    if (v == par) continue;
    dfs(v, u);
    base += max(f[v][0], f[v][1]);
    ch.eb(w + f[v][1] - f[v][0], v);
  }
  f[u][0] = f[u][1] = base;
  sort(all(ch), greater<>());
  REP(i, min(int(ch.size()), k - 1)) {
    if (ch[i]._1 <= 0) return;
    f[u][0] += ch[i]._1, f[u][1] += ch[i]._1;
  }
  if (ch.size() >= k && ch[k - 1]._1 > 0) f[u][0] += ch[k - 1]._1;
}

void solve() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    G[i].clear();
    reset(f[i], 0);
  }
  REP(i, n - 1) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  dfs(1, 0);
  printf("%lld\n", max(f[1][0], f[1][1]));
}

int main() {
  int q; scanf("%d", &q);
  while (q--) solve();
}