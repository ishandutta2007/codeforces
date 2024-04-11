#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long double dp[2][N], sumdp[N];
int n, m;
int x[N], a;

long double getval(int l, int r) {
  if (l) {
    return sumdp[r] - sumdp[l - 1];
  }
  return sumdp[r];
}

long double get(int u, int pos) {
  long double res = 0;
  if (pos < m) {
    int r = u - pos - 1;
    int l = u - m;
    l = max(0, l);
    if (r >= 0) {
      res += getval(l, r);
    }
  }
  if (pos > 1) {
    int r = u - 1;
    int l = u - pos + 1;
    l = max(0, l);
    if (r >= 0) {
      res += getval(l, r);
    }
  }
  return res / (1.0 * (m - 1));
}

int main() {
  scanf("%d %d", &n, &m);
  if (m == 1) {
    printf("1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
    a += x[i];
  }
  dp[0][0] = m - 1;
  sumdp[0] = m - 1;
  for (int i = 1; i <= n * m; i++) {
    sumdp[i] = sumdp[i - 1] + dp[0][i];
  }
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int next = cur ^ 1;
    for (int j = 0; j <= m * n; j++) {
      dp[next][j] = get(j, x[i]);
    }
    cur = next;
    sumdp[0] = dp[cur][0];
    for (int i = 1; i <= n * m; i++) {
      sumdp[i] = sumdp[i - 1] + dp[cur][i];
    }
  }
  printf("%0.17f", (double)(sumdp[a - 1] + 1));
  return 0;
}