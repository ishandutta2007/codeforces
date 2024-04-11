#include <cstdio>

int const N = 1000002;
int const BITS = 31;

int link[N * BITS][2];
int a[N], num[N * BITS];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int c = getchar();
    while (c <= 32) c = getchar();
    a[i] = 0;
    while (c > 32) {
      a[i] = a[i] * 10 + c - '0';
      c = getchar();
    }
  }
  for (int i = 1; i <= n; i++) a[i] ^= a[i - 1];
  int fr = 2;
  int root = 1;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {      
    int v = root;
    for (int b = BITS - 1; b >= 0 && v > 0; b--) {
      int curAi = (a[i] >> b) & 1;
      int curK = (k >> b) & 1;
      if (curK == 1) {
        if (link[v][curAi] > 0) {
          ans += num[link[v][curAi]];
        }
      }
      v = link[v][curAi ^ curK];
    }
    v = root;
    for (int b = BITS - 1; b >= 0; b--) {
      num[v]++;
      int cur = (a[i] >> b) & 1;
      if (link[v][cur] == 0) {
        link[v][cur] = fr++;
      }
      v = link[v][cur];
    }
    num[v]++;
  }
  printf("%lld\n", (long long) n * (n + 1) / 2 - ans);
}