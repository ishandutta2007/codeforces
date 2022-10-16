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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> G(n);
  G.resize(n);
  REP(i, n) cin >> G[i];
  auto ans = G;
  int x, y;
  REP(i, n) REP(j, m) if (G[i][j] == 'L') {
    x = i, y = j;
    break;
  }
  queue<pii> q; q.emplace(x, y);
  while (!q.empty()) {
    tie(x, y) = q.front(); q.pop();
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || ans[nx][ny] != '.') continue;
      int cnt = 0, out = 0;
      REP(j, 4) {
        int xx = nx + dx[j], yy = ny + dy[j];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || G[xx][yy] == '#') continue;
        if (ans[xx][yy] != 'L' && ans[xx][yy] != '+') cnt++;
        out++;
      }
      if (cnt <= 1 && out > 0) {
        ans[nx][ny] = '+';
        q.emplace(nx, ny);
      }
    }
  }
  REP(i, n) REP(j, m) if (ans[i][j] == '-') ans[i][j] = '.';
  REP(i, n) cout << ans[i] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}