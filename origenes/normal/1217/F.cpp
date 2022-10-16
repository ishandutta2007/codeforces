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

struct Seg {
  int l, r;
  vector<pii> val;
} T[maxn << 2];

int par[maxn], rk[maxn];
map<int, bool> en[maxn];
map<pii, int> last;
int n, m, ans;
pair<int, pii> query[maxn];

int Find(int x) {
  return par[x] == x ? par[x] : Find(par[x]);
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
  }
}

void add(int o, int l, int r, pii e) {
  if (l <= T[o].l && T[o].r <= r) T[o].val.eb(e);
  else {
    int mi = T[o].l + T[o].r >> 1;
    if (l <= mi) add(o << 1, l, r, e);
    if (r > mi) add(o << 1 | 1, l, r, e);
  }
}

void dfs(int o) {
  vector<pii> now;
  for (auto e : T[o].val) {
    int u = e._1, v = e._2;
    if (en[u][v]) {
      u = Find(u), v = Find(v);
      if (u == v) continue;
      if (rk[u] > rk[v]) swap(u, v);
      par[u] = v, rk[v] += rk[u];
      now.eb(u, v);
    }
  }
  if (T[o].l == T[o].r) {
    if (query[T[o].l]._1 == 2) {
      int t = T[o].l, u = query[t]._2._1, v = query[t]._2._2;
      ans = Find(u) == Find(v);
      printf("%d", ans);
    }
    if (T[o].l < m) {
      int t = T[o].l;
      int &u = query[t + 1]._2._1, &v = query[t + 1]._2._2;
      u = (u - 1 + ans) % n + 1, v = (v - 1 + ans) % n + 1;
      if (u > v) swap(u, v);
      if (query[t + 1]._1 == 1) en[u][v] ^= true;
    }
  } else {
    dfs(o << 1);
    dfs(o << 1 | 1);
  }
  for (auto e : now) {
    int u = e._1, v = e._2;
    rk[v] -= rk[u], par[u] = u;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  build(1, 1, m);
  FOR(i, 1, m) {
    scanf("%d%d%d", &query[i]._1, &query[i]._2._1, &query[i]._2._2);
    if (query[i]._2._1 > query[i]._2._2) swap(query[i]._2._1, query[i]._2._2);
  }
  FOR(i, 1, m) if (query[i]._1 == 1) {
    int u = query[i]._2._1, v = query[i]._2._2;
    if (last.count(mp(u, v))) add(1, last[mp(u, v)], i - 1, mp(u, v));
    int x = u % n + 1, y = v % n + 1;
    if (x > y) swap(x, y);
    if (last.count(mp(x, y))) add(1, last[mp(x, y)], i - 1, mp(x, y));
    last[mp(u, v)] = last[mp(x, y)] = i;
  }
  for (auto cur : last) add(1, cur._2, m, cur._1);
  iota(par + 1, par + n + 1, 1);
  fill(rk + 1, rk + n + 1, 1);
  if (query[1]._1 == 1) en[query[1]._2._1][query[1]._2._2] = true;
  dfs(1);
}