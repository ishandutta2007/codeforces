#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
int a[N], b[N], l[N], u[N];
int p[N], sz[N], res[N], odd;
pair<int, int> c[N];
vector <int> prep, delta;
vector <pair<int, int> > preroot;

void join(int u) {
  int x = a[u];
  int y = b[u];
  while (p[x] != x) {
    x = p[x];
  }
  while (p[y] != y) {
    y = p[y];
  }
  if (x == y) {
    return;
  }
  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  if (sz[x] % 2 == 1 && sz[y] % 2 == 1) {
    odd -= 2;
    delta.push_back(2);
  } else {
    delta.push_back(0);
  }
  prep.push_back(y);
  preroot.push_back(make_pair(x, sz[x]));
  sz[x] += sz[y];
  p[y] = x;
}

void backup(int pos) {
  while (delta.size() > pos) {
    odd += delta.back();
    delta.pop_back();
    p[prep.back()] = prep.back();
    prep.pop_back();
    sz[preroot.back().first] = preroot.back().second;
    preroot.pop_back();
  }
}

void go(int l, int r, int x, int y) {
  if (l > r) {
    return;
  }
  int now = delta.size();
  int pos = -1;
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; i++) {
    if (u[i] < x) {
      join(i);
    }
  }
  for (int i = x; i <= y; i++) {
    if (c[i].second <= mid) {
      join(c[i].second);
      if (!odd) {
        pos = i;
        break;
      }
    }
  }
  backup(now);
  if (pos == -1) {
    for (int i = l; i <= mid; i++) {
      res[i] = -1;
    }
    for (int i = l; i <= mid; i++) {
      if (u[i] < x) {
        join(i);
      }
    }
    go(mid + 1, r, x, y);
    backup(now);
    return;
  }
  res[mid] = c[pos].first;
  for (int i = x; i < pos; i++) {
    if (c[i].second < l) {
      join(c[i].second);
    }
  }
  go(l, mid - 1, pos, y);
  backup(now);
  for (int i = l; i <= mid; i++) {
    if (u[i] < x) {
      join(i);
    }
  }
  go(mid + 1, r, x, pos);
  backup(now);
}

int main() {
  //freopen("input.txt", "r" ,stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", a + i, b + i, l + i);
    c[i] = make_pair(l[i], i);
  }
  sort(c + 1, c + m + 1);
  for (int i = 1; i <= m; i++) {
    u[c[i].second] = i;
  }
  for (int i = 1; i <= n; i++) {
    sz[i] = 1;
    p[i] = i;
  }
  odd = n;
  go(1, m, 1, m);
  for (int i = 1; i <= m; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}