#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
typedef pair<int, int> pi;

int n, m;
vector <pi> a[N];
int d[N], st[N], cnt, d2[N];
vector <int> x[N];
int lv[N];
int c[N];
pi b[N];
int pre[N];

void bfs() {
  for (int i = 1; i < n; i++) {
    d[i] = 1e9;
  }
  st[0] = 0;
  cnt = 1;
  for (int i = 0; i < cnt; i++) {
    int u = st[i];
    for (pi v : a[u]) {
      if (d[v.first] >= 1e9) {
        d[v.first] = d[u] + 1;
        x[d[u] + 1].push_back(v.first);
        st[cnt++] = v.first;
      }
    }
  }
}

void bfs2() {
  for (int i = 0; i < n; i++) {
    d2[i] = 1e9;
  }
  d2[n - 1] = 0;
  st[0] = n - 1;
  cnt = 1;
  for (int i = 0; i < cnt; i++) {
    int u = st[i];
    for (pi v : a[u]) {
      if (d2[v.first] >= 1e9 && v.second == 0) {
        d2[v.first] = d2[u] + 1;
        pre[v.first] = u;
        st[cnt++] = v.first;
      }
    }
  }
}

bool cmp(int u, int v) {
  if (b[u].first != b[v].first) {
    return b[u].first < b[v].first;
  }
  return lv[b[u].second] < lv[b[v].second];
}

int main() {
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, len;
    scanf("%d %d %d", &u, &v, &len);
    a[u].push_back(pi(v, len));
    a[v].push_back(pi(u, len));
  }
  bfs();
  bfs2();
  b[0] = make_pair(0, 0);
  c[0] = lv[0] = 0;
  int cur = 1;
  for (int len = 1; len <= d[n - 1]; len++) {
    int next = cur;
    for (int u : x[len]) {
      c[next++] = u;
      b[u] = make_pair(1e9, 1e9);
      for (pi v : a[u]) {
        if (d[v.first] != d[u] - 1) {
          continue;
        }
        if (v.second > b[u].first) {
          continue;
        }
        if (v.second == b[u].first) {
          if (lv[v.first] < lv[b[u].second]) {
            b[u].second = v.first;
          }
        }
        if (v.second < b[u].first) {
          b[u] = pi(v.second, v.first);
        }
      }
    }
    sort(c + cur, c + next, cmp);
    lv[c[cur]] = lv[c[cur - 1]] + 1;
    for (int i = cur + 1; i < next; i++) {
      int u = c[i], v = c[i - 1];
      lv[u] = lv[v] + cmp(v, u);
    }
    cur = next;
  }
  int pos = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (d2[i] >= 1e9) {
      continue;
    }
    if (d[i] > d[pos]) {
      continue;
    }
    if (d[i] < d[pos]) {
      pos = i;
      continue;
    }
    if (lv[i] > lv[pos]) {
      continue;
    }
    if (lv[i] < lv[pos]) {
      pos = i;
      continue;
    }
    if (d2[i] < d2[pos]) {
      pos = i;
    }
  }
  int foo = pos;
  vector <int> path, res;
  while (foo) {
    path.push_back(foo);
    res.push_back(b[foo].first);
    foo = b[foo].second;
  }
  path.push_back(0);
  for (int i : res) {
    printf("%d", i);
  }
  if (res.empty()) {
    printf("0");
  }
  printf("\n");
  reverse(path.begin(), path.end());
  foo = pos;
  while (foo != n - 1) {
    foo = pre[foo];
    path.push_back(foo);
  }
  printf("%d\n", path.size());
  for (int i : path) {
    printf("%d ", i);
  }
  return 0;
}