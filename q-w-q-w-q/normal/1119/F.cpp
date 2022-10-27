#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 250005, up = 1e6;
const ll inf = 100000000000000ll;
int rt[N], n, d[N];
ull f[N][2];
vector<int> e[N], ver[N], edg[N], nw;
int a[N], b[N], val[N];
bool in[N], vis[N];
namespace sgt {
int cnt, lc[N * 40], rc[N * 40], sz[N * 40];
ll s[N * 40];
void insert(int &i, int l, int r, int x, int v) {
  if (!i)
    i = ++cnt;
  sz[i] += v, s[i] += x * v;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  if (x <= mid)
    insert(lc[i], l, mid, x, v);
  else
    insert(rc[i], mid + 1, r, x, v);
}
ll query(int i, int l, int r, int x) {
  if (x <= 0)
    return 0;
  if (sz[i] == x)
    return s[i];
  if (sz[i] < x)
    return inf;
  if (l == r)
    return 1ll * l * x;
  int mid = (l + r) >> 1;
  if (sz[lc[i]] >= x)
    return query(lc[i], l, mid, x);
  return s[lc[i]] + query(rc[i], mid + 1, r, x - sz[lc[i]]);
}
} // namespace sgt
void dfs(int i, int fa, int qaq) {
  vis[i] = 1;
  vector<ll> g;
  ull sum = 0;
  for (int k : e[i]) {
    int j = a[k] ^ b[k] ^ i;
    if (j == fa)
      continue;
    dfs(j, i, qaq);
    g.push_back(val[k] + f[j][1] - f[j][0]), sum += f[j][0];
  }
  sort(g.begin(), g.end());
  int tp = d[i] - qaq;
  f[i][0] = sum + sgt::query(rt[i], 1, up, tp);
  f[i][1] = sum + sgt::query(rt[i], 1, up, tp - 1);
  for (ll j : g) {
    sum += j, tp--;
    f[i][0] = min(f[i][0], sum + sgt::query(rt[i], 1, up, tp));
    f[i][1] = min(f[i][1], sum + sgt::query(rt[i], 1, up, tp - 1));
  }
}
vector<ll> minimum_closure_costs(int m, vector<int> u, vector<int> v,
                                 vector<int> w) {
  n = m;
  vector<ll> ans(n);
  for (int i = 1; i < n; i++) {
    a[i] = u[i - 1], b[i] = v[i - 1], val[i] = w[i - 1];
    a[i]++, b[i]++;
    d[a[i]]++, d[b[i]]++;
    ver[d[a[i]]].push_back(a[i]), ver[d[b[i]]].push_back(b[i]);
    edg[a[i]].push_back(i), edg[b[i]].push_back(i);
    sgt::insert(rt[a[i]], 1, up, val[i], 1);
    sgt::insert(rt[b[i]], 1, up, val[i], 1);
  }
  for (int j = n - 1; ~j; j--) {
    for (int i : nw)
      if (!vis[i])
        dfs(i, 0, j), ans[j] += f[i][0];
    for (int i : nw)
      vis[i] = 0;
    for (int i : ver[j]) {
      if (in[i])
        continue;
      in[i] = 1, nw.push_back(i);
      for (int k : edg[i]) {
        int t = a[k] ^ b[k] ^ i;
        if (!in[t])
          continue;
        e[i].push_back(k), e[t].push_back(k);
        sgt::insert(rt[i], 1, up, val[k], -1);
        sgt::insert(rt[t], 1, up, val[k], -1);
      }
    }
  }
  return ans;
}
int main() {
  static int n;
  vector<int> u, v, w;
  vector<ll> ans;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    u.push_back(x), v.push_back(y), w.push_back(z);
  }
  ans = minimum_closure_costs(n, u, v, w);
  for (int i = 0; i < n; i++)
    printf("%lld%c", ans[i], " \n"[i == n - 1]);
}