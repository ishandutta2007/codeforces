#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define reset(a, b) memset(a, b, sizeof(a))
#define _1 first
#define _2 second
#define eb emplace_back
typedef long long ll;
using namespace std;

const int maxn = 512;
const int maxk = 12;
const int maxa = 112345;

int have[maxa], need[maxa], dp[maxn * maxk][maxn];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n * k) {
    int c;
    scanf("%d", &c);
    have[c]++;
  }
  REP(i, n) {
    int f;
    scanf("%d", &f);
    need[f]++;
  }
  FOR(i, 1, k) scanf("%d", &dp[i][1]);
  FOR(i, k + 1, k * n) dp[i][1] = dp[i - 1][1];
  FOR(j, 2, n) FOR(i, 1, n * k) REP(now, min(k, i) + 1)
      dp[i][j] = max(dp[i][j], dp[i - now][j - 1] + dp[now][1]);
  int ans = 0;
  REP(i, maxa) ans += dp[have[i]][need[i]];
  printf("%d", ans);
}