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

const int maxn = 15;

int mat[maxn][maxn], dir[maxn];
bool vis[maxn][maxn];
double f[maxn][maxn];

double dfs(int x, int y) {
  if (vis[x][y]) return f[x][y];
  vis[x][y] = true;
//  cerr << x << ' ' << y << endl;
  int mv = 6;
  FOR(roll, 1, 6) {
    int nx = x, ny = y;
    ny += dir[x] * roll;
    if (ny > 10 || ny < 1) nx--;
    if (nx < 1) {
      mv--;
      continue;
    }
    if (ny > 10) ny = 11 - (ny - 10);
    if (ny < 1) ny = 1 - ny;
    if (!mat[nx][ny]) f[x][y] += dfs(nx, ny);
    else f[x][y] += min(dfs(nx, ny), dfs(nx - mat[nx][ny], ny));
  }
  return f[x][y] = (f[x][y] / 6 + 1) / mv * 6;
}

int main() {
  vis[1][1] = true;
  FOR(i, 1, 10) {
    FOR(j, 1, 10) scanf("%d", &mat[i][j]);
    if (i & 1) dir[i] = -1;
    else dir[i] = 1;
  }
  printf("%.10lf", dfs(10, 1));
}