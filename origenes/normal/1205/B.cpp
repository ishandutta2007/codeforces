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

const int maxn = 155;

int n, m, ans = 1e9;
ll a[112345];
int d[maxn][maxn], w[maxn][maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%lld", a + i);
    if (a[i]) a[++m] = a[i];
  }
  if (m > 130) {
    puts("3");
    return 0;
  }
  n = m;
  reset(d, 0x3f);
  reset(w, -1);
  FOR(i, 1, n) FOR(j, 1, n) if (i != j && (a[i] & a[j]))
    d[i][j] = w[i][j] = 1;
  FOR(k, 1, n) {
    FOR(i, 1, k - 1) FOR(j, i + 1, k - 1) if (w[i][k] != -1 && w[k][j] != -1)
      chkmin(ans, d[i][j] + w[i][k] + w[k][j]);
    FOR(i, 1, n) FOR(j, 1, n) chkmin(d[i][j], d[i][k] + d[k][j]);
  }
  if (ans > 5e8) puts("-1");
  else printf("%d", ans);
}