#include <bits/stdc++.h>
using namespace std;

#define DEBUG 1

#define INF (1.0/0.0)
#define EPS 1e-8
#define PI 3.1415926535
#define EQ(x, y) (abs((x)-(y))<EPS)
#define GE(x, y) ((x)>(y)||EQ(x, y))
#define LE(x, y) ((x)<(y)||EQ(x, y))
#define X real()
#define Y imag()

typedef complex<double> Point;
typedef Point Vec;
typedef array<Point, 2> Line;
typedef vector<Point> Poly;

struct Circle {
  Point c;
  double r;
};

enum Geometry {ABC=-2, CW, ACB, CCW, CAB, ON_LINE, OUTSIDE, INSIDE, ERROR}; 

namespace std {
  bool operator<(Point a, Point b) {
    if (!EQ(a.X, b.X)) return a.X < b.X;
    if (!EQ(a.Y, b.Y)) return a.Y < b.Y;
    return false;
  }

  bool operator>(Point a, Point b) {
    return b<a;
  }

  bool operator<=(Point a, Point b) {
    return !(a>b);
  }
}

double dot(Point a, Point b) {
  return (conj(a)*b).X;
}

double cross(Point a, Point b) {
  return (conj(a)*b).Y;
}

Geometry ccw(Point a, Point b, Point c) {
  a -= b;
  c -= b;
  if (cross(a, c) > EPS) return CCW; // ccw
  if (cross(a, c) < -EPS) return CW; // cw
  if (dot(a, c) < -EPS) return ABC; // a - b - c

  double al = abs(a);
  double cl = abs(c);
  if (EQ(al, cl)) return ERROR; // a and c are duplicate
  if (EQ(min(al, cl), 0)) return ERROR;
  if (al < cl) return CAB; // c - a - b
  else return ACB; // a - c - b
}

Point proj(Line l, Point p) {
  Point v = l[1]-l[0];
  double ratio = dot(v, p-l[0]) / norm(v);
  return l[0] + ratio*v;
}

Point refl(Line l, Point p) {
  return p + (proj(l, p) - p) * 2.0;
}

Vec rotate(Vec v, double r) {
  return v*Vec(cos(r), sin(r));
}

bool IsOrthogonal(Line l, Line m) {
  Vec v1 = l[1]-l[0];
  Vec v2 = m[1]-m[0];
  return EQ(dot(v1, v2), 0.0);
}

bool IsParallel(Line l, Line m) {
  Vec v1 = l[1]-l[0];
  Vec v2 = m[1]-m[0];
  return EQ(cross(v1, v2), 0.0);
}

bool IntersectLL(Line l, Line m) {
  if (!EQ(cross(l[1]-l[0], m[1]-m[0]), 0.0)) return true;
  if (EQ(cross(l[1]-l[0], m[0]-l[0]), 0.0)) return true;
  return false;
}

bool IntersectLS(Line l, Line s) {
  Point b = l[0];
  Vec v = l[1]-l[0];
  return cross(v, s[0]-b)*cross(v, s[1]-b) < EPS;
}

bool IntersectSS(Line s, Line t) {
  // hard coding: CW := -1, CCW := 1 -> only CW*CW and CCW*CCW are equal to 1
  if (ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) == 1) return false;
  swap(s, t);
  if (ccw(s[0], s[1], t[0])*ccw(s[0], s[1], t[1]) == 1) return false;
  if (!IsParallel(s, t)) return true;
  if (max(s[0], s[1]) < min(t[0], t[1])) return false;
  swap(s, t);
  if (max(s[0], s[1]) < min(t[0], t[1])) return false;
  return true;
}

bool IntersectLP(Line l, Point p) {
  return EQ(cross(l[1]-p, l[0]-p), 0.0);
}

bool IntersectSP(Line s, Point p) {
  Point a = s[0];
  Point b = s[1];
  return abs(a-p)+abs(b-p)-abs(a-b) < EPS;
}

double DistL(Line l) {
  return abs(l[0]-l[1]);
}

double DistLP(Line l, Point p) {
  return abs(p - proj(l, p));
}

double DistLL(Line l, Line m) {
  if (!IntersectLL(l, m)) return 0;
  return DistLP(l, m[0]);
}

double DistLS(Line l, Line s) {
  if (IntersectLS(l, s)) return 0;
  return min(DistLP(l, s[0]), DistLP(l, s[1]));
}

double DistSP(Line s, Point p) {
  Point r = proj(s, p);
  if (IntersectSP(s, r)) return abs(r - p);
  return min(abs(s[0]-p), abs(s[1]-p));
}

double DistSS(Line s, Line t) {
  if (IntersectSS(s, t)) return 0;

  double a = min(DistSP(s, t[0]), DistSP(s, t[1]));
  swap(s, t);
  double b = min(DistSP(s, t[0]), DistSP(s, t[1]));
  return min(a, b);
}

