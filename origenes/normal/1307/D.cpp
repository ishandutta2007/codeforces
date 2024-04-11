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

set<int> G[maxn];
int n, m, k;

void dijkstra(int *f, int source) {
  set<pii> q;
  f[source] = 0;
  q.emplace(0, source);
  while (!q.empty()) {
    auto [d, u] = *q.begin(); q.erase(q.begin());
    if (f[u] < d) continue;
    for (auto v : G[u]) if (f[v] > f[u] + 1) {
      f[v] = f[u] + 1;
      q.emplace(f[v], v);
    }
  }
}

int a[maxn], f[maxn], g[maxn];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, k) scanf("%d", a + i);
  set<int> special(a + 1, a + k + 1);
  bool found = false;
  while (m--) {
    int u, v; scanf("%d%d", &u, &v);
    if (special.count(u) && special.count(v)) found = true;
    G[u].emplace(v); G[v].emplace(u);
  }
  reset(f, 0x3f); reset(g, 0x3f);
  dijkstra(f, 1);
  dijkstra(g, n);
  if (found) {
    printf("%d", f[n]);
    return 0;
  }
  int ans = 0;
  vector<pii> v; v.reserve(k);
  FOR(i, 1, k) v.eb(g[a[i]] - f[a[i]], a[i]);
  sort(all(v));
  set<int> avail;
  REP(i, k) {
    int idx = v[i]._2;
    if (!avail.empty()) chkmax(ans, f[idx] - *avail.begin() + 1);
    avail.emplace(-g[idx]);
  }
  reverse(all(v));
  avail.clear();
  REP(i, k) {
    int idx = v[i]._2;
    if (!avail.empty()) chkmax(ans, g[idx] - *avail.begin() + 1);
    avail.emplace(-f[idx]);
  }
  printf("%d", min(ans, f[n]));
}