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

char G[maxn][maxn];
int f[maxn][maxn][maxn][maxn], n;
bool vis[maxn][maxn][maxn][maxn];

int dfs(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  if (vis[x1][y1][x2][y2]) return f[x1][y1][x2][y2];
  vis[x1][y1][x2][y2] = true;
  int &ret = f[x1][y1][x2][y2];
  if (x1 == x2 && y1 == y2) return ret = G[x1][y1] == '#';
  ret = max(x2 - x1 + 1, y2 - y1 + 1);
  FOR(i, x1, x2 - 1) chkmin(ret, dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
  FOR(i, y1, y2 - 1) chkmin(ret, dfs(x1, y1, x2, i) + dfs(x1, i + 1, x2, y2));
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%s", G[i] + 1);
  printf("%d", dfs(1, 1, n, n));
}