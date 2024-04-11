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
  int m, k;
  cin >> m >> k;
  vector<pii> a;
  REP(i, k) {
    int c;
    cin >> c;
    a.eb(c, i + 1);
  }
  sort(all(a), greater<>());
  ll n = 1;
  while (a[0]._1 > (n + 1) / 2 * n || m > sqr(n) - sqr(n / 2)) n++;
  vector<vector<int>> ans(n, vector<int>(n));
  vector<pii> u[2], v;
  REP(i, n) REP(j, n) {
    if ((i + j) % 2 == 0) {
      if (i % 2 == 0) v.eb(i, j);
    } else u[i % 2].eb(i, j);
  }
  int i = 0;
  for (auto [cnt, c] : a) {
    if (i == 0 && u[0].empty()) i++;
    while (!u[i].empty() && cnt) {
      auto [x, y] = u[i].back(); u[i].pop_back();
      ans[x][y] = c;
      cnt--;
    }
    while (!v.empty() && cnt) {
      auto [x, y] = v.back(); v.pop_back();
      ans[x][y] = c;
      cnt--;
    }
  }
  cout << n << '\n';
  REP(x, n) {
    REP(y, n) cout << ans[x][y] << ' ';
    cout << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}