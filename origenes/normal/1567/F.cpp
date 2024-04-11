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
const int maxn = 512;

vector<int> G[maxn * maxn];
int ans[maxn][maxn];
int n, m;

bool dfs(int u, int c) {
  int x = u / m, y = u % m;
  ans[x][y] = c;
  for (auto v : G[u]) {
    int nx = v / m, ny = v % m;
    if (ans[nx][ny] && ans[nx][ny] == ans[x][y]) return false;
    if (!ans[nx][ny] && !dfs(v, 5 - c)) return false;
  }
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  auto f = [](pii coord) {
    return coord._1 * m + coord._2;
  };
  REP(i, n) REP(j, m) if (s[i][j] == 'X') {
    vector<pii> unmarked;
    REP(d, 4) {
      int ni = i + dx[d], nj = j + dy[d];
      if (s[ni][nj] == '.') unmarked.eb(ni, nj);
    }
    if (unmarked.size() % 2 == 1) {
      cout << "NO\n";
      return 0;
    }
    if (unmarked.empty()) continue;
    if (unmarked.size() == 2) {
      int u = f(unmarked[0]), v = f(unmarked[1]);
      G[u].eb(v); G[v].eb(u);
    } else {
      int u = f(unmarked[0]), v = f(unmarked[2]);
      G[u].eb(v); G[v].eb(u);
      u = f(unmarked[1]), v = f(unmarked[3]);
      G[u].eb(v); G[v].eb(u);
    }
  }
  REP(i, n) REP(j, m) if (s[i][j] == '.' && !ans[i][j]) {
    auto ok = dfs(f(mp(i, j)), 1);
    if (!ok) {
      cout << "NO\n";
      return 0;
    }
  }
  REP(i, n) REP(j, m) if (s[i][j] == 'X') {
    REP(d, 4) {
      int ni = i + dx[d], nj = j + dy[d];
      if (s[ni][nj] == '.') ans[i][j] += ans[ni][nj];
    }
  }
  cout << "YES\n";
  REP(i, n) {
    REP(j, m) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}