Line PerpendBisect(Line seg) {
  Point mid = (seg[0]+seg[1])/2.0;
  return Line{mid, mid+(seg[1]-seg[0])*Vec(0, 1)};
}

Point CrossPointLL(Line l, Line m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];
  if (abs(A) < EPS) assert(0);
  return m[0] + B / A * (m[1]-m[0]);
}

vector<Point> CrossPointCL(Circle c, Line l) {
  vector<Point> ret;
  double d = DistLP(l, c.c);
  if (EQ(d, c.r)) {
    ret.emplace_back(proj(l, c.c));
  } else if (d < c.r) {
    double ratio = sqrt(c.r*c.r - d*d);
    Vec sgn = (l[0]-l[1]) / abs(l[0]-l[1]);
    ret.emplace_back(proj(l, c.c) + ratio*sgn);
    ret.emplace_back(proj(l, c.c) - ratio*sgn);
  }

  return ret;
}

vector<Point> CrossPointCS(Circle c, Line s) {
  vector<Point> ret;
  vector<Point> res = CrossPointCL(c, s);
  Point a = s[0];
  Point b = s[1];
  if (a > b) swap(a, b);
  for (Point p : res) {
    if (
      LE(a, p) 
      && 
      LE(p, b)) ret.emplace_back(p);
  }
  return ret;
}

vector<Point> CrossPointCC(Circle c1, Circle c2) {
  vector<Point> ret;
  double d = abs(c1.c - c2.c);
  double rc = (d*d + c1.r*c1.r - c2.r*c2.r) / (2*d);
  double dfr = c1.r*c1.r - rc*rc;

  if (EQ(dfr, 0.0)) dfr = 0.0;
  else if(dfr < 0.0) return ret;

  double rs = sqrt(dfr);
  Vec sgn = (c2.c - c1.c) / d;
  ret.emplace_back(c1.c + sgn*Point(rc, rs));
  if (dfr > 0.0) ret.emplace_back(c1.c + sgn*Point(rc, -rs));
  return ret;
}

// Get the intersection of a circle and a segment, which is obviously a segment
Line CapCS(Circle c, Line s) {
  Point inf(INF, INF);
  vector<Point> cros = CrossPointCS(c, s);
  if (cros.empty()) return Line{inf, inf};

  if (cros.size() == 1) {
    double ad = abs(s[0]-c.c);
    double bd = abs(s[1]-c.c);
    if (!GE(ad, min(bd, c.r))) cros.emplace_back(s[0]);
    else if (!GE(bd, min(ad, c.r))) cros.emplace_back(s[1]);
    else {
      Point p = cros[0];
      cros.emplace_back(p); // avoid an undefined behavior
    }
  }

  if (cros[1] < cros[0]) {
    swap(cros[0], cros[1]);
  }

  return Line{cros[0], cros[1]};
}

Geometry PositioningPoint(Poly poly, Point p) {
  bool in = false;
  int n = poly.size();
  for (int i=0; i<n; i++) {
    Point a = poly[i];
    Point b = poly[(i+1)%n];
    Vec u = a - p;
    Vec v = b - p;

    if (u.Y > v.Y) swap(u, v);

    double cr = cross(u, v);
    if (LE(u.Y, 0) && !GE(0, v.Y) && cr >= EPS) in ^= 1;
    if (IntersectSP({a, b}, p)) return ON_LINE;
  }

  if (in) return INSIDE;
  return OUTSIDE;
}

// Note that ccw(a, b, c) != CCW when a, b, c are colinear
Poly GrahamScan(vector<Point> ps) {
  if (ps.size() <= 2) return ps;

  int k = 0;
  int n = ps.size();
  Poly ret(n*2);

  sort(ps.begin(), ps.end());
  for (int i=0; i<n; i++) {
    while (k > 1 && ccw(ret[k-2], ret[k-1], ps[i]) != CCW) k--;
    ret[k++] = ps[i];
  }

  int k_ = k;
  for (int i=n-1; i>=0; i--) {
    while (k > k_ && ccw(ret[k-2], ret[k-1], ps[i]) != CCW) k--;
    ret[k++] = ps[i];
  }

  ret.resize(k-1);
  return ret;
}

bool IsConvex(Poly ps) {
  //return GrahamScan(ps).size() == ps.size();
  return GrahamScan(ps) == ps;
}

