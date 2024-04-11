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
const int MOD = 1e9 + 7;
const double eps = 1e-9;

inline int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n;
pair<double, double> pts[maxn];

struct Seg {
  double x, y, k;

  Seg() = default;

  Seg(double x, double y, double k) : x(x), y(y), k(k) {}

  bool operator < (const Seg &rhs) const {
    if (dcmp(x - rhs.x) == 0) return dcmp(y - rhs.y) ? y < rhs.y : k < rhs.k;
    return x < rhs.x;
  }
};

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    double x = a / b, y = c / d;
    pts[i] = {x / (sqr(x) + sqr(y)), y / (sqr(x) + sqr(y))};
  }
  vector<Seg> vec;
  FOR(i, 1, n) FOR(j, i + 1, n) {
    double k = dcmp(pts[i]._1 - pts[j]._1) ? (pts[i]._2 - pts[j]._2) / (pts[i]._1 - pts[j]._1) : 1e18;
    vec.eb(pts[i]._1 + pts[j]._1, pts[i]._2 + pts[j]._2, k);
  }
  sort(all(vec));
  int ans = 0;
  for (int i = 0, j; i < int(vec.size()); i = j) {
    int now = 1, cnt = 1;
    for (j = i + 1; j < int(vec.size()) && dcmp(vec[j].x - vec[i].x) == 0 && dcmp(vec[j].y - vec[i].y) == 0; j++) {
      if (dcmp(vec[j].k - vec[j - 1].k)) now = mul(now, cnt + 1), cnt = 1;
      else cnt++;
    }
    now = add(mul(now, cnt + 1), MOD - 1);
    ans = add(ans, now);
  }
  printf("%d", add(ans, MOD - int(vec.size())));
}