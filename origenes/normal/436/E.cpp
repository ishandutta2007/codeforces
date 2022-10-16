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

const int maxn = 312345;

int n, w;
int a[maxn], b[maxn], id[maxn], res[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> w;
  FOR(i, 1, n) cin >> a[i] >> b[i];
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [](int i, int j) { return b[i] < b[j]; });
  ll ans = 1e18, s = 0, tot = 0;
  int best = 0;
  set<pii, greater<>> q;
  FOR(i, 1, n) {
    q.emplace(a[id[i]], id[i]);
    tot += a[i];
  }
  REP(i, n + 1) {
    if (i > w) break;
    s += a[id[i]];
    if (i) {
      if (q.count(mp(a[id[i]], id[i]))) {
        tot -= a[id[i]];
        q.erase(mp(a[id[i]], id[i]));
      }
      tot += b[id[i]] - a[id[i]];
      q.emplace(b[id[i]] - a[id[i]], id[i]);
    }
    while (q.size() > w - i) {
      tot -= q.begin()->_1;
      q.erase(q.begin());
    }
    if (i + q.size() < w) continue;
    if (ans > tot + s) {
      best = i;
      ans = tot + s;
    }
  }
  q.clear();
  tot = s = 0;
  FOR(i, 1, n) {
    q.emplace(a[id[i]], id[i]);
    tot += a[i];
  }
  REP(i, best + 1) {
    if (i > w) break;
    s += a[id[i]];
    if (i) {
      if (q.count(mp(a[id[i]], id[i]))) {
        tot -= a[id[i]];
        q.erase(mp(a[id[i]], id[i]));
      }
      tot += b[id[i]] - a[id[i]];
      q.emplace(b[id[i]] - a[id[i]], id[i]);
    }
    while (q.size() > w - i) {
      tot -= q.begin()->_1;
      q.erase(q.begin());
    }
    if (i + q.size() < w) continue;
  }
  cout << ans << '\n';
  FOR(i, 1, best) res[id[i]]++;
  for (auto [_, u] : q) res[u]++;
  FOR(i, 1, n) cout << res[i];
}