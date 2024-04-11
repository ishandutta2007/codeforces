#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int x[N], y[N];
long double p[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  p[0] = 1.;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] / 2.;
  }
  long double allProb = 1. - p[n] - p[n] * n - p[n] * n * (n - 1) / 2.;
  long double area = 0, point = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= min(100, n - 1); j++) {
      long double prob = p[j + 1] - p[n];
      prob /= allProb;
      int u = (i + j) % n;
      area += prob * (1. * x[i] * y[u] - 1. * x[u] * y[i]);
      point += prob * __gcd(abs(x[i] - x[u]), abs(y[i] - y[u]));
    }
  }
  area /= 2.;
  point /= 2.;
  long double res = fabs(area) - point + 1;
  printf("%.17f\n", (double)res);
  return 0;
}