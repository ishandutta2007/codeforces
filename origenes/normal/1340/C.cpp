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

const int maxm = 11234;
const int maxg = 1123;

int n, m, g, r;
int d[maxm], f[maxm][maxg];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) scanf("%d", d + i);
  scanf("%d%d", &g, &r);
  FOR(i, 1, m) REP(j, g) f[i][j] = 1e9;
  sort(d + 1, d + m + 1);
  f[1][0] = 0;
  queue<pii> q[2];
  q[0].emplace(1, 0);
  int ans = 1e9;
  while (!q[0].empty()) {
    auto [i, j] = q[0].front(); q[0].pop();
    if (n - d[i] <= g - j) {
      chkmin(ans, f[i][j] * (g + r) + j + n - d[i]);
      continue;
    }
    if (i != 1) {
      if (d[i] - d[i - 1] < g - j) {
        if (f[i - 1][j + d[i] - d[i - 1]] > f[i][j]) {
          f[i - 1][j + d[i] - d[i - 1]] = f[i][j];
          q[0].emplace(i - 1, j + d[i] - d[i - 1]);
        }
      } else if (d[i] - d[i - 1] == g - j && f[i - 1][0] > f[i][j] + 1) {
        f[i - 1][0] = f[i][j] + 1;
        q[1].emplace(i - 1, 0);
      }
    }
    if (i != m) {
      if (d[i + 1] - d[i] < g - j) {
        if (f[i + 1][j + d[i + 1] - d[i]] > f[i][j]) {
          f[i + 1][j + d[i + 1] - d[i]] = f[i][j];
          q[0].emplace(i + 1, j + d[i + 1] - d[i]);
        }
      } else if (d[i + 1] - d[i] == g - j && f[i + 1][0] > f[i][j] + 1) {
        f[i + 1][0] = f[i][j] + 1;
        q[1].emplace(i + 1, 0);
      }
    }
    if (q[0].empty()) {
      swap(q[0], q[1]);
      if (ans < 1e9) break;
    }
  }
  if (ans > 5e8) ans = -1;
  printf("%d", ans);
}