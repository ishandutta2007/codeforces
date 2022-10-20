#include <bits/stdc++.h>

using namespace std;

const int N = 400010;
typedef pair<int, int> pi;

int n, m;
vector <pi> a[N];
int low[N], num[N], visited[N];
int used[N], dfsCount;
int maxCnt = 0, posMaxCnt = 0;
int st[N], topStack;
int belong[N];
vector <pi> b[N];
int res[N];
int from[N], to[N];

void dfs(int u) {
  low[u] = num[u] = ++dfsCount;
  visited[u] = 1;
  st[++topStack] = u;
  for (pi v : a[u]) {
    if (used[v.second]) {
      continue;
    }
    used[v.second] = 1;
    if (!visited[v.first]) {
      dfs(v.first);
    }
    low[u] = min(low[u], low[v.first]);
  }
  if (num[u] == low[u]) {
    int cnt = 0;
    while (1) {
      int v = st[topStack--];
      belong[v] = u;
      cnt++;
      if (v == u) {
        break;
      }
    }
    if (cnt > maxCnt) {
      maxCnt = cnt;
      posMaxCnt = u;
    }
  }
}

void go(int u) {
  visited[u] = 1;
  for (pi v : a[u]) {
    if (used[v.second]) {
      continue;
    }
    used[v.second] = 1;
    if (from[v.second] == u) {
      res[v.second] = 0;
    } else {
      res[v.second] = 1;
    }
    if (!visited[v.first]) {
      go(v.first);
    }
  }
}

void go1(int u, int par) {
  for (pi v : b[u]) {
    if (v.first == par) {
      continue;
    }
    if (u == belong[from[v.second]]) {
      res[v.second] = 1;
    } else {
      res[v.second] = 0;
    }
    go1(v.first, u);
  }
}

int main() {
//  freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    from[i] = u;
    to[i] = v;
    a[u].push_back(pi(v, i));
    a[v].push_back(pi(u, i));
  }
  dfs(1);
  memset(visited, 0, sizeof visited);
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      go(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (belong[from[i]] != belong[to[i]]) {
      b[belong[from[i]]].push_back(pi(belong[to[i]], i));
      b[belong[to[i]]].push_back(pi(belong[from[i]], i));
    }
  }
  go1(posMaxCnt, 0);
  printf("%d\n", maxCnt);
  for (int i = 1; i <= m; i++) {
    if (res[i]) {
      printf("%d %d\n", to[i], from[i]);
    } else {
      printf("%d %d\n", from[i], to[i]);
    }
  }
  return 0;
}