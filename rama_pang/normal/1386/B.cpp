#include <bits/stdc++.h>
using namespace std;

class Rational { // a / b
 public:
  __int128_t a, b;
  void Normalize() {
    __int128_t g = __gcd(max(a, -a), max(b, -b));
    a /= g, b /= g;
    if (b < 0) a *= -1, b *= -1;
  }

  Rational() : a(0), b(1) {}
  Rational(__int128_t a) : a(a), b(1) {}
  Rational(__int128_t a, __int128_t b) : a(a), b(b) {}
  
  friend Rational operator + (const Rational &a, const Rational &b) {
    return Rational(a.a * b.b + a.b * b.a, a.b * b.b);
  }

  friend Rational operator - (const Rational &a, const Rational &b) {
    return Rational(a.a * b.b - a.b * b.a, a.b * b.b);
  }

  friend Rational operator * (const Rational &a, const Rational &b) {
    return Rational(a.a * b.a, a.b * b.b);
  }

  friend Rational operator / (const Rational &a, const Rational &b) {
    return Rational(a.a * b.b, a.b * b.a);
  }

  friend bool operator == (const Rational &a, const Rational &b) {
    return a.a == b.a && a.b == b.b;
  }

  friend bool operator != (const Rational &a, const Rational &b) {
    return a.a != b.a || a.b != b.b;
  }

  friend bool operator < (const Rational &a, const Rational &b) {
    return a.a * b.b < a.b * b.a;
  }

  friend bool operator > (const Rational &a, const Rational &b) {
    return a.a * b.b > a.b * b.a;
  }
};

using Point = pair<Rational, Rational>;

Point operator - (const Point &a, const Point &b) {
  return Point(a.first - b.first, a.second - b.second);
}

Point operator * (const Point &a, const int &b) {
  return Point(a.first * b, a.second * b);
}

int Half(Point p) { // upper half or lower half in xy coordinate
  if (p.second != 0) {
    return p.second > 0 ? 1 : -1;
  } else if (p.first != 0) {
    return p.first > 0 ? 1 : -1;
  } else {
    return 0;
  }
}

Rational Cross(Point a, Point b) {
  return (a.first * b.second) - (a.second * b.first);
}

bool AngleCmp(Point a, Point b) {
  int A = Half(a), B = Half(b);
  return A == B ? (Cross(a, b) > 0) : (A > B);
}

struct points_cmp {
  const bool operator() (Point a, Point b) const {
    return AngleCmp(a, b);
  }
};

vector<Point> A;
map<Point, int, points_cmp> points;

int origin = 0;
int inverse = 0;
int gap = 1;

int Query() {
  if (origin) {
    return 1;
  } else if (inverse) {
    return 2;
  } else if (points.size() >= 3 && gap == 0) {
    return 3;
  } else {
    return 0;
  }
}

bool HasGap(Point a, Point b) { // angle between a and b > pi radians
  return a == b || Cross(a, b) < 0;
}

void Insert(Point p) {
  if (p == Point(0, 0)) {
    origin++;
    return;
  }
  if (points.count(p)) {
    points[p]++;
    return;
  }
  points[p] = 1;
  auto it = points.find(p);
  if (points.count(p * -1)) {
    inverse++;
  }
  auto nxt = next(it); if (nxt == end(points)) nxt = begin(points);
  auto prv = it; if (prv == begin(points)) prv = end(points); prv--;
  if (HasGap(prv->first, nxt->first) && !HasGap(prv->first, it->first) && !HasGap(it->first, nxt->first)) {
    gap = 0;
  }
}

void Erase(Point p) {
  if (p == Point(0, 0)) {
    origin--;
    return;
  }
  if (points[p] > 1) {
    points[p]--;
    return;
  }
  auto it = points.find(p);
  if (points.count(p * -1)) {
    inverse--;
  }
  auto nxt = next(it); if (nxt == end(points)) nxt = begin(points);
  auto prv = it; if (prv == begin(points)) prv = end(points); prv--;
  if (HasGap(prv->first, nxt->first)) {
    gap = 1;
  }
  points.erase(p);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  array<long long, 3> S;
  cin >> S[0] >> S[1] >> S[2];

  int Q;
  cin >> Q;
  while (Q--) {
    string t;
    cin >> t;
    if (t == "A") {
      auto Sum = [&](const array<long long, 3> &x) {
        return x[0] + x[1] + x[2];
      };
      array<long long, 3> T;
      cin >> T[0] >> T[1] >> T[2];
      long long sumT = Sum(T);
      for (int i = 0; i < 3; i++) {
        T[i] = 1ll * T[i] * Sum(S) - S[i] * sumT;
      }
      A.emplace_back(Point(Rational(T[0], sumT), Rational(T[1], sumT)));
      A.back().first.Normalize(), A.back().second.Normalize();
      Insert(A.back());
    } else if (t == "R") {
      int r;
      cin >> r;
      Erase(A[--r]);
    }
    cout << Query() << "\n";
  }
  return 0;
}