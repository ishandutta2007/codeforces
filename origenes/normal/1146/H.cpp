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

const int maxn = 312;

pair<double, pii> e[maxn * maxn];
int x[maxn], y[maxn], dp[maxn][maxn][5];
int n, m;
ll ans;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  FOR(i, 1, n) FOR(j, 1, n) if (i != j) e[++m] = {atan2(y[j] - y[i], x[j] - x[i]), mp(i, j)};
  sort(e + 1, e + m + 1);
  FOR(i, 1, m) {
    int u = e[i]._2._1, v = e[i]._2._2;
    dp[u][v][0] = 1;
    FOR(j, 1, n) REP(k, 4) dp[j][v][k + 1] += dp[j][u][k];
  }
  FOR(i, 1, n) ans += dp[i][i][4];
  printf("%lld", ans);
}