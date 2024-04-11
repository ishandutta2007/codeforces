#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, g, r, period;
long long l[N], dp[N];
int canstart[N];
int a[N], tot;

struct it {
  int t[N * 4];

  void init() {
    for (int i = 0; i < N * 4; i++) {
      t[i] = n + 1;
    }
  }

  void add(int node, int l, int r, int x, int y, int val) {
    if (x > r || y < l) {
      return;
    }
    if (x <= l && r <= y) {
      t[node] = min(t[node], val);
      return;
    }
    int m = (l + r) >> 1;
    add(node + node, l, m, x, y, val);
    add(node + node + 1, m + 1, r, x, y, val);
  }

  int get(int node, int l, int r, int x) {
    if (x > r || x < l) {
      return n + 1;
    }
    if (l == r) {
      return t[node];
    }
    int m = (l + r) >> 1;
    int p1 = get(node + node, l, m, x);
    int p2 = get(node + node + 1, m + 1, r, x);
    return min(p1, min(p2, t[node]));
  }
} t;

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &g, &r);
  period = g + r;
  for (int i = 1; i <= n + 1; i++) {
    int u;
    scanf("%d", &u);
    l[i] = l[i - 1] + u;
  }
  a[tot = 1] = 0;
  for (int i = 1; i <= n; i++) {
    //green
    int x = ((-l[i] % period) + period) % period;
    canstart[i] = x;
    a[++tot] = x;
    //red
    x = ((-l[i] + g) % period + period) % period;
    a[++tot] = x;
  }
  t.init();
  sort(a + 1, a + tot + 1);
  tot = unique(a + 1, a + tot + 1) - a - 1;
  for (int i = n; i >= 0; i--) {
    //get dp[i]
    int x = ((-l[i] % period) + period) % period;
    int pos = upper_bound(a + 1, a + tot + 1, x) - a - 1;
    pos = t.get(1, 1, tot, pos);
    if (pos == n + 1) {
      dp[i] = l[n + 1] - l[i];
    } else {
      dp[i] = dp[pos] + l[pos] - l[i];
      dp[i] += canstart[pos] - x;
      if (x > canstart[pos]) {
        dp[i] += period;
      }
    }
    //update in it
    if (!i) {
      continue;
    }
    x = ((-l[i] + g) % period + period) % period;
    int y = ((-l[i] - 1) % period + period) % period;
    int posx = upper_bound(a + 1, a + tot + 1, x) - a - 1;
    int posy = upper_bound(a + 1, a + tot + 1, y) - a - 1;
    if (posx <= posy) {
      t.add(1, 1, tot, posx, posy, i);
    } else {
      t.add(1, 1, tot, 1, posy, i);
      t.add(1, 1, tot, posx, tot, i);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int timestart;
    scanf("%d", &timestart);
    long long res = timestart;
    timestart %= period;
    int pos = upper_bound(a + 1, a + tot + 1, timestart) - a - 1;
    int x = t.get(1, 1, tot, pos);
    if (x == n + 1) {
      res += l[n + 1];
    } else {
      res += l[x] + dp[x];
      res += canstart[x] - timestart;
      if (canstart[x] < timestart) {
        res += period;
      }
    }
    printf("%I64d\n", res);
  }
  return 0;
}