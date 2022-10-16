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

const int maxn = 15;
const int maxt = 235;
const int MOD = 1e9 + 7;

inline void upd(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int n, T;
int dp[maxt][1 << maxn][3], t[maxn], g[maxn];

int main() {
  scanf("%d%d", &n, &T);
  REP(i, n) {
    scanf("%d%d", t + i, g + i);
    g[i]--;
  }
  REP(i, n) dp[t[i]][1 << i][g[i]] = 1;
  FOR(i, 1, T - 1) REP(mask, 1 << n) REP(k, n) if ((mask & (1 << k)) == 0 && t[k] + i <= T)
    REP(j, 3) if (j != g[k]) upd(dp[i + t[k]][mask | (1 << k)][g[k]], dp[i][mask][j]);
  int ans = 0;
  REP(mask, 1 << n) REP(i, 3) upd(ans, dp[T][mask][i]);
  printf("%d", ans);
}