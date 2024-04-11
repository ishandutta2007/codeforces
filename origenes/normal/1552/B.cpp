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
  int n; cin >> n;
  vector<vector<int>> r(n, vector<int>(5));
  REP(i, n) REP(j, 5) cin >> r[i][j];
  queue<int> q;
  REP(i, n) q.emplace(i);
  while (q.size() > 1) {
    queue<int> p;
    while (!q.empty()) {
      if (q.size() == 1) {
        auto u = q.front(); q.pop();
        p.emplace(u);
        continue;
      }
      auto u = q.front(); q.pop();
      auto v = q.front(); q.pop();
      int su = 0;
      REP(j, 5) if (r[u][j] < r[v][j]) su++;
      if (su >= 3) p.emplace(u);
      else p.emplace(v);
    }
    swap(p, q);
  }
  auto ans = q.front();
  REP(i, n) if (i != ans) {
    int cur = 0;
    REP(j, 5) if (r[ans][j] < r[i][j]) cur++;
    if (cur < 3) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans + 1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}