#include <cstdio>
#include <algorithm>

const int md = 7340033;
const int MK = 1111;
int ans[33][MK], a[MK], b[MK], c[MK];

int main() {
  ans[0][0] = 1;
  for (int i = 1; i <= 30; i++) {
    for (int j = 0; j < MK; j++) a[j] = b[j] = ans[i - 1][j];
    for (int it = 0; it < 3; it++) {
      for (int j = 0; j < MK; j++) {
        for (int k = 0; k + j < MK; k++) {
          c[j + k] = (c[j + k] + (long long) a[j] * b[k]) % md;
        }
      }
      for (int j = 0; j < MK; j++) {
        b[j] = c[j];
        c[j] = 0;
      }
    }
    for (int j = 0; j + 1 < MK; j++) ans[i][j + 1] = b[j];
    ans[i][0] = 1;
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = 0;
    while (n > 1 && (n & 1) == 1) {
      n >>= 1;
      ++m;
    }
    printf("%d\n", ans[m][k]);
  }
}