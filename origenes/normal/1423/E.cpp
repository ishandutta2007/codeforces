#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123456;
const long double eps = 1e-12;

int dcmp(long double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

struct Point {
  long double x, y;

  Point operator-(const Point &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }

  bool operator==(const Point &rhs) const {
    return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
  }
};
typedef Point Vector;

long double getDot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

long double getCross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

long double getLength(Vector a) {
  return sqrt(getDot(a, a));
}

long double getDistanceToSegment(Point p, Point a, Point b) {
  Vector A = p - a;
  if (a == b) return getLength(A);
  Vector v1 = b - a, v2 = p - a, v3 = p - b;
  if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
  return dcmp(getDot(v1, v3)) > 0 ? getLength(v3) : abs(getCross(v1, v2) / getLength(v1));
}

long double getArea(const vector<Point> &p) {
  long double ret = 0;
  int n = p.size();
  REP(i, n - 1) {
    Vector a = p[i] - p[0], b = p[i + 1] - p[0];
    ret += getCross(a, b);
  }
  return abs(ret) / 2;
}

bool onSegment(Point o, Point a, Point b) {
  Vector A = a - o, B = b - o;
  return dcmp(getCross(A, B)) == 0 && dcmp(getDot(A, B)) < 0;
}

int isPointInPolygon(Point o, vector<Point> &poly) {
  int wn = 0, n = poly.size();
  REP(i, n) {
    if (onSegment(o, poly[i], poly[(i + 1) % n])) return -1;
    Vector v1 = poly[(i + 1) % n] - poly[i], v2 = o - poly[i];
    int k = dcmp(getCross(v1, v2));
    int d1 = dcmp(poly[i].y - o.y), d2 = dcmp(poly[(i + 1) % n].y - o.y);
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  return wn ? 1 : 0;
}

vector<Point> poly[maxn];
long double area[maxn];

int n, q;
double _w, _h;

int main() {
  scanf("%lf%lf%d", &_w, &_h, &n);
  REP(i, n) {
    int v; scanf("%d", &v);
    poly[i].resize(v);
    for (auto &[x, y] : poly[i]) {
      double _x, _y;
      scanf("%lf%lf", &_x, &_y);
      x = _x, y = _y;
    }
    area[i] = getArea(poly[i]);
  }
  scanf("%d", &q);
  while (q--) {
    Point o; long double r;
    double _x, _y, _r;
    scanf("%lf%lf%lf", &_x, &_y, &_r);
    o.x = _x, o.y = _y, r = _r;
    vector<int> ans;
    long double a = 0;
    REP(i, n) {
      bool sel = false;
      REP(j, int(poly[i].size())) {
        if (dcmp(getDistanceToSegment(o, poly[i][j], poly[i][(j + 1) % poly[i].size()]) - r) <= 0) {
          sel = true;
          break;
        }
      }
      if (!sel && isPointInPolygon(o, poly[i])) sel = true;
      if (sel) {
        ans.eb(i);
        a += area[i];
      }
    }
    printf("%.10lf %d", double(a), int(ans.size()));
    for (auto x : ans) printf(" %d", x);
    putchar('\n');
  }
}