Poly CapConvexes(Poly pp, Poly qq) {
#if DEBUG
  assert (IsConvex(pp));
  assert (IsConvex(qq));
#endif

  Poly ret;
  int a = 0;
  int b = 0;
  int aa = 0;
  int bb = 0;
  int n = pp.size();
  int m = qq.size();
  enum {PIN, QIN, UNKNOWN} in = UNKNOWN;

  auto forward_a = [&](bool put) {
    if (put && in == PIN) ret.emplace_back(pp[a]);
    a = (a+1)%n;
    aa++;
  };

  auto forward_b = [&](bool put) {
    if (put && in == QIN) ret.emplace_back(qq[b]);
    b = (b+1)%m;
    bb++;
  };

  auto intersect_1pt = [](Point &a, Point &b, Point &c, Point &d, Point &r) {
    double D =  cross(b - a, d - c);
    if (EQ(D, 0)) return false;
    double t =  cross(c - a, d - c) / D;
    double s = -cross(a - c, b - a) / D;
    r = a + t * (b - a);
    return GE(t, 0) && LE(t, 1) && GE(s, 0) && LE(s, 1);
  };

  do {
    int apre = (a+n-1)%n;
    int bpre = (b+m-1)%m;
    double C = cross(pp[a]-pp[apre], qq[b]-qq[bpre]);
    double A = cross(pp[apre]-qq[b], pp[a]-qq[b]);
    double B = cross(qq[bpre]-pp[a], qq[b]-pp[a]);
    Point r;
    if (intersect_1pt(pp[apre], pp[a], qq[bpre], qq[b], r)) {
      if (in == UNKNOWN) aa = bb = 0;
      ret.emplace_back(r);
      if (B > 0) in = PIN;
      else if (A > 0) in = QIN;
    }

    if (EQ(A, 0) && EQ(B, 0) && EQ(C, 0)) {
      if (in == PIN) forward_b(false);
      else forward_a(false);
    } else if (C >= 0) {
      if (A > 0) forward_a(true);
      else forward_b(true);
    } else {
      if (B > 0) forward_b(true);
      else forward_a(true);
    }
  } while ((aa < n || bb < m) && aa < 2*n && bb < 2*m);

  if (in == UNKNOWN) {
    if (PositioningPoint(qq, pp[0]) != OUTSIDE) return pp;
    if (PositioningPoint(pp, qq[0]) != OUTSIDE) return qq;
  }
  return ret;
}

double CalcArea(Poly ps) {
  double ret = 0.0;
  for (int i=0; i<ps.size(); i++) {
    ret += cross(ps[i], ps[(i+1)%ps.size()]);
  }
  return ret/2.0;
}

// Convex* requires the elements of ps to be arranged counter clockwise.
pair<int, int> ConvexDiameterApexes(Poly ps) {
#if DEBUG
  assert (IsConvex(ps));
#endif

  int n = ps.size();
  int is = 0;
  int js = 0;
  for (int i=1; i<n; i++) {
    if (ps[i].Y > ps[is].Y) is = i;
    if (ps[i].Y < ps[js].Y) js = i;
  }

  int maxi, maxj;
  double maxd = norm(ps[is]-ps[js]);
  int i = is;
  int j = js;
  do {
    Vec a = ps[i+1] - ps[i];
    Vec b = ps[j+1] - ps[j];
    if (cross(a, b) > -EPS) j = (j+1)%n;
    else i = (i+1)%n;

    double d = norm(ps[i]-ps[j]);
    if (d > maxd) {
      maxd = d;
      maxi = i;
      maxj = j;
    }
  } while (i != is || j != js);

  return make_pair(maxi, maxj);
}

Line ClosestPair(vector<Point> ps) {
  auto CompareY = [](const Point &a, const Point &b) {
    if (a.Y != b.Y) return a.Y < b.Y;
    return a.X < b.X;
  };

  function<Line(Point*,int)> Rec = [&Rec, &CompareY](Point *ps, int n) {
    if (n <= 1) return Line{Point(0, 0), Point(INF, INF)};
    
    int m = n/2;
    double x = ps[m].X;
    Line a = Rec(ps, m);
    Line b = Rec(ps+m, n-m);
    double mind = DistL(a);
    Line ret = a;
    if (DistL(b) < mind) {
      mind = DistL(b);
      ret = b;
    }

    sort(ps, ps+n, CompareY);
    vector<Point> qs;
    qs.reserve(n);
    for (int i=0; i<n; i++) {
      if (abs(ps[i].X - x) >= mind) continue;

      for (int j=0; j<qs.size(); j++) {
        Point p1 = ps[i];
        Point p2 = qs[qs.size()-1-j];
        if (p1.Y - p2.Y >= mind) break;

        double d = abs(p1-p2);
        if (mind > d) {
          mind = d;
          ret = Line{p1, p2};
        }
      }

      qs.emplace_back(ps[i]);
    }

    return ret;
  };

  int n = ps.size();
  assert (n >= 2);
  sort(ps.begin(), ps.end());
  return Rec(&ps[0], n);
}

