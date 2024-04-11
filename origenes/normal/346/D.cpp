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

const int maxn = 1123456;

int n, m, s, t;
int f[maxn], deg[maxn];
bool vis[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[v].eb(u);
    deg[u]++;
  }
  scanf("%d%d", &s, &t);
  reset(f, -1);
  f[t] = 0;
  deque<int> q;
  q.eb(t);
  while (!q.empty()) {
    auto u = q.front(); q.pop_front();
    if (u == s) break;
    if (vis[u]) continue;
    vis[u] = true;
    for (auto v : G[u]) if (!--deg[v]) {
      if (f[v] == -1 || f[u] < f[v]) {
        f[v] = f[u];
        q.emplace_front(v);
      }
    } else if (f[v] == -1) {
      f[v] = f[u] + 1;
      q.eb(v);
    }
  }
  printf("%d", f[s]);
}