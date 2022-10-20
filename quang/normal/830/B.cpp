#include <bits/stdc++.h>

using namespace std;

const int N = 200020, INF = 1e9;

int n;
int a[N], b[N];
int t[N << 2], cnt[N << 2];

void init(int node, int l, int r) {
  if (l == r) {
    t[node] = a[l];
    cnt[node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  init(node << 1, l, m);
  init(node << 1 | 1, m + 1, r);
  t[node] = min(t[node << 1], t[node << 1 | 1]);
  cnt[node] = cnt[node << 1] + cnt[node << 1 | 1];
}

void update(int node, int l, int r, int x) {
  if (x > r || x < l) {
    return;
  }
  if (l == r) {
    t[node] = INF;
    cnt[node] = 0;
    return;
  }
  int m = (l + r) >> 1;
  update(node << 1, l, m, x);
  update(node << 1 | 1, m + 1, r, x);
  t[node] = min(t[node << 1], t[node << 1 | 1]);
  cnt[node] = cnt[node << 1] + cnt[node << 1 | 1];
}

int get(int node, int l, int r, int x, int y, int val) {
  if (x > r || y < l) {
    return INF;
  }
  if (t[node] != val) {
    return INF;
  }
  if (l == r) {
    return l;
  }
  int m = (l + r) >> 1;
  int p1 = get(node << 1, l, m, x, y, val);
  if (p1 != INF) {
    return p1;
  }
  int p2 = get(node << 1 | 1, m + 1, r, x, y, val);
  if (p2 != INF) {
    return p2;
  }
  return INF;
}

int getCnt(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return cnt[node];
  }
  int m = (l + r) >> 1;
  int p1 = getCnt(node << 1, l, m, x, y);
  int p2 = getCnt(node << 1 | 1, m + 1, r, x, y);
  return p1 + p2;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  init(1, 1, n);
  int pos = 1;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int foo = 0;
    foo = get(1, 1, n, pos, n, b[i]);
    if (foo != INF) {
      res += getCnt(1, 1, n, pos, foo);
      update(1, 1, n, foo);
      pos = foo + 1;
      if (pos > n) {
        pos = 1;
      }
      continue;
    }
    foo = get(1, 1, n, 1, pos - 1, b[i]);
    assert(foo != INF);
    res += getCnt(1, 1, n, pos, n) + getCnt(1, 1, n, 1, foo);
    update(1, 1, n, foo);
    pos = foo + 1;
    if (pos > n) {
      pos = 1;
    }
  }
  cout << res << endl;
  return 0;
}