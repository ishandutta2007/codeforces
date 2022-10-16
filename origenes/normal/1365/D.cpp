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
char G[maxn][maxn];

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  int g = 0;
  FOR(i, 1, n) FOR(j, 1, m) if (G[i][j] == 'G') g++;
  if (g == 0) {
    puts("Yes");
    return;
  }
  FOR(i, 1, n) FOR(j, 1, m) if (G[i][j] == 'B') {
    REP(d, 4) {
      int ni = i + dx[d], nj = j + dy[d];
      if (ni < 1 || ni > n || nj < 1 || nj > m || G[ni][nj] == 'B') continue;
      G[ni][nj] = '#';
    }
    G[i][j] = '#';
  }
  if (G[n][m] == '#') {
    puts("No");
    return;
  }
  queue<pii> q;
  q.emplace(n, m);
  vector<vector<char>> vis(n + 1, vector<char>(m + 1));
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m && G[nx][ny] != '#' && !vis[nx][ny]) {
        vis[nx][ny] = true;
        q.emplace(nx, ny);
        if (G[nx][ny] == 'G') g--;
      }
    }
  }
  puts(g == 0 ? "Yes" : "No");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}