// Convex* requires the elements of ps to be arranged counter clockwise.
// <left, right> or <upper, lower>
pair<Poly, Poly> CutConvex(Poly ps, Line l) {
#if DEBUG
  assert (IsConvex(ps));
#endif

  //if (l[0].Y > l[1].Y) swap(l[0], l[1]);
  //else if (EQ(l[0].Y, l[1].Y) && l[0].X > l[1].X) swap(l[0], l[1]);

  Poly left;
  Poly right;
  for (int i=0; i<ps.size(); i++) {
    Point a = ps[i];
    Point b = ps[(i+1)%ps.size()];

    if (ccw(l[0], l[1], a) != CW) left.emplace_back(a);
    else right.emplace_back(a);

    Line m{a, b};
    if (IntersectLS(l, m)) {
      Point p = CrossPointLL(l, m);
      left.emplace_back(p);
      right.emplace_back(p);
    }
  }

  return make_pair(left, right);
}

Circle Circum(Point a, Point b, Point c) {
  Circle ret{{INF, INF}, 0.0};
  Line l{a, b};
  Line m{b, c};
  Line lp = PerpendBisect(l);
  Line mp = PerpendBisect(m);
  if (IsParallel(lp, mp)) return ret;

  ret.c = CrossPointLL(lp, mp);
  ret.r = abs(a-ret.c);
  return ret;
}

vector<Point> TangentPoints(Circle c, Point p) {
  vector<Point> ret;
  double d = abs(c.c-p);
  if (EQ(d, c.r)) {
    ret.emplace_back(p);
    return ret;
  }

  if (d < c.r) return ret;

  Vec v = (p-c.c)/d*c.r;
  double t = acos(c.r/d);
  ret.emplace_back(c.c + rotate(v, t));
  ret.emplace_back(c.c + rotate(v, -t));
  return ret;
}

vector<Line> CommonTangents(Circle p, Circle q) {
#if DEBUG
  assert(!EQ(p.c, q.c) || !EQ(p.r, q.r));
#endif

  double pr = p.r;
  double qr = q.r;
  Point pc = p.c;
  Point qc = q.c;
  double d = abs(pc - qc);
  double dr = abs(pr - qr);
  double sr = abs(pr + qr);

  vector<Line> ret;
  if (EQ(d, sr)) {
    Point cp = (pc * qr + qc * pr) / sr;
    Vec v = cp - pc;
    ret.emplace_back(Line{cp, cp + v*Vec(0, 1)});
  } else if (d > sr) {
    Point cp = (pc * qr + qc * pr) / sr;
    vector<Point> pts = TangentPoints(p, cp);
    vector<Point> qts = TangentPoints(q, cp);
    for (int i=0; i<2; i++) {
      Line l{pts[0], qts[i]};
      if (IntersectLP(l, cp)) {
        ret.emplace_back(l);
        ret.emplace_back(Line{pts[1], qts[i^1]});
      }
    }
  } 

  if (EQ(d, dr)) {
    Point cp = pc + (pc-qc) / (qr-pr) * pr;
    Vec v = cp - pc;
    ret.emplace_back(Line{cp, cp + v*Vec(0, 1)});
  } else if (d > dr) {
    if (EQ(pr, qr)) {
      Point v = (qc - pc) / d * pr;
      v *= Point(0, 1);
      ret.emplace_back(Line{pc+v, qc+v});
      ret.emplace_back(Line{pc-v, qc-v});
    } else {
      Point cp = pc + (qc-pc) * pr / (pr-qr);
      vector<Point> pts = TangentPoints(p, cp);
      vector<Point> qts = TangentPoints(q, cp);
      for (int i=0; i<2; i++) {
        Line l{pts[0], qts[i]};
        if (IntersectLP(l, cp)) {
          ret.emplace_back(l);
          ret.emplace_back(Line{pts[1], qts[i^1]});
          break;
        }
      }
    }
  } 

  return ret;
}

int R;
int B;
Point ps[10];
Point qs[10];
int choice[10];

void dfs(int k, set<int> &st) {
  if (k == R) {
    puts("Yes");
    exit(0);
  }

  set<int> tmp(st);
  for (int u : tmp) {
    Line l{ps[k], qs[u]};
    bool found = false;
    for (int i=0; i<k; i++) {
      Line m{ps[i], ps[choice[i]]};
      if (IntersectSS(l, m)) {
        found = true;
        break;
      }
    }

    if (found) continue;
    st.erase(u);
    choice[k] = u;
    dfs(k+1, st);
    st.insert(u);
  }
}

int main() {
  scanf("%d%d", &R, &B);
  for (int i=0; i<R; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    ps[i] = Point(x, y);
  }

  for (int i=0; i<B; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    qs[i] = Point(x, y);
  }

  if (R != B) {
    puts("No");
    return 0;
  }

  set<int> st;
  for (int i=0; i<B; i++) {
    st.insert(i);
  }
  dfs(0, st);
  puts("No");
}