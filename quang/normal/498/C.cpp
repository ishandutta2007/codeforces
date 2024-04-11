#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int cnt = 0;
int a[N];
map<pair<int, int>, int> M;
vector <pair<int, int> > p[N];

struct flow {
  struct edge {
    int v, f, c;

    edge(int _v = 0, int _f = 0, int _c = 0) {
      v = _v;
      f = _f;
      c = _c;
    }
  };

  int top;
  vector <int> d, cur, q;
  vector <vector <int> > a;
  vector <edge> e;

  void init(int u) {
    d.resize(u);
    a.resize(u);
    q.resize(u);
    cur.resize(u);
  }

  void add(int u, int v, int c) {
    a[u].push_back(e.size());
    e.push_back(edge(v, 0, c));
    a[v].push_back(e.size());
    e.push_back(edge(u, 0, 0));
  }

  bool bfs() {
    for (int i = 0; i <= cnt + 1; i++) {
      d[i] = -1;
    }
    d[0] = 0;
    q[0] = 0;
    top = 1;
    for (int i = 0; i < top; i++) {
      int u = q[i];
      for (int j = 0; j < a[u].size(); j++) {
        int id = a[u][j];
        int v = e[id].v;
        if (d[v] < 0 && e[id].f < e[id].c) {
          d[v] = d[u] + 1;
          q[top++] = v;
        }
      }
    }
    return d[cnt + 1] > 0;
  }

  int dfs(int u, int val) {
    if (u == cnt + 1) {
      return val;
    }
    for (int i = 0; i < a[u].size(); i++) {
      int id = a[u][i];
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
      for (int i = 0; i <= cnt + 1; i++) {
        cur[i] = 0;
      }
      while (1) {
        int foo = dfs(0, 2e9);
        if (!foo) {
          break;
        }
        res += foo;
      }
    }
    return res;
  }
} f;

void go(int u) {
  int x = a[u];
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      M[make_pair(i, u)] = ++cnt;
      int cur = 0;
      while (x % i == 0) {
        x /= i;
        cur++;
      }
      p[u].push_back(make_pair(i, cur));
    }
  }
  if (x > 1) {
    M[make_pair(x, u)] = ++cnt;
    p[u].push_back(make_pair(x, 1));
  }
}

void go2(int u, int v, int x) {
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        x /= i;
        cnt++;
      }
      f.add(M[make_pair(i, u)], M[make_pair(i, v)], cnt);
    }
  }
  if (x > 1) {
    f.add(M[make_pair(x, u)], M[make_pair(x, v)], 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    go(i);
  }
  f.init(cnt + 10);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u & 1) {
      swap(u, v);
    }
    go2(u, v, __gcd(a[u], a[v]));
  }
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      for (int j = 0; j < p[i].size(); j++) {
        f.add(M[make_pair(p[i][j].first, i)], cnt + 1, p[i][j].second);
      }
    } else {
      for (int j = 0; j < p[i].size(); j++) {
        f.add(0, M[make_pair(p[i][j].first, i)], p[i][j].second);
      }
    }
  }
  /*for (int i = 0; i <= cnt + 1; i++) {
    cout << i <<  " : \n";
    for (int j = 0; j < f.a[i].size(); j++) {
      int id = f.a[i][j];
      cout << f.e[id].v << " " << f.e[id].c << endl;
    }
    cout << endl;
  }*/
  cout << f.maxflow() << endl;
  return 0;
}