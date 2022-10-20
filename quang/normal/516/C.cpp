#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100;
const long long INF = (1ll << 60);

int n, m;
long long d[N], h[N], a[N];

struct node {
  long long s, f, best;
} t[N * 4];

void Build(int x, int l, int r) {
  if (l == r) {
    t[x].s = h[l] * 2 - a[l];
    t[x].f = h[l] * 2 + a[l];
    t[x].best = -INF;
    return;
  }
  int m = (l + r) / 2;
  Build(x * 2, l, m);
  Build(x * 2 + 1, m + 1, r);
  t[x].s = max(t[x * 2].s, t[x * 2 + 1].s);
  t[x].f = max(t[x * 2].f, t[x * 2 + 1].f);
  t[x].best = max(t[x * 2].best, t[x * 2 + 1].best);
  t[x].best = max(t[x].best, t[x * 2].s + t[x * 2 + 1].f);
}

node Get(int x, int l, int r, int u, int v) {
  node ans;
  if (u > r || v < l) {
    ans.best = ans.s = ans.f = -INF;
    return ans;
  }
  if (u <= l && r <= v) {
    return t[x];
  }
  int m = (l + r) / 2;
  node foo1 = Get(x * 2, l, m, u, v);
  node foo2 = Get(x * 2 + 1, m + 1, r, u, v);
  ans.s = max(foo1.s, foo2.s);
  ans.f = max(foo1.f, foo2.f);
  ans.best = max(foo1.best, foo2.best);
  ans.best = max(ans.best, foo1.s + foo2.f);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
 //fi, fo;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    h[i + n] = h[i];
  }
  for (int i = 2; i <= n * 2; i++) {
    a[i] = a[i - 1] + d[i - 1];
  }
  Build(1, 1, n * 2);
  while (m--) {
    int l, r;
    cin >> l >> r;
    if (r < l) {
      r += n;
    }
    cout << Get(1, 1, n * 2, r + 1, l + n - 1).best << endl;
  }
  return 0;
}