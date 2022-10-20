#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, m;
int a[N], b[N], suma, sumb;
int res[N][N];

struct flow {
  struct edge {
    int v, f, c;
    edge() {};
    edge(int v, int f, int c) {
      this->v = v;
      this->f = f;
      this->c = c;
    }
  };

  vector <edge> e;
  vector <int> a[N * 2];
  int d[N * 2], q[N * 2], top, cur[N * 2];

  void add(int u, int v, int c) {
    a[u].push_back(e.size());
    e.push_back(edge(v, 0, c));
    a[v].push_back(e.size());
    e.push_back(edge(u, 0, 0));
  }

  bool bfs() {
    for (int i = 1; i <= n + n + 1; i++) {
      d[i] = -1;
    }
    d[0] = 0;
    top = 1;
    q[0] = 0;
    for (int i = 0; i < top; i++) {
      int u = q[i];
      for (int j = 0; j < a[u].size(); j++) {
        int id = a[u][j];
        int v = e[id].v;
        if (d[v] == -1 && e[id].f < e[id].c) {
          q[top++] = v;
          d[v] = d[u] + 1;
        }
      }
    }
    return d[n + n + 1] >= 0;
  }

  int dfs(int u, int val) {
    if (u == n + n + 1) {
      return val;
    }
    for (; cur[u] < a[u].size(); cur[u]++) {
      int id = a[u][cur[u]];
      int v = e[id].v;
      if (d[v] != d[u] + 1 || e[id].f >= e[id].c) {
        continue;
      }
      int foo = dfs(v, min(val, e[id].c - e[id].f));
      if (foo) {
        e[id].f += foo;
        e[id ^ 1].f -= foo;
        return foo;
      }
    }
    return 0;
  }

  int maxflow() {
    int res = 0;
    while (bfs()) {
      for (int i = 0; i <= n + n + 1; i++) {
        cur[i] = 0;
      }
      while (1) {
        int foo = dfs(0, 1e9);
        if (!foo) {
          break;
        }
        res += foo;
      }
    }
    return res;
  }

  void trace() {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < a[i].size(); j++) {
        int id = a[i][j];
        int v = e[id].v;
        int f = e[id].f;
        if (v > n && v <= n + n) {
          res[i][v - n] = f;
        }
      }
    }
  }
} f;

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    suma += a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sumb += b[i];
  }
  if (suma != sumb) {
    puts("NO");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    f.add(i, i + n, 1e9);
    f.add(0, i, a[i]);
    f.add(i + n, n + n + 1, b[i]);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    f.add(u, v + n, 1e9);
    f.add(v, u + n, 1e9);
  }
  if (f.maxflow() == suma) {
    cout << "YES\n";
    f.trace();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    puts("NO");
  }
  return 0;
}