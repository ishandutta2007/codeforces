#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class Line {
 public: 
  long double a, b;
  long double get(long double x) { return a * x + b; }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  lint n;
  long double p;
  cin >> n >> p;
  vector<Line> a(n);
  long double sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].a >> a[i].b;
    sum += a[i].a;
  }

  if (p >= sum) {
    cout << -1 << "\n";
    return 0;
  }

  auto Can = [&](long double x) {
    long double cost = 0;
    for (int i = 0; i < n; i++) {
      long double et = a[i].a * x - a[i].b;
      if (et >= 0) {
        cost += et;
      }
    }
    return cost / x <= p;
  };

  long double lo = 0, hi = 1e14;
  for (int rep = 0; rep < 100; rep++) {
    long double md = (lo + hi) / 2;
    if (Can(md)) {
      lo = md;
    } else {
      hi = md;
    }
  }
  cout << fixed << setprecision(20);
  cout << lo << "\n";
  return 0;
}