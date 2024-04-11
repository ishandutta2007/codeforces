#include <bits/stdc++.h>
using namespace std;

int c, a, b, p, q;

int main() {
  scanf("%d %d %d %d %d", &c, &p, &q, &a, &b);
  if (a > b) {
    swap(a, b);
    swap(p,q);
  }

  long long res = 0;
  if (b > 1000) {
    for (int y = 0; y*b <= c; y++) {
      int x = ((c - b * y) / a);
      res = max(res, (long long)x * p + (long long) y * q);
    }
  } else {
    for (int x = 0; x <= 10000 && a*x <= c; x++) {
      int y = ((c - a * x) / b);
      res = max(res, (long long)x * p + (long long) y * q);
    }
    for (int y = 0; y <= 10000 && b*y <= c; y++) {
      int x = ((c - b * y) / a);
      res = max(res, (long long)x * p + (long long) y * q);
    }
  }
  printf("%I64d\n", res);
}