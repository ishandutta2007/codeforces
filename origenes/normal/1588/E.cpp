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

const int maxn = 3123;
const double pi = acos(-1);
const double eps = 1e-9;

int n, R;
int cnt[maxn][maxn], x[maxn], y[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> R;
  FOR(i, 1, n) cin >> x[i] >> y[i];
  FOR(i, 1, n) {
    vector<pair<double, int>> events;
    int req = n - 1;
    FOR(j, 1, n) if (i != j) {
      int dx = x[j] - x[i], dy = y[j] - y[i];
      double t = atan2(dy, dx), a = asin(R / sqrt(sqr(ll(dx)) + sqr(ll(dy))));
      events.eb(t, j + 1);
      if (sqr(ll(dx)) + sqr(ll(dy)) <= sqr(ll(R))) {
        req--;
        continue;
      }
      double lo = t - a, hi = t + a;
      if (lo < -pi) lo += 2 * pi;
      if (hi > pi) hi -= 2 * pi;
      if (abs(lo - hi) < eps) continue;
      if (lo <= hi) {
        events.eb(lo - eps, 1);
        events.eb(hi + eps, -1);
      } else {
        events.eb(lo - eps, 1); events.eb(pi + eps, -1);
        events.eb(-pi - eps, 1); events.eb(hi + eps, -1);
      }
    }
    sort(all(events));
    int c = 0;
    for (auto [_, d] : events) {
      if (d == -1 || d == 1) {
        c += d;
        continue;
      }
      if (c == req) {
        int j = d - 1;
        assert(i != j);
        if (i < j) cnt[i][j]++;
        else cnt[j][i]++;
      }
    }
  }
  int ans = 0;
  FOR(i, 1, n) FOR(j, i + 1, n) if (cnt[i][j] == 2) ans++;
  cout << ans;
}