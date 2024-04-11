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

const double eps = 1e-9;

int dcmp(double x) {
  if (abs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, d;
  vector<pair<double, int>> events;
  cin >> n >> d;
  while (n--) {
    int x, y, r;
    cin >> x >> y >> r;
    double R = sqrt(sqr(x) + sqr(y));
    double L = int(R - r) / d * d;
    if (dcmp(L - (R - r)) < 0) L += d;
    double ang = atan2(y, x);
    while (dcmp(L - R - r) <= 0) {
      double delta = acos((sqr(x) + sqr(y) + sqr(L) - sqr(r)) / 2 / R / L);
      events.eb(ang - delta, 1);
      events.eb(ang + delta + eps, -1);
      L += d;
    }
  }
  sort(all(events));
  int s = 0, ans = 0;
  for (auto [_, v] : events) {
    s += v;
    chkmax(ans, s);
  }
  cout << ans;
}