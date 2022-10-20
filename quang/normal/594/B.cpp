#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const double PI = acos(-1);

int n;
int s, f;
int v, r;

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d %d", &n, &r, &v);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &s, &f);
    long long len = f - s;
    long double le = 0, ri = 2e9 + 10;
    for (int it = 1; it <= 100; it++) {
      long double m = (le + ri) * 0.5;
      long double x = 1.0 * m * v;
      long double y = 1.0 * m * v / (PI * r * 2);
      long long zz = y;
      y -= zz;
      y *= PI;
      long double delta = (cos(PI / 2 + y) - cos(PI / 2 - y)) * r;
      x += abs(delta);
      if (x >= len) {
        ri = m;
      } else {
        le = m;
      }
    }
    printf("%0.17f\n", (double)(le + ri) / 2);
  }
  return 0;
}