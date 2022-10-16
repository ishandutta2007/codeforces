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

int n, m, k, q;
int a[maxn][maxn], f[maxn][maxn][40];
vector<pii> c[40];

void bfs(int now) {
  queue<pii> Q;
  for (auto [x, y] : c[now]) {
    f[x][y][now] = 0;
    Q.emplace(x, y);
  }
  vector<char> vis(k);
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();
    if (!vis[a[x][y]]) {
      vis[a[x][y]] = true;
      for (auto [nx, ny] : c[a[x][y]]) if (f[nx][ny][now] == -1) {
        f[nx][ny][now] = f[x][y][now] + 1;
        Q.emplace(nx, ny);
      }
    }
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m && f[nx][ny][now] == -1) {
        f[nx][ny][now] = f[x][y][now] + 1;
        Q.emplace(nx, ny);
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) FOR(j, 1, m) {
      scanf("%d", &a[i][j]);
      c[--a[i][j]].eb(i, j);
    }
  reset(f, -1);
  REP(i, k) bfs(i);
  scanf("%d", &q);
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int cap = abs(r1 - r2) + abs(c1 - c2);
    REP(i, k) chkmin(cap, f[r1][c1][i] + f[r2][c2][i] + 1);
    printf("%d\n", cap);
  }
}