#include <bits/stdc++.h>

const int M = 111;
double res_r[M][M][M], res_s[M][M][M], res_p[M][M][M];

int main() {
  for (int r = 0; r < M; r++) 
    for (int s = 0; s < M; s++) 
      for (int p = 0; p < M; p++) {
        if (r == 0 && s == 0 && p == 0) continue;
        if (r != 0 && s == 0 && p == 0) {
          res_r[r][s][p] = 1;
          res_s[r][s][p] = 0;
          res_p[r][s][p] = 0;
          continue;
        }
        if (r == 0 && s != 0 && p == 0) {
          res_r[r][s][p] = 0;
          res_s[r][s][p] = 1;
          res_p[r][s][p] = 0;
          continue;
        }
        if (r == 0 && s == 0 && p != 0) {
          res_r[r][s][p] = 0;
          res_s[r][s][p] = 0;
          res_p[r][s][p] = 1;
          continue;
        }
        int cntAll = r * (s + p) + s * p;
        if (r != 0 && s != 0) {
          res_r[r][s][p] += res_r[r][s - 1][p] * r * s / cntAll;
          res_s[r][s][p] += res_s[r][s - 1][p] * r * s / cntAll;
          res_p[r][s][p] += res_p[r][s - 1][p] * r * s / cntAll;
        }
        if (r != 0 && p != 0) {
          res_r[r][s][p] += res_r[r - 1][s][p] * r * p / cntAll;
          res_s[r][s][p] += res_s[r - 1][s][p] * r * p / cntAll;
          res_p[r][s][p] += res_p[r - 1][s][p] * r * p / cntAll;
        }
        if (s != 0 && p != 0) {
          res_r[r][s][p] += res_r[r][s][p - 1] * s * p / cntAll;
          res_s[r][s][p] += res_s[r][s][p - 1] * s * p / cntAll;
          res_p[r][s][p] += res_p[r][s][p - 1] * s * p / cntAll;
        }
        
      }
  int r, s, p;
  scanf("%d %d %d", &r, &s, &p);
  printf("%.17f %.17f %.17f\n", res_r[r][s][p], res_s[r][s][p], res_p[r][s][p]);
}