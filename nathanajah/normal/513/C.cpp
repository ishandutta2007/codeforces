#include <bits/stdc++.h>
using namespace std;

int n;
double l[6],r[6];


int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &l[i], &r[i]);
  }
  double res = 0;
  for (int i = 1; i <= 10000; i++) {
    //win alone
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < (1 << n); k++) {
        if (k & (1<<j)) {
          continue;
        }
        if (__builtin_popcount(k) < 1) {
          continue;
        }
        double probnow = max(0.0, r[j] - i)/(r[j] + 1 - l[j]);
        probnow = min(probnow, 1.0);
        for (int ll = 0; ll < n; ll++) {
          if (ll != j) {
            double probtmp = 0;
            if (k & (1<<ll)) {
              if (l[ll] <= i  && i <= r[ll]) {
                probtmp = 1/(r[ll] + 1 - l[ll]);
              } else {
                probtmp = 0;
              }
            } else {
              probtmp = max(0.0, i - l[ll])/(r[ll] + 1 - l[ll]);
              probtmp = min(probtmp, 1.0);
            }
            probnow *= probtmp;
          }
        }
        res += i * probnow;
      }
    }
    //tie
    for (int j = 0; j < (1 << n); j++) {
      if (__builtin_popcount(j) > 1) {
        double probnow = 1;
        for (int k = 0; k < n; k++) {
          double probtmp;
          if (j & (1<<k)) {
            probtmp = 0;
            if (l[k] <= i && i <= r[k]) {
              probtmp = 1.0/(r[k] + 1 - l[k]);
            }
          } else {
            probtmp = max(0.0, i - l[k])/(r[k] + 1 - l[k]);
            probtmp = min(probtmp, 1.0);
          }
          probnow *= probtmp;
        }
        res += probnow * i;
      }  
    }
  }
  printf("%.10lf\n", res);
}