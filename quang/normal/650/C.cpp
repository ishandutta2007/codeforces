#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int curX[N], curY[N];
pair<int, pair<int, int> > a[N];
vector <vector<int> > res;
int n, m;
vector <pair<int, int > > dirX[N], dirY[N];
vector <vector<int> > used;
int foo;
pair<int, int> st[N];
int top;
int usedX[N], usedY[N];

void bfs(int u, int v) {
  st[top = 1] = make_pair(u, v);
  used[u][v] = 1;
  for (int i = 1; i <= top; i++) {
    u = st[i].first;
    v = st[i].second;
    foo = max(foo, curX[u] + 1);
    foo = max(foo, curY[v] + 1);
    if (!usedX[u]) {
      for (int j = 0; j < dirX[u].size(); j++) {
        pair<int, int> bar = dirX[u][j];
        if (!used[bar.first][bar.second]) {
          used[bar.first][bar.second] = 1;
          st[++top] = bar;
        }
      }
      usedX[u] = 1;
    }

    if (!usedY[v]) {
      for (int j = 0; j < dirY[v].size(); j++) {
        pair<int, int> bar = dirY[v][j];
        if (!used[bar.first][bar.second]) {
          used[bar.first][bar.second] = 1;
          st[++top] = bar;
        }
      }
      usedY[v] = 1;
    }
  }
  for (int i = 1; i <= top; i++) {
    u = st[i].first;
    v = st[i].second;
    res[u][v] = foo;
    curX[u] = foo;
    curY[v] = foo;
    usedX[u] = usedY[v] = 0;
    if (!dirX[u].empty()) {
      dirX[u].clear();
    }
    if (!dirY[v].empty()) {
      dirY[v].clear();
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  res.resize(n + 1, vector<int> (m + 1, 0));
  used.resize(n + 1, vector<int> (m + 1, 0));
  int top = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int u;
      scanf("%d", &u);
      a[++top] = make_pair(u, make_pair(i, j));
    }
  }
  sort(a + 1, a + top + 1);
  for (int i = 1; i <= top;) {
    int last = i;
    while (last < top && a[last + 1].first == a[i].first) {
      last++;
    }
    for (int j = i; j <= last; j++) {
      dirX[a[j].second.first].push_back(a[j].second);
      dirY[a[j].second.second].push_back(a[j].second);
    }
    for (int j = i; j <= last; j++) {
      if (used[a[j].second.first][a[j].second.second]) {
        continue;
      }
      foo = 0;
      bfs(a[j].second.first, a[j].second.second);
    }
    i = last + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}