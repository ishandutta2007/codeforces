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

const int maxn = 112;

int a[maxn], b[maxn], tab[maxn][maxn], ans[maxn][maxn];
int n, m, h;

int main() {
  scanf("%d%d%d", &n, &m, &h);
  FOR(i, 1, m) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &tab[i][j]);
  FOR(i, 1, n) {
    FOR(j, 1, m) {
      if (!tab[i][j]) {
        ans[i][j] = 0;
        continue;
      }
      if (a[j] <= b[i]) ans[i][j] = a[j];
      else ans[i][j] = b[i];
    }
  }
  FOR(i, 1, n) {
    FOR(j, 1, m) printf("%d ", ans[i][j]);
    puts("");
  }
}