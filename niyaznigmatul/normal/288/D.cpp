#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int n;
long long ans;
int ss[222222], ff[222222], he[222222], ne[222222], sz[222222];

void dfs(int v, int pr) {
  sz[v] = 1;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    dfs(ff[e], v);
    sz[v] += sz[ff[e]];
  }
}

void dfs2(int v, int pr, int up, long long cn2) {
  long long dn2 = sz[v] - 1;
  long long cur = 0;
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    dn2 += cur * sz[ff[e]];
    cur += sz[ff[e]];
  }
  long long dn1 = (long long) sz[v] * (sz[v] - 1) >> 1;
  long long cn1 = (long long) up * (up - 1) >> 1;
  ans += 2 * dn2 * cn2 + dn2 * (cn1 - cn2) + (dn1 - dn2) * cn2;
//  printf("%d %I64d %I64d %I64d %I64d %I64d\n", v, cn1, cn2, dn1, dn2, 2 * dn2 * cn2 + dn2 * (cn2 - cn1) + (dn2 - dn1) * cn2);
  for (int e = he[v]; e >= 0; e = ne[e]) {
    if (ff[e] == pr) continue;
    dfs2(ff[e], v, up + sz[v] - sz[ff[e]], dn2 - (long long) sz[ff[e]] * (sz[v] - sz[ff[e]]) + (long long) up * (sz[v] - sz[ff[e]]));
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", ss + i, ff + i);
    --ss[i];
    --ff[i];
    ss[i + n - 1] = ff[i];
    ff[i + n - 1] = ss[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n + n - 2; i++) {
    ne[i] = he[ss[i]];
    he[ss[i]] = i;
  }
  dfs(0, -1);
  ans = 0;
  dfs2(0, -1, 0, 0);
  printf("%I64d\n", ans);
}