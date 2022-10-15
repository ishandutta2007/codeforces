#include <cstdio>

const int mod = 1000000007;
void add(int & a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

const int N = 2222;
int dp[4][N][N];
int a[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int c = getchar();
    while (c <= 32) c = getchar();
    a[i] = c - 'a';
    a[i] = 25 - a[i];
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int t = 0; t < 2; t++) {
        int val = dp[t][i][j];
        if (val == 0) continue;
//        printf("%d %d %d %d\n", t, i, j, val);
        add(dp[1][i + 1][j], val);
        add(dp[0][i + 1][j], (long long) (25 - a[i]) * val % mod);
        if (t == 0) {
          int w = i;
          for (; w < n; w++) {
            int cn = (n - w) * (w - i + 1);
            if (cn + j > k) break;
            add(dp[0][w + 1][j + cn], (long long) a[w] * val % mod);
          }
          int wleft = w;
          w = n - 1;
          for (; w > wleft; w--) {
            int cn = (n - w) * (w - i + 1);
            if (cn + j > k) break;
            add(dp[0][w + 1][j + cn], (long long) a[w] * val % mod);
          }
        }
      }
    }
  }
  int ans = dp[0][n][k];
  add(ans, dp[1][n][k]);
  printf("%d\n", ans);
}