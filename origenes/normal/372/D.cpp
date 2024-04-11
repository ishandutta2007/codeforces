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

vector<int> G[maxn];
int dep[maxn], anc[maxn][18], dfn[maxn];
int n, k, clk;

void dfs(int u, int par) {
  dep[u] = dep[par] + 1;
  dfn[u] = ++clk;
  anc[u][0] = par;
  FOR(i, 1, 17) anc[u][i] = anc[anc[u][i - 1]][i - 1];
  for (auto v : G[u]) if(v != par) dfs(v, u);
}

int dist(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  int x = u, y = v;
  ROF(i, 17, 0) if (dep[anc[v][i]] >= dep[u]) v = anc[v][i];
  if (u == v) return dep[x] + dep[y] - 2 * dep[u];
  ROF(i, 17, 0) if (anc[v][i] != anc[u][i]) u = anc[u][i], v = anc[v][i];
  u = anc[u][0];
  return dep[x] + dep[y] - 2 * dep[u];
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  dfs(1, 0);
  int ans = 1, j = 1, now = 0;
  set<pii> s;
  s.emplace(dfn[1], 1);
  FOR(i, 2, n) {
    auto it1 = s.lower_bound(mp(dfn[i], i)), it2 = it1;
    if (it2 == s.begin()) it1 = prev(s.end());
    else {
      it1--;
      if (it2 == s.end()) it2 = s.begin();
    }
    now -= dist(it1->_2, it2->_2);
    now += dist(it1->_2, i) + dist(it2->_2, i);
    s.emplace(dfn[i], i);
    if (i - j + 1 < ans) continue;
    if (now / 2 < k) chkmax(ans, i - j + 1);
    else {
      auto it = s.find(mp(dfn[j], j));
      if (it == s.begin()) it1 = prev(s.end());
      else it1 = it, it1--;
      it2 = it, it2++;
      if (it2 == s.end()) it2 = s.begin();
      now -= dist(it1->_2, j) + dist(it2->_2, j);
      now += dist(it1->_2, it2->_2);
      s.erase(it);
      j++;
    }
  }
  printf("%d", ans);
}