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

int n, x, d;
int f[maxn], dep[maxn], g[maxn];
vector<int> G[maxn], lvl[maxn], cnt[maxn];
char ans[maxn];

void dfs(int u, int par = 0) {
  dep[u] = dep[par] + 1;
  chkmax(d, dep[u]);
  lvl[dep[u]].eb(u);
  for (auto v : G[u]) dfs(v, u);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> x;
  FOR(i, 2, n) {
    int p; cin >> p;
    G[p].eb(i);
  }
  dfs(1);
  FOR(i, 1, d) cnt[lvl[i].size()].eb(i);
  reset(f, -1);
  f[0] = 0;
  FOR(i, 1, n) if (!cnt[i].empty()) {
    REP(j, n + 1) {
      if (f[j] >= 0) g[j] = 0;
      else g[j] = (j >= i ? g[j - i] + 1: 1e9);
      if (g[j] > 0 && g[j] <= cnt[i].size()) f[j] = cnt[i][g[j] - 1];
    }
  }
  if (f[x] != -1) {
    reset(ans, 'b');
    while (x > 0) {
      for (auto c : lvl[f[x]]) ans[c] = 'a';
      x -= lvl[f[x]].size();
    }
    cout << d << '\n';
    FOR(i, 1, n) cout << ans[i];
    return 0;
  }
  int y = n - x;
  FOR(i, 1, d) if (!lvl[i].empty()) {
    if (lvl[i].size() <= max(x, y)) {
      for (auto c : lvl[i]) ans[c] = (x > y ? 'a' : 'b');
      if (x > y) x -= lvl[i].size();
      else y -= lvl[i].size();
      continue;
    }
    sort(all(lvl[i]), [](int u, int v) { return G[u].size() > G[v].size(); });
    REP(j, max(x, y)) ans[lvl[i][j]] = (x > y ? 'a' : 'b');
    FOR(j, max(x, y), int(lvl[i].size()) - 1) ans[lvl[i][j]] = (x > y ? 'b' : 'a');
    x > y ? x = 0 : y = 0;
  }
  cout << d + 1 << '\n';
  FOR(i, 1, n) cout << ans[i];
}