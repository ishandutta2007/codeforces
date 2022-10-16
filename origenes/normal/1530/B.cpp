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

const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> ans(h);
  REP(i, h) ans[i] = string(w, '0');
  for (int j = 0; j < w; j += 2) ans[0][j] = '1';
  auto check = [&](int x, int y) {
    REP(d, 8) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (ans[nx][ny] == '1') return false;
    }
    return true;
  };
  REP(i, h) if (check(i, w - 1)) ans[i][w - 1] = '1';
  ROF(j, w - 1, 0) if (check(h - 1, j)) ans[h - 1][j] = '1';
  ROF(i, h - 1, 0) if (check(i, 0)) ans[i][0] = '1';
  REP(i, h) cout << ans[i] << '\n';
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