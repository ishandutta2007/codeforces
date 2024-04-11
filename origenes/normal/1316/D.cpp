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
const char moves[] = "UDLR";

int n;
int x[maxn][maxn], y[maxn][maxn];
char mat[maxn][maxn];
bool vis[maxn][maxn];
vector<pii> cc;
set<pii> G[maxn][maxn];
int par[maxn][maxn];

void dfsi(int r, int c) {
  vis[r][c] = true;
  cc.eb(r, c);
  REP(i, 4) {
    int nr = r + dx[i], nc = c + dy[i];
    if (1 <= nr && nr <= n && 1 <= nc && nc <= n && !vis[nr][nc] && x[nr][nc] == -1) {
      dfsi(nr, nc);
      G[r][c].emplace(nr, nc);
      par[nr][nc] = i;
    }
  }
}

void dfs(int r, int c) {
  vis[r][c] = true;
  REP(i, 4) {
    int nr = r + dx[i], nc = c + dy[i];
    if (1 <= nr && nr <= n && 1 <= nc && nc <= n && !vis[nr][nc] && x[nr][nc] == x[r][c] && y[nr][nc] == y[r][c]) {
      dfs(nr, nc);
      mat[nr][nc] = moves[i ^ 1];
    }
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) FOR(j, 1, n) scanf("%d%d", &x[i][j], &y[i][j]);
  reset(par, -1);
  FOR(i, 1, n) FOR(j, 1, n) if (!vis[i][j]) {
    if (x[i][j] == -1) {
      cc.clear();
      dfsi(i, j);
      queue<pii> q;
      for (auto [r, c] : cc) if (G[r][c].empty()) q.emplace(r, c);
      while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if (par[r][c] != -1) {
          mat[r][c] = moves[par[r][c] ^ 1];
          auto [pr, pc] = mp(r - dx[par[r][c]], c - dy[par[r][c]]);
          G[pr][pc].erase(mp(r, c));
          if (G[pr][pc].empty()) q.emplace(pr, pc);
        } else {
          bool found = false;
          REP(_, 4) {
            int nr = r + dx[_], nc = c + dy[_];
            if (1 <= nr && nr <= n && 1 <= nc && nc <= n && x[nr][nc] == -1) {
              mat[r][c] = moves[_];
              found = true;
            }
          }
          if (!found) {
            puts("INVALID");
            return 0;
          }
        }
      }
    } else if (x[i][j] == i && y[i][j] == j) {
      cc.clear();
      mat[i][j] = 'X';
      dfs(i, j);
    }
  }
  FOR(i, 1, n) FOR(j, 1, n) if (mat[i][j] == 0) {
    puts("INVALID");
    return 0;
  }
  puts("VALID");
  FOR(i, 1, n) puts(mat[i] + 1);
}
/*
 3
1 1 1 2 -1 -1
-1 -1 2 2 -1 -1
-1 -1 -1 -1 -1 -1
 */