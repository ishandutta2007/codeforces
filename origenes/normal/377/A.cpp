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

const int maxn = 512;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char mat[maxn][maxn];
bool vis[maxn][maxn];
int n, m, k, deg[maxn][maxn];
pii par[maxn][maxn];

void dfs(int x, int y) {
  vis[x][y] = true;
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || mat[nx][ny] != '.') continue;
    deg[x][y]++;
    par[nx][ny] = {x, y};
    dfs(nx, ny);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  REP(i, n) scanf("%s", mat[i]);
  REP(i, n) REP(j, m) if (mat[i][j] == '.') {
    dfs(i, j);
    break;
  }
  queue<pii> q;
  REP(i, n) REP(j, m) if (mat[i][j] == '.' && !deg[i][j]) q.emplace(i, j);
  while (k--) {
    int x = q.front()._1, y = q.front()._2; q.pop();
    mat[x][y] = 'X';
    int px = par[x][y]._1, py = par[x][y]._2;
    if (!--deg[px][py]) q.emplace(px, py);
  }
  REP(i, n) puts(mat[i]);
}