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

double a[maxn], s[maxn];
int par[maxn], n, q;
vector<int> G[maxn];

void dfs(int u, int p) {
  par[u] = p;
  for (auto v : G[u]) if (v != p) {
    dfs(v, u);
    s[u] += a[v];
  }
}

int main() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lf", a + i);
    a[i] = 1 - a[i];
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(0, -1);
  double ans = 0;
  REP(i, n) ans += a[i] - a[i] * s[i];
  scanf("%d", &q);
  while (q--) {
    int u;
    double p;
    scanf("%d%lf", &u, &p);
    p = 1 - p;
    double d = p - a[u] - (p - a[u]) * s[u];
    if (par[u] != -1) {
      d -= a[par[u]] * (p - a[u]);
      s[par[u]] += p - a[u];
    }
    a[u] = p;
    printf("%.10lf\n", ans += d);
  }
}