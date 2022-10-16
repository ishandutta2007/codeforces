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

const int maxn = 20;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n, m, sz;
int f[maxn][maxn][1 << 8], val[1 << 8], px[8], py[8], v[8];
char mat[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", mat[i]);
  REP(i, n) REP(j, m) if (isdigit(mat[i][j])) {
    px[mat[i][j] - '1'] = i, py[mat[i][j] - '1'] = j;
    sz++;
  }
  REP(i, sz) scanf("%d", v + i);
  REP(i, n) REP(j, m) if (mat[i][j] == 'B') {
    px[sz] = i, py[sz] = j;
    v[sz] = -1e8;
    sz++;
  }
  REP(mask, 1 << sz) REP(i, sz) if (mask & (1 << i)) val[mask] += v[i];
  int sx, sy;
  REP(i, n) REP(j, m) if (mat[i][j] == 'S') {
    sx = i, sy = j;
    break;
  }
  reset(f, 0x3f);
  queue<tuple<int, int, int>> q;
  q.emplace(sx, sy, 0);
  f[sx][sy][0] = 0;
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    int x = get<0>(u), y = get<1>(u), mask = get<2>(u);
    REP(d, 4) {
      int nx = x + dx[d], ny = y + dy[d], nmask = mask;
      if (nx < 0 || ny < 0 || nx >= n || ny >= m || mat[nx][ny] == '#' || isdigit(mat[nx][ny]) || mat[nx][ny] == 'B') continue;
      if (d == 3) {REP(i, sz) if (y < py[i] && x == px[i]) nmask ^= 1 << i;}
      else if (d == 2) REP(i, sz) if (y < py[i] && nx == px[i]) nmask ^= 1 << i;
      if (f[x][y][mask] + 1 < f[nx][ny][nmask]) {
        f[nx][ny][nmask] = f[x][y][mask] + 1;
        q.emplace(nx, ny, nmask);
      }
    }
  }
  int ans = 0;
  REP(mask, 1 << sz) chkmax(ans, val[mask] - f[sx][sy][mask]);
  printf("%d", ans);
}