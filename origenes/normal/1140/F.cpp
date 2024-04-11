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

const int maxn = 312345;

struct Seg {
  int l, r;
  vector<pii> upd;
} T[maxn << 2];

map<pii, int> in;
int q, par[maxn << 1], clk;
pii sz[maxn << 1];
stack<pii> pre[maxn << 1];
stack<pair<pii, int>> buff;
ll ans[maxn << 1], res;

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l < r) {
    int m = l + r >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
  }
}

void add(int o, int l, int r, pii v) {
  if (l <= T[o].l && T[o].r <= r) {
    T[o].upd.eb(v);
    return;
  }
  int m = T[o].l + T[o].r >> 1;
  if (l <= m) add(o << 1, l, r, v);
  if (r > m) add(o << 1 | 1, l, r, v);
}

int Find(int x) {
  return par[x] == x ? x : Find(par[x]);
}

void Union(int u, int v, int t) {
  int pu = Find(u), pv = Find(v);
  if (pu == pv) return;
  if (sz[pu]._1 + sz[pu]._2 < sz[pv]._1 + sz[pv]._2) swap(pu, pv);
  pre[pu].emplace(sz[pu]); pre[pv].emplace(sz[pv]);
  res -= ll(sz[pu]._1) * sz[pu]._2 + ll(sz[pv]._1) * sz[pv]._2;
  par[pv] = pu;
  sz[pu]._1 += sz[pv]._1, sz[pu]._2 += sz[pv]._2;
  res += ll(sz[pu]._1) * sz[pu]._2;
  buff.emplace(mp(pu, pv), t);
}

void rm(int u, int v) {
  par[v] = v;
  res -= ll(sz[u]._1) * sz[u]._2;
  sz[u]= pre[u].top(); pre[u].pop();
  res += ll(sz[u]._1) * sz[u]._2;
  sz[v] = pre[v].top(); pre[v].pop();
  res += ll(sz[v]._1) * sz[v]._2;
}

void dfs(int o) {
  int now = ++clk;
  for (auto it : T[o].upd) Union(it._1, it._2, now);
  if (T[o].l == T[o].r) {
    ans[T[o].l] = res;
  } else {
    dfs(o << 1);
    dfs(o << 1 | 1);
  }
  while (!buff.empty() && buff.top()._2 == now) {
    auto cur = buff.top()._1; buff.pop();
    rm(cur._1, cur._2);
  }
}

int main() {
  build(1, 1, 1 << 19);
  scanf("%d", &q);
  FOR(i, 1, maxn) par[i] = i, sz[i] = {1, 0};
  FOR(i, maxn + 1, 2 * maxn - 1) par[i] = i, sz[i] = {0, 1};
  FOR(i, 1, q) {
    pii now;
    scanf("%d%d", &now._1, &now._2);
    now._2 += maxn;
    if (in.count(now)) {
      int st = in[now];
      add(1, st, i - 1, now);
      in.erase(now);
    } else in[now] = i;
  }
  for (const auto &it : in) {
    auto now = it._1;
    int st = it._2;
    add(1, st, q + 1, now);
  }
  dfs(1);
  FOR(i, 1, q) printf("%lld ", ans[i]);
}