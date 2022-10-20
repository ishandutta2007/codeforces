#include <bits/stdc++.h>

using namespace std;

const int N = 100, V = 100010;
const int dirI[] = {0, 1, 0, -1};
const int dirJ[] = {1, 0, -1, 0};

int a[N][N];
int n, m;

struct flow {
  int head[V], to[V], nxt[V], c[V], cost[V], f[V], h[V], par[V];
  bool inQueue[V];
  int n, s, t, cnt;

  flow (int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    for (int i = 0; i < n; i++) {
      head[i] = -1;
    }
    cnt = 0;
  }

  void addEdge(int u, int v, int _c, int _cost) {
    to[cnt] = v, c[cnt] = _c, cost[cnt] = _cost, f[cnt] = 0, nxt[cnt] = head[u], head[u] = cnt++;
    to[cnt] = u, c[cnt] = 0, cost[cnt] = -_cost, f[cnt] = 0, nxt[cnt] = head[v], head[v] = cnt++;
  }

  int maxFlow() {
    int res = 0;
    while (1) {
      for (int i = 0; i < n; i++) {
        h[i] = 2e9;
        inQueue[i] = 0;
        par[i] = -1;
      }
      queue <int> q;
      h[s] = 0;
      inQueue[s] = 1;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for (int id = head[u]; id != -1; id = nxt[id]) {
          int v = to[id];
          if (h[v] > h[u] + cost[id] && c[id] > f[id]) {
            h[v] = h[u] + cost[id];
            par[v] = id;
            if (!inQueue[v]) {
              q.push(v);
              inQueue[v] = 1;
            }
          }
        }
      }
      if (par[t] == -1) {
        break;
      }
      int x = t;
      int now = 2e9;
      while (x != s) {
        int id = par[x];
        now = min(now, c[id] - f[id]);
        x = to[id ^ 1];
      }
      x = t;
      while (x != s) {
        int id = par[x];
        res += now * cost[id];
        f[id] += now;
        f[id ^ 1] -= now;
        x = to[id ^ 1];
      }
    }
//    cout << endl;
//    for (int i = 0; i < cnt; i++) {
//      if (f[i] > 0 && to[i ^ 1] != s && to[i] != t) {
//        cout << to[i ^ 1] << " " << to[i] << " " << cost[i] << endl;
//      }
//    }
    return res;
  }
};

int main() {
  scanf("%d %d", &n, &m);
  flow f(n * m + 2, n * m, n * m + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0;  j < m; j++) {
      if ((i + j) & 1) {
        f.addEdge(i * m + j, f.t, 1, 0);
      } else {
        f.addEdge(f.s, i * m + j, 1, 0);
        for (int k = 0; k < 4; k++) {
          int ii = i + dirI[k];
          int jj = j + dirJ[k];
          if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
            continue;
          }
          f.addEdge(i * m + j, ii * m + jj, 1, a[i][j] != a[ii][jj]);
        }
      }
    }
  }
  cout << f.maxFlow() << endl;
  return 0;
}