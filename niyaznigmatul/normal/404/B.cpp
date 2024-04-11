#include <cstdio>
#include <cmath>

int main() {
  int a, d;
  double aa, dd;
  scanf("%lf%lf", &aa, &dd);
  a = (int) (round(aa * 10000));
  d = (int) (round(dd * 10000));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long cc = (long long) i * d / a & 3;
    long long all = (long long) i * d % a;    
    if (cc == 0) {
      printf("%.17lf %.17lf\n", all * .0001, 0.);
    } else if (cc == 1) {
      printf("%.17lf %.17lf\n", a * .0001, all * .0001);
    } else if (cc == 2) {
      printf("%.17lf %.17lf\n", (a - all) * .0001, a * .0001);
    } else {
      printf("%.17lf %.17lf\n", 0., (a - all) * .0001);
    }
  }
}