#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n;
vector <pair<int, int> > odd, even;

struct flow {
  struct edge {
    int v, f, c;

    edge(int _v = 0, int _f = 0, int _c = 0) {
      v = _v;
      f = _f;
      c = _c;
    }
  };

  int d[N], cur[N], q[N], top, cnt;
  vector <int> a[N];
  vector <edge> e;
  vector <int> res[N];

  void add(int u, int v, int c) {
    a[u].push_back(e.size());
    e.push_back(edge(v, 0, c));
    a[v].push_back(e.size());
    e.push_back(edge(u, 0, 0));
  }

  bool bfs() {
    for (int i = 1; i <= n + 2; i++) {
      d[i] = -1;
    }
    d[n + 1] = 0;
    q[0] = n + 1;
    top = 1;
    for (int x = 0; x < top; x++) {
      int u = q[x];
      for (int i = 0; i < a[u].size(); i++) {
        int id = a[u][i];
        int v = e[id].v;
        if (d[v] < 0 && e[id].f < e[id].c) {
          d[v] = d[u] + 1;
          q[top++] = v;
        }
      }
    }
    return d[n + 2] > 0;
  }

  int dfs(int u, int val) {
    if (u == n + 2) {
      return val;
    }
    for (;cur[u] < a[u].size(); cur[u]++) {
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
      for (int i = 1; i <= n + 2; i++) {
        cur[i] = 0;
      }
      while (1) {
        int f = dfs(n + 1, 2e9);
        if (!f) {
          break;
        }
        res += f;
      }
    }
    return res;
  }

  void go(int u) {
    res[cnt].push_back(u);
    d[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
      int id = a[u][i];
      int v = e[id].v;
      if (!d[v] && e[id].f != 0 && v <= n) {
        go(v);
      }
    }
  }

  void trace() {
    for (int i = 1; i <= n; i++) {
      d[i] = 0;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!d[i]) {
        cnt++;
        go(i);
      }
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
      cout << res[i].size() << " ";
      for (int j = 0; j < res[i].size(); j++) {
        cout << res[i][j] << " ";
      }
      cout << endl;
    }
  }
};

bool check(int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef Doflamingo
  freopen("inp.txt", "r", stdin);
#endif // Doflamingo
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    if (u & 1) {
      odd.push_back(make_pair(u, i));
    } else {
      even.push_back(make_pair(u, i));
    }
  }
  if (odd.size() != even.size()) {
    puts("Impossible");
    return 0;
  }
  flow f;
  for (int i = 0; i < odd.size(); i++) {
    for (int j = 0; j < even.size(); j++) {
      if (check(odd[i].first + even[j].first)) {
        f.add(odd[i].second, even[j].second, 1);
      }
    }
  }
  for (int i = 0; i < odd.size(); i++) {
    f.add(n + 1, odd[i].second, 2);
    f.add(even[i].second, n + 2, 2);
  }
  if (f.maxflow() != n) {
    puts("Impossible");
    return 0;
  }
  f.trace();
  return 0;
}