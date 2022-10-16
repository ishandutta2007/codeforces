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

const int maxn = 412345;
const int dx[] = {1, 0, 0};
const int dy[] = {0, -1, 1};

vector<int> G[maxn];
int scc_no, clk;
int comp[maxn], lowlink[maxn], pre[maxn], deg[maxn];
stack<int> S;

void dfs(int u) {
  pre[u] = lowlink[u] = ++clk;
  S.emplace(u);
  for (auto v : G[u]) {
    if (!pre[v]) {
      dfs(v);
      chkmin(lowlink[u], lowlink[v]);
    } else if (!comp[v]) chkmin(lowlink[u], pre[v]);
  }
  if (pre[u] == lowlink[u]) {
    int v;
    scc_no++;
    do {
      v = S.top(); S.pop();
      comp[v] = scc_no;
    } while (u != v);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<int>> down(n, vector<int>(m));
  REP(i, n) cin >> s[i];
  REP(j, m) ROF(i, n - 1, 0) {
    if (s[i][j] == '#') down[i][j] = i;
    else down[i][j] = i + 1 < n ? down[i + 1][j] : n;
  }
  REP(i, n) REP(j, m) if (s[i][j] == '#') {
    int u = i * m + j;
    REP(d, 3) {
      int ni = i + dx[d], nj = j + dy[d];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
      ni = down[ni][nj];
      if (ni < 0 || ni >= n) continue;
      if (s[ni][nj] == '#') {
        int v = ni * m + nj;
        G[u].eb(v);
      }
    }
    if (i > 0 && s[i - 1][j] == '#') {
      int v = (i - 1) * m + j;
      G[u].eb(v);
    }
  }
  REP(i, n) REP(j, m) if (s[i][j] == '#' && !comp[i * m + j]) dfs(i * m + j);
  REP(i, n) REP(j, m) {
    int u = i * m + j;
    for (auto v : G[u]) if (comp[u] != comp[v]) deg[comp[v]]++;
  }
  int ans = 0;
  FOR(i, 1, scc_no) if (deg[i] == 0) ans++;
  cout << ans;
}