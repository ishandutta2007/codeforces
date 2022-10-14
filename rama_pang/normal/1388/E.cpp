#include <bits/stdc++.h>
using namespace std;

using ld = long double;
#define double ld

struct Line {
  int m, c;
  Line() {}
  Line(int m, int c) : m(m), c(c) {}
  double get(double x) { return m * x + c; }
};

class ConvexHull {
 public:
  vector<Line> H;
  vector<double> coord;
  ConvexHull() {}

  bool Majorize(Line a, Line b, Line c, const function<bool(double, double)> &cmp) {
    if (b.m == c.m) return true;
    return double(b.c - a.c) / double(a.m - b.m) >= double(c.c - a.c) / double(a.m - c.m);
  }

  void Build(vector<Line> lines, const function<bool(double, double)> &cmp) {
    for (auto x : lines) {
      int sz = H.size();
      while (sz > 1 && Majorize(H[sz - 2], H[sz - 1], x, cmp)) {
        H.pop_back();
        sz--;
      }
      H.emplace_back(x);
    }
    coord.emplace_back(-1e18);
    for (int i = 1; i < (int) H.size(); i++) {
      coord.emplace_back(double(H[i].c - H[i - 1].c) / double(H[i - 1].m - H[i].m));
    }
  }

  double Query(double x, const function<bool(double, double)> &cmp) {
    int lo = 0, hi = int(H.size()) - 1;
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (coord[md] < x) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    return H[lo].get(x);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> xl(n), xr(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> xl[i] >> xr[i] >> y[i];
  }

  vector<Line> left, right;
  for (int i = 0; i < n; i++) {
    left.emplace_back(Line(y[i], xl[i]));
    right.emplace_back(Line(y[i], xr[i]));
  }

  sort(begin(left), end(left), [&](Line &a, Line &b) {
    return make_pair(a.m, -a.c) > make_pair(b.m, -b.c);
  });
  sort(begin(right), end(right), [&](Line &a, Line &b) {
    return make_pair(a.m, -a.c) < make_pair(b.m, -b.c);
  });
  left.resize(unique(begin(left), end(left), [&](Line &a, Line &b) {
    return a.m == b.m;
  }) - begin(left));
  right.resize(unique(begin(right), end(right), [&](Line &a, Line &b) {
    return a.m == b.m;
  }) - begin(right));

  ConvexHull L; L.Build(left, [&](double a, double b) { return a >= b; });
  ConvexHull R; R.Build(right, [&](double a, double b) { return a <= b; });
  auto Calc = [&](double x) {
    double LL = L.Query(x, [&](double a, double b) { return a < b; });
    double RR = R.Query(x, [&](double a, double b) { return a > b; });
    return RR - LL;
  };
  
  vector<pair<double, double>> segs; // invalid
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (y[i] == y[j]) {
        continue;
      }
      double a = xr[j] - xl[i];
      double b = xl[j] - xr[i];
      a /= double(y[i] - y[j]);
      b /= double(y[i] - y[j]);
      segs.emplace_back(min(a, b), max(a, b));
    }
  }
  sort(begin(segs), end(segs));
  vector<pair<double, double>> mrg;
  for (auto i : segs) {
    if (mrg.empty() || mrg.back().second <= i.first) {
      mrg.emplace_back(i);
    } else {
      mrg.back().second = max(mrg.back().second, i.second);
    }
  }
  vector<double> qs;
  for (auto i : mrg) {
    qs.emplace_back(i.first);
    qs.emplace_back(i.second);
  }
  if (qs.empty()) qs.emplace_back(0);
  double ans = 1e18;
  for (auto x : qs) {
    ans = min(ans, Calc(x));
  }

  cout << fixed << setprecision(20) << ans << "\n";
  return 0;
}