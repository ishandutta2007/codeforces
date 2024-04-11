#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N], l[N], r[N], cnt[N], res[N], id[N];
int curRes;
int sz;

bool cmp(int u, int v) {
  int blockU = l[u] / sz, blockV = l[v] / sz;
  if (blockU != blockV) {
    return blockU < blockV;
  }
  return r[u] < r[v];
}

void add(int u, int sign) {
  int then = b[u] == cnt[u];
  cnt[u] += sign;
  int now = b[u] == cnt[u];
  curRes += now - then;
}

int main() {
  scanf("%d %d", &n, &m);
  sz = sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", l + i, r + i);
    id[i] = i;
  }
  sort(id + 1, id + m + 1, cmp);
  int curL = 2, curR = 1;
  for (int i = 1; i <= m; i++) {
    int u = id[i];
    while (curL > l[u]) {
      add(a[--curL], 1);
    }
    while (curL < l[u]) {
      add(a[curL++], -1);
    }
    while (curR > r[u]) {
      add(a[curR--], -1);
    }
    while (curR < r[u]) {
      add(a[++curR], 1);
    }
    res[u] = curRes;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}