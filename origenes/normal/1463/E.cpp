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

const int maxn = 312345;

int n, k;
int p[maxn], deg[maxn], par[maxn], nxt[maxn];
bool vis[maxn];
vector<int> G[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  FOR(i, 1, n) cin >> p[i];
  while (k--) {
    int x, y;
    cin >> x >> y;
    G[x].eb(y);
    deg[y]++;
    if (deg[y] == 2) {
      cout << 0;
      return 0;
    }
  }
  queue<int> q;
  FOR(i, 1, n) if (!deg[i]) q.emplace(i);
  iota(par + 1, par + n + 1, 1);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    if (G[u].size() > 1) {
      cout << 0;
      return 0;
    }
    if (G[u].empty()) nxt[u] = -1;
    else {
      int v = G[u][0];
      nxt[u] = v;
      q.emplace(v);
      par[v] = u;
    }
  }
  FOR(i, 1, n) if (!nxt[i]) {
    cout << 0;
    return 0;
  }
  FOR(i, 1, n) {
    G[i].clear();
    deg[i] = 0;
  }
  FOR(i, 1, n) if (p[i]) {
    if (Find(p[i]) == Find(i)) continue;
    G[Find(p[i])].eb(i);
    deg[Find(i)]++;
  }
  FOR(i, 1, n) if (i == Find(i) && !deg[i]) q.emplace(i);
  vector<int> ans;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : G[u]) {
      v = Find(v);
      if (!--deg[v]) q.emplace(v);
    }
    do {
      ans.eb(u);
      u = nxt[u];
    } while (u != -1);
  }
  if (ans.size() != n) {
    cout << 0;
    return 0;
  }
  vis[0] = true;
  for (auto x : ans) {
    if (!vis[p[x]]) {
      cout << 0;
      return 0;
    }
    vis[x] = true;
  }
  for (auto x : ans) cout << x << ' ';
}