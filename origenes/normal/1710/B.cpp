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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n), p(n);
  vector<pii> events;
  REP(i, n) {
    cin >> x[i] >> p[i];
    events.eb(x[i] - p[i], 1);
    events.eb(x[i], -2);
    events.eb(x[i] + p[i], 1);
  }
  sort(all(events));
  ll mn = 1e18, mx = -1e18;
  ll a = 0, b = 0;
  REP(i, int(size(events)) - 1) {
    if (b > m) {
      chkmax(mx, b - m + events[i]._1);
      chkmin(mn, events[i]._1 - b + m);
    }
    a += events[i]._2;
    b += a * (events[i + 1]._1 - events[i]._1);
  }
  REP(i, n) cout << ((x[i] - p[i]) <= mn && x[i] + p[i] >= mx);
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}