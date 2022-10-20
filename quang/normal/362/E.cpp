#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, k;

struct flow {
  int head[N], nxt[N], to[N], c[N], f[N], cost[N], h[N], par[N], inQueue[N];
  queue <int> q;
  int n, s, t, cnt;

  flow(int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    cnt = 0 ;
    for (int i = 0; i < n; i++) {
      head[i] = -1;
      inQueue[i] = 0;
    }
  }

  void addEdge(int u, int v, int _c, int _cost) {
    to[cnt] = v, c[cnt] = _c, cost[cnt] = _cost, f[cnt] = 0, nxt[cnt] = head[u], head[u] = cnt++;
    to[cnt] = u, c[cnt] = 0, cost[cnt] = -_cost, f[cnt] = 0, nxt[cnt] = head[v], head[v] = cnt++;
  }

  pair<int, int> maxFlow(int lim) {
    int res = 0, minCost = 0;
    while (1) {
      for (int i=  0; i < n; i++) {
        par[i] = -1;
        h[i] = 2e9;
      }
      h[s] = 0;
      q.push(s);
      inQueue[s] = 1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for (int id = head[u]; id != -1; id = nxt[id]) {
          int v = to[id];
          if (h[v] > h[u] + cost[id] && f[id] < c[id]) {
            h[v] = h[u] + cost[id];
            par[v] = id;
            if (!inQueue[v]) {
              inQueue[v] = 1;
              q.push(v);
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
      if (h[t] != 0) {
        now = min(now, (lim - minCost) / h[t]);
      }
      if (now <= 0) {
        break;
      }
      x = t;
      res += now;
      while (x != s) {
        int id = par[x];
        f[id] += now;
        f[id ^ 1] -= now;
        minCost += now * cost[id];
        x = to[id ^ 1];
      }
    }
    return make_pair(res, minCost);
  }
};

int main() {
  scanf("%d %d", &n, &k);
  flow f(n + 2, 0, n + 1);
  f.addEdge(0, 1, 2e9, 0);
  f.addEdge(n, n + 1, 2e9, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int u;
      scanf("%d", &u);
      if (u) {
        f.addEdge(i, j, u, 0);
        f.addEdge(i, j, 2e9, 1);
      }
    }
  }
  pair<int, int> res = f.maxFlow(k);
  cout << res.first << endl;
  return 0;
}