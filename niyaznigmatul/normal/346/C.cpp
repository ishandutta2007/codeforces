#include <cstdio>
#include <algorithm>

const int INF = 1 << 25;
const int N = 1234567;

int ne[N], he[N], dp[N], x[N];

int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  scanf("%d%d", &a, &b);
  for (int i = 0; i < a - b + 1; i++) he[i] = -1;
  for (int i = 0; i < n; i++) ne[i] = -1;
  int cm = a;
  std::sort(x, x + n);
  int cn = 1;
  for (int i = 1; i < n; i++) {
    if (x[i] != x[cn - 1]) {
      x[cn++] = x[i];
    }
  }
  n = cn;
  for (int i = 0; i < n; i++) {
      int z = a / x[i] * x[i];
      if (z < b) {
          continue;
      }
      if (cm > z) cm = z;
      z -= b;
      ne[i] = he[z];
      he[z] = i;
  }
  for (int i = 0; i < a - b + 1; i++) dp[i] = INF;
  dp[a - b] = 0;
  for (int i = a; i > b; i--) {
      int val = dp[i - b];
      if (val != INF) {
        int go = cm;
        if (go >= i) go = i - 1;
        go -= b;
        if (dp[go] > val + 1) dp[go] = val + 1;
      }
      for (int e = he[i - b]; e >= 0; ) {
          int f = ne[e];
          if (i - x[e] >= b) {
              int z = i - x[e];
              if (cm > z) {
                  cm = z;
              }
              z -= b;
              ne[e] = he[z];
              he[z] = e;
          } else {
              ne[e] = -1;
          }
          e = f;
      }
  }
  printf("%d\n", dp[0]);
}