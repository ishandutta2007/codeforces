#include <bits/stdc++.h>

using namespace std;

const long long N = 1000, V = 100000;

long long n, m, x;
long long a[N], b[N], c[N];

struct flow {
  long long head[V], to[V], nxt[V], c[V], f[V], h[V], cur[V];
  long long q[V], top;
  long long n, s, t, cnt;

  flow(long long n, long long s, long long t) {
    this->n = n;
    this->s = s;
    this->t = t;
    for (long long i = 0; i < n; i++) {
      head[i] = -1;
    }
    cnt = 0;
  }

  void addEdge(long long u, long long v, long long _c) {
    to[cnt] = v, f[cnt] = 0, c[cnt] = _c, nxt[cnt] = head[u], head[u] = cnt++;
    to[cnt] = u, f[cnt] = 0, c[cnt] = 0, nxt[cnt] = head[v], head[v] = cnt++;
  }


  bool bfs() {
    for (long long i = 0; i < n; i++) {
      h[i] = -1;
    }
    h[s] = 0;
    top = 1;
    q[0] = s;
    for (long long i=  0; i < top; i++) {
      long long u = q[i];
      for (long long id = head[u]; id != -1; id = nxt[id]) {
        long long v = to[id];
        if (h[v] == -1 && f[id] < c[id]) {
          h[v] = h[u] + 1;
          q[top++] = v;
        }
      }
    }
    return h[t] > 0;
  }

  long long dfs(long long u, long long now) {
    if (u == t) {
      return now;
    }
    for (long long &id = cur[u]; id != -1; id = nxt[id]) {
      long long v = to[id];
      if (h[v] == h[u] + 1 && f[id] < c[id]) {
        long long foo = dfs(v, min(now, c[id] - f[id]));
        if (foo) {
          f[id] += foo;
          f[id ^ 1] -= foo;
          return foo;
        }
      }
    }
    return 0;
  }

  long long maxFlow() {
    long long res = 0;
    while (bfs()) {
      for (long long i = 0; i < n; i++) {
        cur[i] = head[i];
      }
      while (1) {
        long long f = dfs(s, 1e15);
        if (!f) {
          break;
        }
        res += f;
      }
    }
    return res;
  }
};

bool check(long double u) {
  flow f(n, 0, n - 1);
  for (long long i = 1; i <= m; i++) {
    long double y = 1.0 * c[i] / u;
    y = min(y, (long double)x);
    long long yy = y;
    if (!yy) {
      continue;
    }
    f.addEdge(a[i], b[i], yy);
  }
  long long res = f.maxFlow();
  return res >= x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> x;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
  }
  long double low = 0.0, high = 1e10;
  for (long long i = 1; i <= 300; i++) {
    long double mid = (high + low) / 2.;
    if (check(mid)) {
      low = mid;
    } else {
      high = mid;
    }
  }
  printf("%0.17f", (double)low * x);
  return 0;
}