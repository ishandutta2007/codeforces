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
  int n, k;
  cin >> n >> k;
  vector<bool> used(2 * n + 1);
  vector<pii> edges(k);
  for (auto &[x, y] : edges) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    used[x] = used[y] = true;
  }
  vector<int> rem;
  FOR(i, 1, 2 * n) if (!used[i]) rem.eb(i);
  REP(i, n - k) edges.eb(rem[i], rem[i + n - k]);
  int ans = 0;
  REP(i, n) FOR(j, i + 1, n - 1) {
    auto [x1, y1] = edges[i];
    auto [x2, y2] = edges[j];
    if (x1 > x2) swap(x1, x2), swap(y1, y2);
    if (x2 < y1 && y1 < y2) ans++;
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}