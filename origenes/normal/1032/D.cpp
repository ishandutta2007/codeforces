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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

pair<double, double> p1[2], p2[2];

int main() {
  int a, b, c;
  double x1, y1, x2, y2, ans;
  scanf("%d%d%d%lf%lf%lf%lf", &a, &b, &c, &x1, &y1, &x2, &y2);
  ans = double(abs(x1 - x2)) + abs(y1 - y2);
  if (!a) {
    double y = -c / double(b);
    chkmin(ans, abs(y1 - y) + abs(y2 - y) + abs(x1 - x2));
  } else if (!b) {
    double x = -c / double(a);
    chkmin(ans, abs(x1 - x) + abs(x2 - x) + abs(y1 - y2));
  } else {
    p1[0] = {x1, (-c - a * x1) / b};
    p1[1] = {(-c - b * y1) / a, y1};
    p2[0] = {x2, (-c - a * x2) / b};
    p2[1] = {(-c - b * y2) / a, y2};
    REP(i, 2) {
      double d1 = abs(p1[i]._1 - x1) + abs(p1[i]._2 - y1);
      REP(j, 2) {
        double d2 = abs(p2[j]._1 - x2) + abs(p2[j]._2 - y2);
        double d3 = sqrt(sqr(p1[i]._1 - p2[j]._1) + sqr(p1[i]._2 - p2[j]._2));
        chkmin(ans, d1 + d2 + d3);
      }
    }
  }
  printf("%.10lf", ans);
}