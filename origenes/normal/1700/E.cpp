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

const int dx[] = {-1, 1, 0, 0, 0};
const int dy[] = {0, 0, -1, 1, 0};

int n, m;
vector<vector<int>> a;
vector<vector<bool>> v, vis;
vector<pii> bad;

bool inside(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool good(int x, int y) {
  auto check = [x, y](int i, int j) {
    if (!inside(i, j)) return false;
    return a[x][y] > a[i][j];
  };
  return a[x][y] == 1 || check(x + 1, y) || check(x - 1, y) || check(x, y + 1) || check(x, y - 1);
}

bool check(int x1, int y1, int x2, int y2) {
  swap(a[x1][y1], a[x2][y2]);
  int cnt = 0;
  auto go = [&cnt](int i, int j) {
    REP(d, 5) {
      int x = i + dx[d], y = j + dy[d];
      if (!inside(x, y) || vis[x][y]) continue;
      vis[x][y] = true;
      cnt += v[x][y] - !good(x, y);
    }
  };
  go(x1, y1);
  go(x2, y2);
  REP(d, 5) {
    int x = x1 + dx[d], y = y1 + dy[d];
    if (inside(x, y)) vis[x][y] = false;
    x = x2 + dx[d], y = y2 + dy[d];
    if (inside(x, y)) vis[x][y] = false;
  }
  swap(a[x1][y1], a[x2][y2]);
  return size(bad) == cnt;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  a = vector<vector<int>>(n + 1, vector<int>(m + 1));
  v = vis = vector<vector<bool>>(n + 1, vector<bool>(m + 1));
  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
  FOR(i, 1, n) FOR(j, 1, m) if (!good(i, j)) {
    bad.eb(i, j);
    v[i][j] = true;
  }
  if (bad.empty()) {
    cout << 0;
    return 0;
  }
  if (size(bad) > 10) {
    cout << 2;
    return 0;
  }
  set<ll> s;
  int ans = 0;
  REP(d, 5) {
    int x = bad[0]._1 + dx[d], y = bad[0]._2 + dy[d];
    if (!inside(x, y)) continue;
    FOR(i, 1, n) FOR(j, 1, m) {
      ll c1 = ll((x - 1) * m + y) * n * m + ((i - 1) * m + j);
      ll c2 = ll((i - 1) * m + j) * n * m + ((x - 1) * m + y);
      if (!s.count(c1) && !s.count(c2)) {
        ans += check(x, y, i, j);
        s.emplace(c1);
        s.emplace(c2);
      }
    }
  }
  if (ans == 0) cout << 2;
  else cout << "1 " << ans;
}