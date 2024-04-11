#include <bits/stdc++.h>

using namespace std;

const int N = 250, M = 30;
const int V = 1e6;

int n, m;
int a[N];
int edge[M][N];
int edge1[N][N];

struct Flow {
  int head[V], to[V], c[V], cost[V], f[V], nxt[V], h[V], par[V], inQueue[V];
  int s, t, n, cnt;
  queue <int> q;
  Flow (int n, int s, int t) {
    this->n = n;
    this->s = s;
    this->t = t;
    cnt = 0;
    for (int i=  0; i < n; i++) {
      head[i] = -1;
      inQueue[i] = 0;
    }
  }

  int addEdge(int u, int v, int _c, int _cost) {
    to[cnt] = v, c[cnt] = _c, cost[cnt] = _cost, f[cnt] = 0, nxt[cnt] = head[u], head[u] = cnt++;
    to[cnt] = u, c[cnt] = 0, cost[cnt] = -_cost, f[cnt] = 0, nxt[cnt] = head[v], head[v] = cnt++;
    return cnt - 2;
  }

  pair<int, int> maxFlow () {
    int res = 0, minCost = 0;
    while (1) {
      for (int i = 0; i < n; i++) {
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
      x = t;
      while (x != s) {
        int id = par[x];
        minCost += cost[id] * now;
        f[id] += now;
        f[id ^ 1] -= now;
        x = to[id ^ 1];
      }
      res += now;
    }
    return make_pair(res, minCost);
  }
};

vector <pair<int, int> > ans;
int cur[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  Flow f((n + m) * 2 + 2, (n + m) * 2, (n + m) * 2 + 1);
  for (int i = 0; i < n + m; i++) {
    f.addEdge(f.s, i, 1, 0);
  }
  for (int i = n + m; i < f.s; i++) {
    f.addEdge(i, f.t, 1, 0);
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      edge[i][j] = f.addEdge(i, j + m + m + n, 1, __builtin_popcount(a[j]));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edge1[i][j] = f.addEdge(i + m, j + m + m + n, 1, __builtin_popcount(a[j]) * (a[j] != a[i]));
    }
  }
  pair<int, int> res = f.maxFlow();
  int q[N], top = 0;
  for (int i = 0; i < m; i++) {
    int pos = -1;
    for (int j = 0; j < n; j++) {
      if (f.f[edge[i][j]] > 0) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      continue;
    }
    q[top++] = pos;
    ans.push_back(make_pair(pos, i));
    cur[pos] = i;
  }
  for (int id = 0; id < top; id++) {
    int u = q[id];
    int pos = -1;
    for (int j = u + 1; j < n; j++) {
      if (f.f[edge1[u][j]] > 0) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      continue;
    }
    q[top++] = pos;
    if (a[u] != a[pos]) {
      ans.push_back(make_pair(pos, cur[u]));
    }
    cur[pos] = cur[u];
  }
  printf("%d %d\n", n + ans.size(), res.second);
  sort(ans.begin(), ans.end());
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (now < ans.size() && ans[now].first == i) {
      printf("%c=%d\n", cur[i] + 'a', a[i]);
      now++;
    }
    printf("print(%c)\n", cur[i] + 'a');
  }
  return 0;
}