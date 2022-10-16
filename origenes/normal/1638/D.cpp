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

const int maxn = 1123;

int n, m;
int a[maxn][maxn];
bool vis[maxn][maxn];

bool check(int x, int y) {
  if (x < 1 || x + 1 > n || y < 1 || y + 1 > m) return false;
  if (vis[x][y]) return false;
  set<int> c;
  FOR(i, x, x + 1) FOR(j, y, y + 1) if (a[i][j]) c.emplace(a[i][j]);
  return size(c) <= 1;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
  queue<pii> q;
  FOR(i, 1, n - 1) FOR(j, 1, m - 1) if (check(i, j)) {
    vis[i][j] = true;
    q.emplace(i, j);
  }
  vector<tuple<int, int, int>> ans;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    int c = 0;
    FOR(i, x, x + 1) FOR(j, y, y + 1) chkmax(c, a[i][j]);
    a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 0;
    if (c) ans.eb(x, y, c);
    FOR(i, x - 1, x + 1) FOR(j, y - 1, y + 1) if (check(i, j)) {
      q.emplace(i, j);
      vis[i][j] = true;
    }
  }
  FOR(i, 1, n) FOR(j, 1, m) if (a[i][j]) {
    cout << -1;
    return 0;
  }
  reverse(all(ans));
  cout << size(ans) << '\n';
  for (auto [x, y, c] : ans) cout << x << ' ' << y << ' ' << c << '\n';
}