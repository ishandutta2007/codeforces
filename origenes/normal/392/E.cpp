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

const int maxn = 412;
const int inf = 1e9;

int n, w[maxn], v[maxn], f[maxn][maxn], g[maxn][maxn], h[maxn][maxn], ans[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", v + i);
  FOR(i, 1, n) scanf("%d", w + i);
  FOR(len, 1, n) FOR(i, 1, n - len + 1) {
    int j = i + len - 1;
    if (len == 1) {
      f[i][j] = v[1];
      continue;
    }
    g[i][j] = h[i][j] = f[i][j] = -inf;
    FOR(k, i + 1, j) {
      if (w[k] == w[i] + 1) chkmax(g[i][j], f[i + 1][k - 1] + g[k][j]);
      else if (w[k] == w[i] - 1) chkmax(h[i][j], f[i + 1][k - 1] + h[k][j]);
    }
    FOR(k, i, j - 1) chkmax(f[i][j], f[i][k] + f[k + 1][j]);
    FOR(k, i, j) if (g[i][k] >= -1e8 && h[k][j] >= -1e8) chkmax(f[i][j], g[i][k] + h[k][j] + v[w[k] - w[i] + w[k] - w[j] + 1]);
  }
  FOR(i, 1, n) {
    ans[i] = ans[i - 1];
    REP(j, i) chkmax(ans[i], ans[j] + f[j + 1][i]);
  }
  printf("%d", ans[n]);
}