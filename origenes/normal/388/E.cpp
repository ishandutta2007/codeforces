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

const int maxn = 1123;
const double eps = 1e-7;

struct Line {
  double x, y, vx, vy;

  void read() {
    double t1, t2;
    scanf("%lf%lf%lf%lf%lf%lf", &t1, &x, &y, &t2, &vx, &vy);
    vx = (vx - x) / (t2 - t1);
    vy = (vy - y) / (t2 - t1);
    x -= vx * t1, y -= vy * t1;
  }
} lines[maxn];

inline int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  bool operator < (const Point &rhs);
};

double cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

bool Point::operator<(const Point &rhs) {
  if (dcmp(cross(*this, rhs)) == 0) return dcmp(x - rhs.x) == 0 ? y < rhs.y : x < rhs.x;
  return cross(*this, rhs) < 0;
}

int n, ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) lines[i].read();
  FOR(i, 1, n) {
    vector<double> moments;
    vector<Point> vec;
    FOR(j, 1, n) if (i != j) {
      Line d = {lines[j].x - lines[i].x, lines[j].y - lines[i].y, lines[j].vx - lines[i].vx, lines[j].vy - lines[i].vy};
      double t = dcmp(d.vx) ? d.x / d.vx : dcmp(d.vy) ? d.y / d.vy : 0;
      if (dcmp(d.x - t * d.vx) == 0 && dcmp(d.y - t * d.vy) == 0) {
        moments.eb(t);
        vec.eb(d.vx, d.vy);
      }
    }
    sort(all(moments));
    int m = moments.size(), cnt = 1;
    if (m) chkmax(ans, 1);
    FOR(j, 1, m - 1) {
      if (dcmp(moments[j] - moments[j - 1]) == 0) cnt++;
      else cnt = 1;
      chkmax(ans, cnt);
    }
    cnt = 1;
    sort(all(vec));
    FOR(j, 1, m - 1) {
      if (dcmp(cross(vec[j], vec[j - 1])) == 0) {
        if (dcmp(vec[j].x - vec[j - 1].x) || dcmp(vec[j].y - vec[j - 1].y)) cnt++;
      } else cnt = 1;
      chkmax(ans, cnt);
    }
  }
  printf("%d", ans + 1);
}