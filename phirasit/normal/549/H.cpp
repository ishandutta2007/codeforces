#include <stdio.h>

double a, b, c, d;

double max(double x, double y) {
  return x > y ? x : y;
}
double min(double x, double y) {
  return x < y ? x : y;
}
double abs(double k) {
  return k < 0.0 ? -k : k;
}
int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  double x = 0.0, y = max(max(abs(a), abs(b)), max(abs(c), abs(d)));
  int cnt = 0;
  while(cnt < 300 and y-x > 1e-9) {
    double mid = (x + y) / 2.0;
    double mn1 = min(min((a-mid)*(d-mid), (a-mid)*(d+mid)), min((a+mid) * (d-mid), (a+mid) * (d+mid)));
    double mx1 = max(max((a-mid)*(d-mid), (a-mid)*(d+mid)), max((a+mid) * (d-mid), (a+mid) * (d+mid)));
    double mn2 = min(min((c-mid)*(b-mid), (c-mid)*(b+mid)), min((c+mid) * (b-mid), (c+mid) * (b+mid)));
    double mx2 = max(max((c-mid)*(b-mid), (c-mid)*(b+mid)), max((c+mid) * (b-mid), (c+mid) * (b+mid)));
    if(max(mn1, mn2) <= min(mx1, mx2)) {
      y = mid;
    }else {
      x = mid;
    }
    cnt++;
  }
  printf("%.10lf\n", x);
  return 0;
}