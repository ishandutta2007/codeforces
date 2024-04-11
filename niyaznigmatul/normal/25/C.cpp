#include <cstdio>

int const N = 333;

int d[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) scanf("%d", d[i] + j);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    --v;
    --u;
    long long ans = 0;
    for (int from = 0; from < n; from++)
      for (int to = 0; to < n; to++) {
        if (d[from][v] + w + d[u][to] < d[from][to]) d[from][to] = d[from][v] + w + d[u][to];
        if (d[from][u] + w + d[v][to] < d[from][to]) d[from][to] = d[from][u] + w + d[v][to];
        ans += d[from][to];
      }      
    if (i > 0) putchar(' ');
    printf("%I64d", ans / 2);
  }
  puts("");
}