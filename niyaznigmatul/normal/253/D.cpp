#include <cstdio>

int s[444][444];
int a[444][444];
int cn[444][33];

int sum(int i1, int j1, int i2, int j2) {
  int ret = a[i2][j2];
  if (i1 > 0) ret -= a[i1 - 1][j2];
  if (j1 > 0) ret -= a[i2][j1 - 1];
  if (i1 > 0 && j1 > 0) ret += a[i1 - 1][j1 - 1];
  return ret;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, m, kn;
  scanf("%d%d%d", &n, &m, &kn);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c < 'a' || c > 'z') c = getchar();
      s[i][j] = c;
      a[i][j] = c == 'a';
    }
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m; j++) {
      a[i][j] += a[i - 1][j];
    }
  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++)
      a[i][j] += a[i][j - 1];
  long long ans = 0;
  for (int i = 0; i < n; i++) 
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < 26; k++) cn[m][k] = 0;
      for (int k = m - 1; k >= 0; k--) {
        for (int t = 0; t < 26; t++) cn[k][t] = cn[k + 1][t];
        if (s[i][k] == s[j][k]) {
          cn[k][s[i][k] - 'a']++;
        }
      }
      int x = 0;
      for (int k = 0; k < m; k++) {
        if (x < k + 1) x = k + 1;
        while (x < m && sum(i, k, j, x) <= kn) ++x;
        if (s[i][k] == s[j][k]) {
          ans += cn[k + 1][s[i][k] - 'a'] - cn[x][s[i][k] - 'a'];
//          printf("%d %d %d %d %d\n", i, j, k, x, cn[k + 1][s[i][k] - 'a'] - cn[x][s[i][k] - 'a']);
        }
      }
    }
  printf("%I64d\n", ans);
}