#include <bits/stdc++.h>

using namespace std;

const int N = 100010, INF = 1 << 30;

int n, m;
vector <int> a[2][N];
int res, curRes;
vector <int> ans, curAns;
int used[N], q[N], top;

bool bfs(int root, int x) {
  vector <int> val[3];
  used[root] = 1;
  q[top = 1] = root;
  int tot = 0, cnt = 0;
  for (int i = 1; i <= top; i++) {
    int u = q[i];
    val[used[u]].push_back(u);
    tot++;
    cnt += used[u] == 1;
    for (int v : a[x][u]) {
      if (!used[v]) {
        q[++top] = v;
        used[v] = 3 - used[u];
      } else {
        if (used[v] == used[u]) {
          return 0;
        }
      }
    }
    for (int v : a[x ^ 1][u]) {
      if (!used[v]) {
        q[++top] = v;
        used[v] = used[u];
      } else {
        if (used[v] != used[u]) {
          return 0;
        }
      }
    }
  }
  if (tot - cnt > cnt) {
    curRes += cnt;
    for (int u : val[1]) {
      curAns.push_back(u);
    }
  } else {
    curRes += tot - cnt;
    for (int u : val[2]) {
      curAns.push_back(u);
    }
  }
  return 1;
}

void go(int x) {
  curAns.clear();
  curRes = 0;
  memset(used, 0, sizeof used);
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      if (!bfs(i, x)) {
        return;
      }
    }
  }
  if (res > curRes) {
    res = curRes;
    ans = curAns;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    char w;
    scanf("%d %d %c", &u, &v, &w);
    if (w == 'R') {
      a[0][u].push_back(v);
      a[0][v].push_back(u);
    } else {
      a[1][u].push_back(v);
      a[1][v].push_back(u);
    }
  }
  res = INF;
  go(0);
  go(1);
  if (res >= INF) {
    puts("-1");
    return 0;
  }
  printf("%d\n", res);
  for (int u : ans) {
    printf("%d ", u);
  }
  return 0;
}