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

const int maxn = 212345;

set<int> G[maxn], sel[maxn];

int n, m, par[maxn], d, cc, p[maxn];
vector<int> vec;

void dfs(int u, int par) {
  p[u] = par;
  vec.eb(u);
  for (auto v : sel[u]) if (v != par) dfs(v, u);
}

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  int pu = Find(u), pv = Find(v);
  par[pv] = pu;
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  FOR(i, 1, n) par[i] = i;
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].emplace(v);
    G[v].emplace(u);
  }
  cc = n;
  FOR(u, 2, n) for (auto v : G[u]) if (v != 1) {
        int pu = Find(u), pv = Find(v);
        if (pu != pv) {
          Union(u, v);
          sel[u].emplace(v);
          sel[v].emplace(u);
          cc--;
        }
      }
  if (cc > d + 1) {
    puts("NO");
    return 0;
  }
  for (auto v : G[1]) p[Find(v)] = 1;
  FOR(i, 2, n) if (!p[Find(i)]) {
      puts("NO");
      return 0;
    }
  reset(p, 0);
  for (auto v : G[1]) {
    int pu = Find(1), pv = Find(v);
    if (pu == pv) continue;
    Union(1, v);
    sel[1].emplace(v);
    sel[v].emplace(1);
    d--;
  }
  if (d) {
    FOR(i, 2, n) if (!p[i]) {
        vec.clear();
        dfs(i, 1);
        for (auto v : vec) if (G[1].count(v) && !sel[1].count(v)) {
            sel[1].emplace(v);
            sel[v].emplace(1);
            sel[v].erase(p[v]);
            sel[p[v]].erase(v);
            if (!--d) break;
          }
        if (!d) break;
      }
  }
  if (!d) {
    puts("YES");
    FOR(u, 1, n) for (auto v : sel[u]) if (v > u) printf("%d %d\n", u, v);
  } else puts("NO");
}