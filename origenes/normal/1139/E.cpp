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

const int maxn = 5123;

int n, m, d;
int p[maxn], c[maxn], k[maxn], match[maxn], ans[maxn];
bool vis[maxn], mark[maxn];
vector<int> G[maxn];

bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (int v : G[u]) if (match[v] == -1 || dfs(match[v])) {
    match[v] = u;
    return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", p + i);
  FOR(i, 1, n) scanf("%d", c + i);
  reset(match, -1);
  scanf("%d", &d);
  FOR(i, 1, d) {
    scanf("%d", k + i);
    mark[k[i]] = true;
  }
  FOR(i, 1, n) if (!mark[i]) G[p[i]].eb(c[i]);
  int now = 0;
  ROF(i, d, -1) {
    while (true) {
      reset(vis, 0);
      if (!dfs(now)) break;
      now++;
    }
    ans[i] = now;
    G[p[k[i]]].eb(c[k[i]]);
  }
  FOR(i, 1, d) printf("%d\n", ans[i]);
}