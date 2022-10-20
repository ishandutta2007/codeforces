#include <bits/stdc++.h>

using namespace std;

const int N = 100200, MOD = 1000000007;

int n, m;
int a[N];
int dp[110][N];
int c[110][N];

int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

int sub(int u, int v) {
  u -= v;
  if (u < 0) {
    u += MOD;
  }
  return u;
}

void bf(int l, int r, int k) {
  for (int i = l; i <= r; i++) {
    a[i] = add(a[i], c[k][i - l + k]);
  }
}

void update(int l, int r, int k) {
  for (int i = 0; i <= k; i++) {
    dp[i][l] = add(dp[i][l], c[i][k]);
    dp[i][r + 1 - i] = add(dp[i][r + 1 - i], sub(0, c[k - i][r - l + k - i]));
  }
}

int main() {
  //freopen("input.txt", "r" ,stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < 110; i++) {
    for (int j = i; j < N; j++) {
      if (i == 0 || j == i) {
        c[i][j] = 1;
      } else {
        c[i][j] = add(c[i][j - 1], c[i - 1][j - 1]);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    if (r - l > 110) {
      update(l, r, k);
    } else {
      bf(l, r, k);
    }
  }
  for (int i = 100; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = add(dp[i][j], add(dp[i][j - 1], dp[i + 1][j - 1])) % MOD;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", add(a[i], dp[0][i]));
  }
  return 0;
}