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

const int maxn = 112345;

int n, m;
bool ok;
int p[maxn], h[maxn];
ll s[maxn];
vector<int> G[maxn];

ll dfs(int u, int par) {
  s[u] = p[u];
  ll good = 0;
  for (auto v : G[u]) if (v != par) {
    good += dfs(v, u);
    if (!ok) return -1;
    s[u] += s[v];
  }
  if ((s[u] + h[u]) & 1) {
    ok = false;
    return -1;
  }
  ll have = (s[u] + h[u]) / 2;
  if (have < good || s[u] < have) {
    ok = false;
    return -1;
  }
  if (have < 0) {
    ok = false;
    return -1;
  }
  return have;
}

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) scanf("%d", h + i);
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].eb(y); G[y].eb(x);
  }
  ok = true;
  dfs(1, 0);
  puts(ok ? "YES" : "NO");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}