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

int n, a, b, da, db, f[maxn];
vector<int> G[maxn];

void bfs(int s) {
  vector<char> vis(n + 1);
  vis[s] = true;
  f[s] = 0;
  queue<int> q; q.emplace(s);
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    for (auto v : G[u]) if (!vis[v]) {
      f[v] = f[u] + 1;
      vis[v] = true;
      q.emplace(v);
    }
  }
}

void solve() {
  scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  bfs(a);
  if (f[b] <= da) {
    puts("Alice");
    return;
  }
  FOR(i, 1, n) if (G[i].size() == 1) {
    bfs(i);
    int j = max_element(f + 1, f + n + 1) - f;
    bfs(j);
    int d = *max_element(f + 1, f + n + 1);
    if (da * 2 >= d) {
      puts("Alice");
      return;
    }
    break;
  }
  puts(db > 2 * da ? "Bob" : "Alice");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}