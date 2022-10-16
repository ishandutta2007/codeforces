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

vector<int> G[maxn];
int m, a, b, dis[maxn], f[maxn];
ll ans;

int main() {
  scanf("%d%d%d", &m, &a, &b);
  REP(i, 2 * a + b + 1) {
    if (i >= b) G[i].eb(i - b);
    if (i <= a + b) G[i].eb(i + a);
  }
  reset(dis, 0x3f);
  dis[0] = 0;
  set<pii> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(now);
    int u = now._2, d = now._1;
    if (d > dis[u]) continue;
    for (auto v : G[u]) if (dis[v] > d && dis[v] > v) {
      dis[v] = max(d, v);
      q.emplace(dis[v], v);
    }
  }
  sort(dis, dis + 2 * a + b + 1);
  int p = 0;
  REP(i, 2 * a + b + 1) {
    while (p <= 2 * a + b && dis[p] <= i) p++;
    f[i] = p;
  }
  REP(i, min(m + 1, a + b)) ans += f[i];
  int d = a / __gcd(a, b);
  FOR(i, a + b, min(m, 2 * a + b - 1)) {
    int k = (m - i) / a;
    ans += ll(k + 1) * (f[i] * 2 + ll(k) * d) / 2;
  }
  printf("%lld", ans);
}