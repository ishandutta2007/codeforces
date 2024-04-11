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
  int n, m; cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));
  set<pair<int, pii>> s;
  REP(i, n) REP(j, m) cin >> b[i][j];
  REP(i, n) REP(j, m) {
    s.emplace(b[i][j], mp(i, j));
    if (s.size() > m) s.erase(*s.rbegin());
  }
  vector<vector<int>> way(n, vector<int>(m, -1));
  REP(i, m) {
    auto [x, y] = s.begin()->_2;
    way[x][y] = i;
    s.erase(s.begin());
  }
  REP(i, n) {
    set<int> avails;
    REP(j, m) avails.emplace(j);
    REP(j, m) if (way[i][j] != -1) avails.erase(way[i][j]);
    REP(j, m) if (way[i][j] == -1) {
      way[i][j] = *avails.begin();
      avails.erase(avails.begin());
    }
  }
  vector<vector<int>> ans(n, vector<int>(m));
  REP(i, n) REP(j, m) ans[i][way[i][j]] = b[i][j];
  REP(i, n) {
    for (auto x : ans[i]) cout << x << ' ';
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