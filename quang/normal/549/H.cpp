#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d;

pair <double, double> get(double a, double b, double c, double d) {
  vector <double> x;
  x.push_back(a * c);
  x.push_back(a * d);
  x.push_back(b * c);
  x.push_back(b * d);
  sort(x.begin(), x.end());
  return make_pair(x[0], x[3]);
}
bool check(double x) {
  pair <double, double> x1, x2;
  x1 = get(a - x, a + x, d - x, d + x);
  x2 = get(b - x, b + x, c - x, c + x);
  return (x1.first <= x2.second && x2.first <= x1.second);
}

int main() {
  cin >> a >> b >> c >> d;
  double l = 0;
  double r = 1e15;
  for (int i = 1; i <= 1000; i++) {
    double m = (l + r) * 0.5;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%0.9f", r);
  return 0;
}