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

const int maxn = 1123;

struct Point {
  int x, y;

  bool operator < (const Point &rhs) const {
    return x == rhs.x ? y < rhs.y : x < rhs.x;
  }

  void get() {
    scanf("%d%d", &x, &y);
  }
};

struct Line {
  Point a, b;
  ll cnt;
} line[maxn];

inline bool between(ll mi, ll lo, ll hi) {
  if (lo > hi) swap(lo, hi);
  return lo <= mi && mi <= hi;
}

bool inter(Point &o, const Line &l1, const Line &l2) {
  ll x1 = l1.a.x, y1 = l1.a.y, dx1 = (l1.b.x - l1.a.x) / l1.cnt, dy1 = (l1.b.y - l1.a.y) / l1.cnt;
  ll x2 = l2.a.x, y2 = l2.a.y, dx2 = (l2.b.x - l2.a.x) / l2.cnt, dy2 = (l2.b.y - l2.a.y) / l2.cnt;
  ll cross = dx2 * dy1 - dy2 * dx1, dot = (y2 - y1) * dx1 - (x2 - x1) * dy1;
  if (!cross || dot % cross) return false;
  ll r = dot / cross, x = x2 + r * dx2, y = y2 + r * dy2;
  if (between(x, l1.a.x, l1.b.x) && between(y, l1.a.y, l1.b.y) && between(x, l2.a.x, l2.b.x) && between(y, l2.a.y, l2.b.y)) {
    o.x = x, o.y = y;
    return true;
  }
  return false;
}

ll ans;
set<Point> s[maxn], comb;
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    line[i].a.get(); line[i].b.get();
    line[i].cnt = __gcd(abs(line[i].a.x - line[i].b.x), abs(line[i].a.y - line[i].b.y));
  }
  FOR(i, 1, n) {
    FOR(j, 1, n) if (i != j) {
      Point o;
      if (inter(o, line[i], line[j])) {
        s[i].emplace(o);
        comb.emplace(o);
      }
    }
    ans += line[i].cnt + 1 - int(s[i].size());
  }
  printf("%lld", ans + comb.size());
}