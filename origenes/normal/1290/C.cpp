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
int par[maxn * 2];
ll sz[maxn * 2];
char need[maxn];
vector<int> belong[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  par[u] = v;
  sz[v] += sz[u];
}

int main() {
  ll ans = 0;
  scanf("%d%d", &n, &k);
  scanf("%s", need + 1);
  REP(i, k) {
    int c; scanf("%d", &c);
    while (c--) {
      int x; scanf("%d", &x);
      belong[x].eb(i * 2);
    }
  }
  iota(par, par + 2 * k, 0);
  REP(i, k) sz[2 * i] = 1;
  FOR(i, 1, n) need[i] = (need[i] == '0');
  FOR(i, 1, n) {
    if (belong[i].size() == 2) {
      int u = Find(belong[i][0]), v = Find(belong[i][1]);
      int nu = Find(u ^ 1), nv = Find(v ^ 1);
      if (u != v && u != nv) {
        ans -= min(sz[u], sz[nu]);
        ans -= min(sz[v], sz[nv]);
        if (need[i]) Union(u, nv), Union(nu, v);
        else Union(u, v), Union(nu, nv);
        u = Find(u), nu = Find(nu);
        ans += min(sz[u], sz[nu]);
      }
    } else if (!belong[i].empty()) {
      int u = Find(belong[i][0]), nu = Find(u ^ 1);
      ans -= min(sz[u], sz[nu]);
      need[i] ? (sz[nu] += maxn) : (sz[u] += maxn);
      ans += min(sz[u], sz[nu]);
    }
    printf("%lld\n", ans);
  }
}