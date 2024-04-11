#include <cstdio>
#include <cstdlib>
#include <ctime>

const int co = 48;
const int md = 95542721;
const int N = 1 << 18;

int sum[co][N];
int here[N];
int ad[N];
int msum[N];
int a[N];

int randint(int v) {
  return ((rand() << 15) | rand()) % v;
}

void add(int & a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void build(int q, int v, int l, int r) {
  if (l >= r) {
    return;
  }
  if (l == r - 1) {
    sum[q][v] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(q, v * 2, l, m);
  build(q, v * 2 + 1, m, r);
  add(sum[q][v], sum[q][v * 2]);
  add(sum[q][v], sum[q][v * 2 + 1]);
}

void relax(int v) {
  if (ad[v] == 0) return;
  ad[2 * v] += ad[v];
  ad[2 * v + 1] += ad[v];
  here[v] = (ad[v] + here[v]) % 48;
  ad[v] = 0;
}

int gSum(int v, int d) {
  return sum[(d + here[v] + ad[v]) % 48][v];
}

int getSum(int v, int l, int r, int ll, int rr) {
  if (r <= ll || rr <= l) {
    return 0;
  }
  if (ll <= l && r <= rr) {
    return gSum(v, 0);
  }
  relax(v);
  int ret = 0;
  int m = (l + r) >> 1;
  add(ret, getSum(v * 2, l, m, ll, rr));
  add(ret, getSum(v * 2 + 1, m, r, ll, rr));
  return ret;
}

void collect(int v) {
  for (int i = 0; i < co; i++) {
    sum[i][v] = 0;
    add(sum[i][v], gSum(v * 2, i));
    add(sum[i][v], gSum(v * 2 + 1, i));
  }
  here[v] = 0;
}

void add(int v, int l, int r, int ll, int rr) {
  if (r <= ll || rr <= l) {
    return;
  }
  if (ll <= l && r <= rr) {
    ad[v]++;
    return;
  }
  relax(v);  
  int m = (l + r) >> 1;
  add(v * 2, l, m, ll, rr);
  add(v * 2 + 1, m, r, ll, rr);
  collect(v);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] %= md;
  }
  for (int d = 0; d < co; d++) {
    build(d, 1, 0, n);
    for (int i = 0; i < n; i++) {
      a[i] = (long long) a[i] * a[i] % md * a[i] % md;
    }
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1) {
      printf("%d\n", getSum(1, 0, n, l - 1, r));
    } else {
      add(1, 0, n, l - 1, r);
    }
  }
}