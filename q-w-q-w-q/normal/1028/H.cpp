#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int N = 200005, V = 5032108;
int n, q, a[N];
int s, pr[1000005], rea[V], qwq[V];
int ans[2000005];
vector<int> d[V];
vector<pair<int, int>> line[N], qy[N];
int st;
pair<int, int> g[111];
bool np[V], u[V];

struct p {
  int top, v[12], p[12];
  void push(int i, int j) {
    while (top && v[top] >= j)
      top--;
    top++, v[top] = j, p[top] = i;
  }
  void join(int i, int j) {
    if (!top) {
      top++;
      v[top] = j, p[top] = i;
      return;
    }

    if (p[top] == i)
      v[top] = min(v[top], j);
    else {
      while (top && v[top] >= j)
        top--;
      top++;
      v[top] = j, p[top] = i;
    }
  }
} f[V];

p merge(p x, p y) {
  p z;
  z.top = 0;
  int i = 1, j = 1;
  while (i <= x.top && j <= y.top) {
    if (x.p[i] < y.p[j])
      z.join(x.p[i], x.v[i]), i++;
    else
      z.join(y.p[j], y.v[j]), j++;
  }

  while (i <= x.top)
    z.join(x.p[i], x.v[i]), i++;
  while (j <= y.top)
    z.join(y.p[j], y.v[j]), j++;
  return z;
}

void init() {
  rea[1] = 1;
  for (int i = 2; i < V; i++) {
    if (!np[i])
      pr[++s] = i, rea[i] = i, qwq[i] = 1;

    for (int j = 1; j <= s && i * pr[j] < V; j++) {
      np[i * pr[j]] = 1;
      if (rea[i] % pr[j] == 0)
        rea[i * pr[j]] = rea[i] / pr[j];
      else
        rea[i * pr[j]] = rea[i] * pr[j];
      if (i % pr[j] == 0) {
        qwq[i * pr[j]] = qwq[i];
        break;
      }

      qwq[i * pr[j]] = qwq[i] + 1;
    }
  }
}

void gu() {
  static pair<int, int> f[111];
  int cnt = 0;
  for (int i = 1; i <= st; i++) {
    if (g[i].first > f[cnt].first || cnt == 0) {
      if (g[i].second > f[cnt].second || cnt == 0)
        f[++cnt] = g[i];
    } else
      f[cnt] = g[i];
  }

  st = cnt;
  for (int i = 1; i <= st; i++)
    g[i] = f[i];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> q;
  init();
  for (int i = 1; i <= n; i++)
    cin >> a[i], u[a[i] = rea[a[i]]] = 1;

  for (int i = 1; i < V; i++)
    for (int j = i; j < V; j += i)
      if (u[j])
        d[j].push_back(i);

  for (int i = 1; i <= n; i++) {
    p tp;
    tp.top = 0;
    for (int x : d[a[i]]) {
      p g = f[x];
      for (int j = 1; j <= g.top; j++)
        g.v[j] = g.v[j] - 2 * qwq[x] + qwq[a[i]];
      f[x].push(i, qwq[a[i]]);
      tp = merge(tp, g);
    }
    for (int j = 1; j <= tp.top; j++)
      line[i].push_back(make_pair(tp.p[j], tp.v[j]));
  }

  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    qy[r].push_back(make_pair(l, i));
  }

  for (int i = 1; i <= n; i++) {
    for (auto tp : line[i])
      g[++st] = make_pair(tp.second, tp.first);
    sort(g + 1, g + st + 1);
    gu();

    for (auto tp : qy[i]) {
      for (int j = 1; j <= st; j++)
        if (g[j].second >= tp.first) {
          ans[tp.second] = g[j].first;
          break;
        }
    }
  }

  for (int i = 1; i <= q; i++)
    cout << ans[i] << '\n';
}