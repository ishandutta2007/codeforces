#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 2010, INF = 1e9 + 10;

int n, m, g;
int v[N], cnt, s[N];

struct flow {
  struct edge {
    int v, c, f;
    edge(int v = 0, int c = 0, int f = 0) {
      this->v = v;
      this->c = c;
      this->f = f;
    }
  };
  vector <edge> e;
  vector <int> a[N + M];
  int cur[N + M];

  void addedge(int u, int v, int c, int f) {
    a[u].push_back(e.size());
    e.push_back(edge(v, c, f));
  }

  int d[N + M], st[N + M], top;

  bool bfs() {
    for (int i = 0; i <= cnt; i++) {
      d[i] = -1;
    }
    d[0] = 0;
    top = 1;
    st[0] = 0;
    for (int i = 0; i < top; i++) {
      int u = st[i];
      for (int id : a[u]) {
        int v = e[id].v;
        if (d[v] >= 0) {
          continue;
        }
        if (e[id].f < e[id].c) {
          st[top++] = v;
          d[v] = d[u] + 1;
        }
      }
    }
    return d[1] >= 0;
  }

  int dfs(int u, int now) {
    if (now == 0) {
      return 0;
    }
    if (u == 1) {
      return now;
    }
    for (; cur[u] < a[u].size(); cur[u]++) {
      int id = a[u][cur[u]];
      int v = e[id].v;
      int c = e[id].c, f = e[id].f;
      if (d[v] != d[u] + 1) {
        continue;
      }
      if (c <= f) {
        continue;
      }
      int foo = dfs(v, min(now, c - f));
      if (!foo) {
        continue;
      }
      e[id].f += foo;
      e[id ^ 1].f -= foo;
      return foo;
    }
    return 0;
  }

  int maxflow() {
    int res = 0;
    while (bfs()) {
      for (int i = 0; i <= cnt; i++) {
        cur[i] = 0;
      }
      int foo;
      while (1) {
        foo = dfs(0, INF);
        if (!foo) {
          break;
        }
        res += foo;
      }
    }
    return res;
  }
} f;

int main() {
  int sum = 0;
  scanf("%d %d %d", &n, &m, &g);
  for (int i = 1; i <= n; i++) {
    scanf("%d", s + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", v + i);
  }
  for (int i = 1; i <= n; i++) {
    f.addedge(0, i + 1, v[i] * (1 - s[i]), 0);
    f.addedge(i + 1, 0, 0, 0);
    f.addedge(i + 1, 1, v[i] * s[i], 0);
    f.addedge(1, i + 1, 0, 0);
  }
  cnt = n + 1;
  for (int i = 1; i <= m; i++) {
    cnt++;
    int op, w, k, is_friend;
    scanf("%d %d %d", &op, &w, &k);
    sum += w;
    for (int j = 1; j <= k; j++) {
      int u;
      scanf("%d", &u);
      f.addedge(cnt, u + 1, INF * (1 - op), 0);
      f.addedge(u + 1, cnt, INF * op, 0);
    }
    scanf("%d", &is_friend);
    if (is_friend) {
      w += g;
    }
    if (!op) {
      f.addedge(op, cnt, w, 0);
      f.addedge(cnt, op, 0, 0);
    } else {
      f.addedge(op, cnt, 0, 0);
      f.addedge(cnt, op, w, 0);
    }
  }
  int x = f.maxflow();
  cout << sum - x;
  return 0;
}