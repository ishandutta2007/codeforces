#include <stdio.h>

const int N = 210;

int f[N], pass[N], incycle[N];
int n;
long long k = 1ll, mx = 1ll;

long long gcd(long long a, long long b) {
  return (a % b ? gcd(b, a % b) : b);
}
int dfs(int u, int step) {
  if(incycle[u]) {
    return -1;
  }
  if(pass[u]) {
    long long cycle = step - pass[u];
    k = k * cycle / gcd(k, cycle);
    return u;
  }
  pass[u] = step;
  int r = dfs(f[u], step+1);
  if(r != -1) {
    incycle[u] = 1;
  }
  pass[u] = 0;
  return (r == u ? -1 : r);
}
int main() {
  scanf("%d", &n);
  for(int i = 1;i <= n;i++) {
    scanf("%d", &f[i]);
  }
  for(int i = 1;i <= n;i++) {
    if(pass[i] == 0) {
      dfs(i, 1);
    }
  }
  for(int i = 1;i <= n;i++) {
    int cnt = 0;
    for(int u = i;!incycle[u];u = f[u]) {
      cnt++;
    }
    if(cnt > mx) {
      mx = cnt;
    }
  }
  long long ans = ((mx + k - 1) / k) * k;
  printf("%I64d\n", ans);
  return 0;
}