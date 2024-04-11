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

const int maxn = 25;

bool vis[maxn * 2][1 << 20];
int f[maxn * 2][1 << 20], mask[maxn * 2][26], n;
char mat[maxn][maxn];

int dfs(int i, int s, int now, bool flag) {
  if (vis[i][s]) return f[i][s];
  vis[i][s] = true;
  int &ret = f[i][s];
  ret = -1e9;
  if (i == 2 * n - 2) ret = 0;
  else {
    REP(nxt, 26) {
      int ns = mask[i + 1][nxt] & (s | (s << 1));
      if (ns) chkmax(ret, -dfs(i + 1, ns, nxt, !flag));
    }
  }
  if (flag) {
    if (now == 0) ret++;
    else if (now == 1) ret--;
  } else {
    if (now == 0) ret--;
    else if (now == 1) ret++;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%s", mat[i]);
  REP(i, 2 * n) REP(j, 26) REP(k, n) {
    int x = k, y = i - k;
    if (y >= 0 && y < n && mat[x][y] == j + 'a') mask[i][j] |= 1 << k;
  }
  int ans = dfs(0, 1, mat[0][0] - 'a', false);
  if (ans < 0) puts("FIRST");
  else if (ans > 0) puts("SECOND");
  else puts("DRAW");
}