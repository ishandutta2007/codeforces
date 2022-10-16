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

const int maxn = 55;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
string s[maxn];

void dfs(int x, int y) {
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (s[nx][ny] == '.') {
      s[nx][ny] = s[x][y] == 'R' ? 'W' : 'R';
      dfs(nx, ny);
    }
  }
}

void solve() {
  cin >> n >> m;
  REP(i, n) cin >> s[i];
  REP(i, n) REP(j, m) if (s[i][j] != '.') dfs(i, j);
  if (s[0][0] == '.') {
    s[0][0] = 'R';
    dfs(0, 0);
  }
  bool bad = false;
  REP(i, n) REP(j, m) {
    int ni = i + 1, nj = j + 1;
    if (nj < m && s[i][j] == s[i][nj]) bad = true;
    if (ni < n && s[i][j] == s[ni][j]) bad = true;
  }
  if (bad) cout << "NO\n";
  else {
    cout << "YES\n";
    REP(i, n) cout << s[i] << '\n';
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