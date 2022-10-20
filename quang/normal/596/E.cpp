#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, m, q;
char s[N][N], model[1000010];
int a[10], b[10];
int c[N * N];
int used[N * N], cycle[N * N];
vector <int> pre[N * N];
int last[10], flag;

char digit(int u) {
  int x = u / m;
  int y = u % m;
  return s[x][y];
}

void go(int u, int pos) {
  if (pos == -1) {
    flag = 1;
    return;
  }
  for (int v : pre[u]) {
    if (cycle[v]) {
      continue;
    }
    char xx = digit(v);
    go(v, pos - (xx == model[pos]));
    if (flag) {
      return;
    }
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i <= 9; i++) {
    scanf("%d %d", a + i, b + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i + a[s[i][j] - '0'];
      int y = j + b[s[i][j] - '0'];
      if (x < 0 || x >= n || y < 0 || y >= m) {
        x = i;
        y = j;
      }
      c[i * m + j] = x * m + y;
    }
  }
  n *= m;
  for (int i = 0; i < n; i++) {
    pre[c[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    vector <int> p;
    int cur = i;
    while (!used[cur]) {
      used[cur] = 1;
      p.push_back(cur);
      cur = c[cur];
    }
    int pos = -1;
    for (int i = 0; i < p.size(); i++) {
      if (p[i] == cur) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      continue;
    }
    int mask = 0;
    for (int i = pos; i < p.size(); i++) {
      int x = p[i] / m;
      int y = p[i] % m;
      mask |= (1 << (s[x][y] - '0'));
    }
    for (int i = pos; i < p.size(); i++) {
      cycle[p[i]] = mask;
    }
  }
  while (q--) {
    scanf("%s", model);
    int m2 = strlen(model);
    for (int i = 0; i < 10; i++) {
      last[i] = -1;
    }
    for (int i = 0; i < m2; i++) {
      last[model[i] - '0'] = i;
    }
    flag = 0;
    for (int i = 0; i < n; i++) {
      if (!cycle[i]) {
        continue;
      }
      int pos = -1;
      for (int j = 0; j < 10; j++) {
        if (cycle[i] & (1 << j)) {
          continue;
        }
        pos = max(pos, last[j]);
      }
      go(i, pos);
      if (flag) {
        break;
      }
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}