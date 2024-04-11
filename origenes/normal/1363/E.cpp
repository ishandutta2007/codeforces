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

int n, a[maxn], b[maxn], c[maxn];
ll ans;
vector<int> G[maxn];

int dfs(int u, int par, int cost) {
  chkmin(a[u], cost);
  int zero = 0, one = 0;
  if (b[u] != c[u]) {
    if (b[u] == 0) zero++;
    else one++;
  }
  for (auto v : G[u]) if (v != par) {
    int now = dfs(v, u, a[u]);
    if (now < 0) zero += -now;
    else one += now;
  }
  if (zero <= one) ans += ll(a[u]) * zero;
  else ans += ll(a[u]) * one;
  return one - zero;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d%d", a + i, b + i, c + i);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  int now = dfs(1, 0, 1e9 + 5);
  if (now) puts("-1");
  else printf("%lld", ans * 2);
}