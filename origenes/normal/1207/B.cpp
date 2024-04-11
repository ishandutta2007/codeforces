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

int n, m;
int a[maxn][maxn], b[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  vector<pii> ans;
  bool good = true;
  FOR(i, 1, n) FOR(j, 1, m) if (!b[i][j] && a[i][j]) {
    bool done = false;
    if (i > 1) {
      if (j > 1 && a[i - 1][j - 1] && a[i - 1][j] && a[i][j - 1]) {
        ans.eb(i - 1, j - 1);
        done = true;
        b[i][j] = 1;
        goto en;
      }
      if (j < m && a[i - 1][j] && a[i - 1][j + 1] && a[i][j + 1]) {
        ans.eb(i - 1, j);
        done = true;
        b[i][j] = b[i][j + 1] = 1;
        goto en;
      }
    }
    if (i < n) {
      if (j > 1 && a[i][j - 1] && a[i + 1][j - 1] && a[i + 1][j]) {
        ans.eb(i, j - 1);
        done = true;
        b[i][j] = b[i + 1][j - 1] = b[i + 1][j] = 1;
        goto en;
      }
      if (j < m && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
        ans.eb(i, j);
        done = true;
        b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
      }
    }
    en: if (!done) {
      good = false;
      break;
    }
  }
  if (!good) puts("-1");
  else {
    printf("%d\n", int(ans.size()));
    for (auto it : ans) printf("%d %d\n", it._1, it._2);
  }
}