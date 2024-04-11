#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
double mx[N], mn[N];
long double a[N], b[N], u[N], v[N];

bool check(long double u) {
  if (u < -0.000000000000001) {
    return 0;
  }
  if (u > 1.000000000000001) {
    return 0;
  }
  return 1;
}

void solve(long double &x, long double &y, long double b, long double c) {
  long double delta = b * b;
  delta -= (long double)4 * c;
  delta = max(delta, (long double)0.);
  x = (-b - sqrt(delta)) / 2.;
  y = -b - x;
 /* if (check(x) && check(y)) {
    return;
  }
  x = (-b + sqrt(delta)) / 2.;
  y = -b - x;*/
}

int main() {
//  freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", mx + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", mn + i);
  }
  for (int i = 1; i <= n; i++) {
    mn[i] += mn[i - 1];
    mx[i] += mx[i - 1];
    long double sum = mn[i] + mx[i];
    long double pro = mx[i];
    solve(a[i], b[i], -sum, pro);
  }
//  a[n] = b[n] = 1.;
//  mx[n] = mn[n] = 1.;
  for (int i = 1; i <= n; i++) {
    printf("%0.17f ", (double)(a[i] - a[i - 1]));
  }
  printf("\n");
  for (int i = 1; i <= n; i++) {
    printf("%0.17f ", (double)(b[i] - b[i - 1]));
  }
//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      long double pro = (a[i] - a[i - 1]) * (b[j] - b[j - 1]);
//      u[min(i, j)] += pro;
//      v[max(i, j)] += pro;
//    }
//  }
//  puts("\n");
//  for (int i = 1; i <= n; i++) {
//    printf("%0.17f ", (double)(v[i]));
//  }
//  printf("\n");
//  for (int i = 1; i <= n; i++) {
//    printf("%0.17f ", (double)(u[i]));
//  }
  return 0;
}