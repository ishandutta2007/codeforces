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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 55;

struct Restriction {
  int l, r, x, c;
} rs[maxn];

int n, h, m;
int dp[maxn][maxn][maxn], cost[maxn][maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];

int dfs(int lo, int hi, int up) {
  if (up < 0 || lo > hi) return 0;
  if (vis[lo][hi][up]) return dp[lo][hi][up];
  vis[lo][hi][up] = true;
  int &ret = dp[lo][hi][up];
  ret = dfs(lo, hi, up - 1);
  FOR(i, lo, hi) chkmax(ret, up * up - cost[lo][i][hi][up] + dfs(lo, i - 1, up) + dfs(i + 1, hi, up));
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &h, &m);
  FOR(i, 1, m) scanf("%d%d%d%d", &rs[i].l, &rs[i].r, &rs[i].x, &rs[i].c);
  FOR(i, 1, n) FOR(j, i, n) {
    FOR(k, 1, m) if (i <= rs[k].l && rs[k].r <= j) {
      cost[i][rs[k].l][j][rs[k].x + 1] += rs[k].c;
      cost[i][rs[k].r + 1][j][rs[k].x + 1] -= rs[k].c;
    }
    FOR(k, i + 1, j) REP(x, maxn) cost[i][k][j][x] += cost[i][k - 1][j][x];
    FOR(k, i, j) FOR(x, 1, maxn - 1) cost[i][k][j][x] += cost[i][k][j][x - 1];
  }
  printf("%d", dfs(1, n, h));
}