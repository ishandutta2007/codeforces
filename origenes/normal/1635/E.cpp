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

int n, m;
int c[maxn], deg[maxn], pos[maxn];
char dir[maxn];
vector<int> G[maxn];

bool dfs(int u, int x) {
  c[u] = x;
  for (auto v : G[u]) {
    if (c[v] == -1 && !dfs(v, 1 - x)) return false;
    if (c[v] == x) return false;
  }
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (auto &[op, x, y] : edges) {
    cin >> op >> x >> y;
    G[x].eb(y);
    G[y].eb(x);
  }
  reset(c, -1);
  FOR(i, 1, n) if (c[i] == -1 && !dfs(i, 0)) {
    cout << "NO\n";
    return 0;
  }
  FOR(i, 1, n) G[i].clear();
  for (auto [op, x, y] : edges) {
    if (c[x]) swap(x, y);
    if (op == 1) {
      G[x].eb(y);
      deg[y]++;
    } else {
      G[y].eb(x);
      deg[x]++;
    }
  }
  queue<int> q;
  FOR(i, 1, n) if (deg[i] == 0) q.emplace(i);
  int x = 0;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    pos[u] = x++;
    dir[u] = c[u] ? 'R' : 'L';
    for (auto v : G[u]) if (!--deg[v]) q.emplace(v);
  }
  if (x != n) cout << "NO\n";
  else {
    cout << "YES\n";
    FOR(i, 1, n) cout << dir[i] << ' ' << pos[i] << '\n';
  }
}