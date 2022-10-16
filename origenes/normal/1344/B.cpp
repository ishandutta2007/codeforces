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
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
char s[maxn][maxn];
bool bc[maxn], br[maxn], mark[maxn][maxn], vis[maxn][maxn];

void dfs(int x, int y) {
  vis[x][y] = true;
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx > 0 && nx <= n && ny > 0 && ny <= m && s[nx][ny] == '#' && !vis[nx][ny]) dfs(nx, ny);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  FOR(i, 1, n) FOR(j, 1, m) br[i] |= s[i][j] == '#';
  FOR(i, 1, m) FOR(j, 1, n) bc[i] |= s[j][i] == '#';
  FOR(i, 1, n) FOR(j, 1, m) if (s[i][j] == '#' || (!bc[j] && !br[i])) mark[i][j] = true;
  reset(bc, 0); reset(br, 0);
  FOR(i, 1, n) FOR(j, 1, m) br[i] |= mark[i][j], bc[j] |= mark[i][j];
  FOR(i, 1, n) if (!br[i]) {
    puts("-1");
    return 0;
  }
  FOR(j, 1, m) if (!bc[j]) {
    puts("-1");
    return 0;
  }
  FOR(i, 1, n) {
    int fi = -1, se = -1;
    FOR(j, 1, m) if (s[i][j] == '#') {
      fi = j;
      break;
    }
    ROF(j, m, 1) if (s[i][j] == '#') {
      se = j;
      break;
    }
    FOR(j, fi + 1, se - 1) if (s[i][j] == '.') {
      puts("-1");
      return 0;
    }
  }
  FOR(j, 1, m) {
    int fi = -1, se = -1;
    FOR(i, 1, n) if (s[i][j] == '#') {
      fi = i;
      break;
    }
    ROF(i, n, 1) if (s[i][j] == '#') {
      se = i;
      break;
    }
    FOR(i, fi + 1, se - 1) if (s[i][j] == '.') {
      puts("-1");
      return 0;
    }
  }
  int ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) if (!vis[i][j] && s[i][j] == '#') {
    ans++;
    dfs(i, j);
  }
  printf("%d", ans);
}