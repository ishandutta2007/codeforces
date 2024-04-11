#include <bits/stdc++.h>
using namespace std;

const int N = 44;

int n, m, q;
char s[N][N];

int pre[N][N][N][N];

int solve() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '1') continue;

      int lst = m;
      for (int ii = i; ii < n; ++ii) {
        for (int jj = j; jj < lst; ++jj) {
          if (s[ii][jj] == '1') {
            lst = jj;
            break;
          }

          ++pre[ii][jj][i][j];
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int ii = i; ii >= 0; --ii) {
        for (int jj = j; jj >= 0; --jj) {
          pre[i][j][ii][jj] += (ii < i ? pre[i][j][ii+1][jj] : 0);
          pre[i][j][ii][jj] += (jj < j ? pre[i][j][ii][jj+1] : 0);
          pre[i][j][ii][jj] -= (ii < i && jj < j ? pre[i][j][ii+1][jj+1] : 0);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int ii = 0; ii <= i; ++ii) {
        for (int jj = 0; jj <= j; ++jj) {
          pre[i][j][ii][jj] += (i > ii ? pre[i-1][j][ii][jj] : 0);
          pre[i][j][ii][jj] += (j > jj ? pre[i][j-1][ii][jj] : 0);
          pre[i][j][ii][jj] -= (i > ii && j > jj ? pre[i-1][j-1][ii][jj] : 0);
        }
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a, --b, --c, --d;

    printf("%d\n", pre[c][d][a][b]);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}