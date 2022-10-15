#include <cstdio>

int const A = 30;
int const N = 555;

int cn[A][3];
int dp[N][A][A], from[N][A][A];
int ans[N][N];
int s[N][N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      s[i][j] = c - 'a';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int e = 0; e < 26; e++) cn[e][0] = cn[e][1] = 0;
    for (int j = 0; j < m; j++) cn[s[i][j]][j % 2]++;
    for (int f1 = 0; f1 < 26; f1++) {
      for (int f2 = 0; f2 < 26; f2++) {
        if (f1 == f2) continue;
        int cur = 1 << 30;
        for (int g1 = 0; g1 < 26; g1++) {
          if (g1 == f1) continue;
          for (int g2 = 0; g2 < 26; g2++) {
            if (g2 == g1 || g2 == f2) continue;
            if (cur > dp[i][g1][g2]) {
              cur = dp[i][g1][g2];
              from[i + 1][f1][f2] = g1 * 26 + g2;
            }
          }
        }
        cur += m - cn[f1][0] - cn[f2][1];
        dp[i + 1][f1][f2] = cur;
      }
    }
  }
  int b1 = -1, b2 = -1;
  for (int f1 = 0; f1 < 26; f1++)
    for (int f2 = 0; f2 < 26; f2++) {
      if (f1 == f2) continue;
      if (b1 < 0 || dp[n][b1][b2] > dp[n][f1][f2]) {
        b1 = f1;
        b2 = f2;
      }
    }
  printf("%d\n", dp[n][b1][b2]);
  for (int i = n; i > 0; i--) {
    for (int q = 0; q < m; q++) if (q % 2 == 0) ans[i - 1][q] = 'a' + b1; else ans[i - 1][q] = 'a' + b2;
    int z = from[i][b1][b2];
    b1 = z / 26;
    b2 = z % 26;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) putchar(ans[i][j]);
    puts("");
  }
}