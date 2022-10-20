#include <bits/stdc++.h>

using namespace std;

const int N = 1010, MOD = 1000000007;

inline int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

inline int mul (int u, int v) {
  return (long long) u * v % MOD;
}

int dp[2][N][55], res[N][55];
int f[N], c[N][N];

int A(int k, int n) {
  return mul(c[n][k], f[k]);
}

void pre() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = mul(f[i - 1], i);
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
      }
    }
  }
  int cur = 0, next;
  dp[0][0][0] = 1;
  for (int it = 1; it < N; it++) {
    next = cur ^ 1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 55; j++) {
        dp[next][i][j] = 0;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 55; j++) {
        dp[next][i][j] = dp[cur][i][j];
        if (i - it >= 0 && j) {
          dp[next][i][j] = add(dp[next][i][j], dp[cur][i - it][j - 1]);
        }
      }
    }
    cur = next;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < 55; j++) {
      for (int sum = 1; sum <= i; sum++) {
        if (!dp[cur][sum][j]) {
          continue;
        }
        int foo = mul(dp[cur][sum][j], A(j, j + i - sum));
        res[i][j] = add(res[i][j], foo);
      }
    }
  }
}

int main() {
  pre();
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, n;
    scanf("%d %d", &n, &k);
    if (k > 50) {
      printf("0\n");
    } else {
      printf("%d\n", res[n][k]);
    }
  }
  return 0;
}