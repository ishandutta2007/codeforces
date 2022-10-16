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

const int maxn = 1123;

int n, tot;
int x[maxn], y[maxn], par[maxn], cc[maxn];
map<pii, vector<int>> jp;
vector<int> d[maxn * maxn], id[maxn * maxn];

void ins(int x, int y, int i, int j) {
  jp[mp(x, y)].eb(i);
  jp[mp(x, y)].eb(j);
}

int dis(pii a, pii b) {
  return abs(a._1 - b._1) + abs(a._2 -  b._2);
}

int dis(int i, int j) {
  return dis(mp(x[i], y[i]), mp(x[j], y[j]));
}

int Find(int x) {
  return x == par[x] ? x : par[x] = Find(par[x]);
}

void Union(int u, int v) {
  u = Find(u), v = Find(v);
  par[u] = v;
}

bool check(ll lim) {
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, n) FOR(j, 1, i - 1) if ((x[i] == x[j] || y[i] == y[j]) && dis(i, j) <= lim) Union(i, j);
  set<int> comp;
  FOR(i, 1, n) comp.emplace(Find(i));
  if (comp.size() == 1) return true;
  if (comp.size() > 4) return false;
  int cnt = 0;
  for (auto p : comp) cc[p] = cnt++;
  FOR(i, 1, n) cc[i] = cc[Find(i)];
  REP(i, tot) {
    int mask = 0;
    REP(j, int(id[i].size())) if (d[i][j] <= lim) mask |= 1 << cc[id[i][j]];
    if (mask == (1 << cnt) - 1) return true;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  FOR(i, 1, n) FOR(j, 1, i - 1) {
    if (x[i] == x[j]) ins(x[i], (y[i] + y[j]) / 2, i, j);
    else if (y[i] == y[j]) ins((x[i] + x[j]) / 2, y[i], i, j);
    else {
      ins(x[i], y[j], i, j);
      ins(x[j], y[i], i, j);
    }
  }
  for (const auto &[p1, v] : jp) {
    for (auto idx : v) {
      d[tot].eb(dis(p1, mp(x[idx], y[idx])));
      id[tot].eb(idx);
    }
    tot++;
  }
  ll lo = 1, hi = 2e9 + 10;
  while (lo < hi) {
    ll mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  if (lo > 2e9) puts("-1");
  else printf("%lld", lo);
}