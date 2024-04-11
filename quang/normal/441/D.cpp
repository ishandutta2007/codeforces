#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n, m;
int a[N];
int used[N];

int getf() {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      res++;
      int u = i;
      while (!used[u]) {
        used[u] = 1;
        u = a[u];
      }
    }
  }
  return n - res;
}

void out(int u) {
  for (int i = 1; i <= u; i++) {
    for (int j = 1; j <= n; j++) {
      used[j] = 0;
    }
    int pos = a[1];
    while (pos != 1) {
      used[pos] = 1;
      pos = a[pos];
    }
    for (int j = 2; j <= n; j++) {
      if (!used[j]) {
        pos = j;
        break;
      }
    }
    swap(a[pos], a[1]);
    printf("%d %d ", 1, pos);
  }
}

void in(int u) {
  int cur = 1;
  for (int i = 1; i <= u; i++) {
    while (a[cur] == cur) {
      cur++;
    }
    int minval = n + 1;
    int x = a[cur];
    while (x != cur) {
      minval = min(minval, x);
      x = a[x];
    }
    swap(a[cur], a[minval]);
    printf("%d %d ", cur, minval);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  scanf("%d", &m);
  int p = getf();
  if (m == p) {
    puts("0");
    return 0;
  }
  printf("%d\n", abs(m - p));
  if (m > p) {
    out(abs(m - p));
  } else {
    in(abs(m - p));
  }
  return 0;
}