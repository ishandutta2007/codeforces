#include<bits/stdc++.h>

using namespace std;

#define double double
#define EPS 1e-9
struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
  Point(const Point& p) : x(p.x), y(p.y) {}
  int operator < (const Point& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
  int operator == (const Point& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
  Point operator + (const Point& p) const {return Point(x + p.x, y + p.y);}
  Point operator - (const Point& p) const {return Point(x - p.x, y - p.y);}
  Point operator * (double c) const {return Point(x * c, y * c);}
  Point operator / (double c) const {return Point(x / c, y / c);}
  double arg() const { return atan2(y, x); }
};
double cross(Point p, Point q) {return p.x * q.y - p.y * q.x;}
double area(Point a, Point b, Point c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
double area2(Point a, Point b, Point c) {return cross(a, b) + cross(b, c) + cross(c, a);}
double dot(Point p, Point q) {return p.x * q.x + p.y * q.y;}
double dist(Point p, Point q) {return sqrt(dot(p - q, p - q));}
double dist2(Point p, Point q) {return dot(p - q, p - q);}
ostream& operator << (ostream& os, const Point& p) {
  os << "(" << p.x << "," << p.y << ")";
  return os;
}

#undef double

Point offset(vector<Point> &v) {
  Point ans = v[0];
  for(auto &p : v) {
    ans.x = min(ans.x, p.x);
    ans.y = min(ans.y, p.y);
  }
  return ans;
}

void diff(vector<Point> &v, vector<pair<double, Point>> &ret) {
  for(int i = 0; i < v.size(); ++i) {
    Point vec = v[(i + 1) % v.size()] - v[i];
    ret.emplace_back(vec.arg(), vec);
  }
}

vector<Point> minkowskisum(vector<Point> &a, vector<Point> &b) {
  Point off = offset(a) + offset(b);

  vector<pair<double, Point>> v; /// angle, vector
  vector<Point> ret;
  diff(a, v);
  diff(b, v);

  sort(v.begin(), v.end(), [&](const pair<double, Point> &x, const pair<double, Point> &y){
    return x.first < y.first;
  });

  vector<bool> mark(v.size(), false);
  for(int i = v.size() - 1; i > 0; --i) {
    if(abs(v[i].first - v[i - 1].first) < EPS) {
      mark[i] = true;
      v[i - 1].second = v[i - 1].second + v[i].second;
      v[i].second = Point(0, 0);
    }
  }
  for(int i = 0; i < v.size(); ++i) if(!mark[i]) ret.emplace_back(v[i].second);
  partial_sum(ret.begin(), ret.end(), ret.begin());
  off = off - offset(ret);
  for(auto &p : ret) p = p + off;
  return ret;
}

double cross(Point a, Point b, Point c){
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool PointInsidePolygon(vector<Point> &poly, Point q) {
  int a = 1, b = poly.size() - 1;
  swap(a, b);
  if(cross(poly[0], poly[a], q) > 0 || cross(poly[0], poly[b], q) < 0) return 0;
  while(abs(a - b) > 1) {
    int c = (a + b) >> 1;
    if(cross(poly[0], poly[c], q) > 0) {
      b = c;
    }
    else a = c;
  }

  return cross(poly[a], poly[b], q) <= 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<Point> a[3];
  for(int i = 0; i < 3; ++i) {
    int m; cin >> m;
    while(m--) {
      int x, y; cin >> x >> y;
      a[i].emplace_back(x, y);
    }
  }

  vector<Point> poly = minkowskisum(a[0], a[1]);
                poly = minkowskisum(poly, a[2]);

  int q; cin >> q;
  while(q--) {
    Point a; cin >> a.x >> a.y;
    a.x *= 3; a.y *= 3;

    if(PointInsidePolygon(poly, a)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}