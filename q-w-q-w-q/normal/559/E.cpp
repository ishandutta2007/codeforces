#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 105;
int n, f[N], g[N][N], ans;
struct p {
  int x, l;
  bool operator<(const p &j) const { return x < j.x; }
} a[N];
inline int calc(vector<pair<int, int>> a) {
  static pair<int, int> b[N << 1];
  int cnt = 0, ans = 0;
  for (auto tp : a) {
    b[++cnt] = make_pair(tp.first, 1);
    b[++cnt] = make_pair(tp.second, -1);
  }
  sort(b + 1, b + cnt + 1);
  for (int i = 1, x = 0; i < cnt; i++) {
    x += b[i].second;
    if (x > 0) ans += b[i + 1].first - b[i].first;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].l;
  sort(a + 1, a + n + 1);
  a[0].x = -(1 << 30);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int r = a[j].x + a[j].l;
      if (a[i + 1].x + a[i + 1].l >= r)
        g[i + 1][i + 1] = max(g[i + 1][i + 1], g[i][j] + min(a[i + 1].l, a[i + 1].x + a[i + 1].l - r));
      else
        g[i + 1][j] = max(g[i + 1][j], g[i][j]);
      if (r <= a[i + 1].x || a[i + 1].x - a[i + 1].l >= a[j].x) continue;
      int k = i, l = a[i + 1].x - a[i + 1].l;
      vector<pair<int, int>> b{make_pair(a[i + 1].x - a[i + 1].l, a[i + 1].x)};
      while (a[k].x >= l) {
        if (k != j) {
          l = min(l, a[k].x - a[k].l);
          b.push_back(make_pair(a[k].x - a[k].l, a[k].x));
        } else
          b.push_back(make_pair(a[j].x, a[j].x + a[j].l));
        k--;
      }
      for (int t = 0; t <= k; t++) {
        if (a[t].x + a[t].l > r) continue;
        b.push_back(make_pair(-(1 << 30), a[t].x + a[t].l));
        g[i + 1][j] = max(g[i + 1][j], g[k][t] + calc(b) - (1 << 30) - a[t].x - a[t].l);
        b.pop_back();
      }
      g[i + 1][j] = max(g[i + 1][j], f[k] + calc(b));
    }
    vector<pair<int, int>> b{make_pair(a[i + 1].x - a[i + 1].l, a[i + 1].x)};
    int k = i, l = a[i + 1].x - a[i + 1].l;
    while (a[k].x >= l) {
      l = min(l, a[k].x - a[k].l);
      b.push_back(make_pair(a[k].x - a[k].l, a[k].x));
      k--;
    }
    for (int t = 0; t <= k; t++) {
      int r = a[t].x + a[t].l;
      if (r > a[i + 1].x) continue;
      b.push_back(make_pair(-(1 << 30), r));
      f[i + 1] = max(f[i + 1], g[k][t] + calc(b) - (1 << 30) - r);
      b.pop_back();
    }
    f[i + 1] = max(f[i + 1], f[k] + calc(b));
    g[i + 1][i + 1] = max(g[i + 1][i + 1], f[i] + a[i + 1].l);
  }
  ans = f[n];
  for (int i = 0; i <= n; i++) ans = max(ans, g[n][i]);
  cout << ans;
}