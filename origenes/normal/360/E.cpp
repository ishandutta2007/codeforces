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

const int maxn = 11234;

int n, m, k, s1, s2, t;
ll f1[maxn], f2[maxn];
int l[maxn], r[maxn], a[maxn], b[maxn], ans[maxn];

vector<pii> G[maxn];
vector<int> G2[maxn];

void dijkstra(ll *f, int s) {
  fill(f + 1, f + n + 1, 1e18);
  f[s] = 0;
  set<pair<ll, int>> q;
  q.emplace(0, s);
  while (!q.empty()) {
    ll d = q.begin()->_1;
    int u = q.begin()->_2;
    q.erase(q.begin());
    if (f[u] < d) continue;
    for (auto e : G[u]) {
      int v = e._1, w = e._2;
      if (f[v] > f[u] + w) {
        f[v] = f[u] + w;
        q.emplace(f[v], v);
      }
    }
    for (int id : G2[u]) {
      int v = b[id], w = ans[id] == 1 ? l[id] : r[id];
      if (f[v] > f[u] + w) {
        f[v] = f[u] + w;
        q.emplace(f[v], v);
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &s1, &s2, &t);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
  }
  FOR(i, 1, k) {
    scanf("%d%d%d%d", a + i, b + i, l + i, r + i);
    G2[a[i]].eb(i);
  }
  dijkstra(f1, s1);
  dijkstra(f2, s2);
  while (true) {
    bool found = false;
    FOR(i, 1, k) if (ans[i] != 1 && f1[a[i]] < f2[a[i]]) {
      ans[i] = 1;
      dijkstra(f1, s1);
      dijkstra(f2, s2);
      found = true;
      break;
    }
    if (!found) break;
  }
  if (f1[t] < f2[t]) {
    puts("WIN");
    goto out;
  }
  fill(ans + 1, ans + k + 1, 0);
  dijkstra(f1, s1);
  dijkstra(f2, s2);
  while (true) {
    bool found = false;
    FOR(i, 1, k) if (ans[i] != 1 && f1[a[i]] <= f2[a[i]]) {
      ans[i] = 1;
      dijkstra(f1, s1);
      dijkstra(f2, s2);
      found = true;
      break;
    }
    if (!found) break;
  }
  if (f1[t] == f2[t]) {
    puts("DRAW");
    goto out;
  }
  puts("LOSE");
  return 0;
  out:
  FOR(i, 1, k) printf("%d ", ans[i] == 1 ? l[i] : r[i]);
}