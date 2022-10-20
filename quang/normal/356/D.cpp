#include <bits/stdc++.h>

using namespace std;

const int N = 70100;

int n, s;
int a[N], id[N];
int pre[N];
int used[N], nex[N];
unsigned int f[N], f2[N];

bool cmp(int u, int v) {
  return a[u] > a[v];
}

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  if (s < a[id[1]]) {
    printf("-1\n");
    return 0;
  }
  s -= a[id[1]];
  if (s != 0) {
    int len = (s >> 5) + 1;
    f[0] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j <= len; j++) {
        f2[j] = 0;
      }
      int val = a[id[i]];
      int leap = (val >> 5);
      int shift = val & 31;
      for (int j = 0; j <= len; j++) {
        int k = j + leap;
        if (k > len) {
          break;
        }
        f2[k] |= (f[j] << shift);
        if (shift) {
          f2[k + 1] |= (f[j] >> (32 - shift));
        }
      }
      for (int j = 0; j <= len; j++) {
        if ((f[j] | f2[j]) == f[j]) {
          continue;
        }
        unsigned int mask = ((f[j] ^ f2[j]) & f2[j]);
        for (int it = 0; it < 32; it++) {
          if ((mask >> it) & 1) {
            pre[j * 32 + it] = i;
          }
        }
        f[j] |= f2[j];
      }
    }
    if (!pre[s]) {
      cout << -1 << endl;
      return 0;
    }
    int foo = s;
    while (foo) {
      int x = pre[foo];
      x = id[x];
      used[x] = 1;
      foo -= a[x];
    }
  }
  int cur = id[1];
  for (int i = 2; i <= n; i++) {
    if (used[id[i]]) {
      continue;
    }
    nex[cur] = id[i];
    cur = id[i];
  }
  for (int i = 1; i <= n; i++) {
    if (nex[i] == 0) {
      printf("%d 0\n", a[i]);
    } else {
      printf("%d 1 %d\n", a[i] - a[nex[i]], nex[i]);
    }
  }
  return 0;
}