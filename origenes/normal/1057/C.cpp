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
const int maxk = 2123;
const int inf = 0x3f3f3f3f;

int dp[maxn][maxk], r[maxn];
int n, s, k, ans = inf;
char c[maxn];
vector<int> G[maxn];

int main() {
  scanf("%d%d%d", &n, &s, &k);
  FOR(i, 1, n) scanf("%d", r + i);
  scanf("%s", c + 1);
  FOR(i, 1, n) FOR(j, i + 1, n) if (c[i] != c[j]) {
    if (r[i] > r[j]) G[j].eb(i);
    else if (r[i] < r[j]) G[i].eb(j);
  }
  reset(dp, 0x3f);
  set<pair<int, pii>> q;
  FOR(i, 1, n) {
    if (r[i] >= k) chkmin(ans, abs(s - i));
    else {
      dp[i][k - r[i]] = abs(s - i);
      q.emplace(dp[i][k - r[i]], mp(i, k - r[i]));
    }
  }
  while (!q.empty()) {
    auto now = *q.begin(); q.erase(q.begin());
    int val = now._1, pos = now._2._1, need = now._2._2;
    if (dp[pos][need] < val) continue;
    for (int nxt : G[pos]) {
      int dis = abs(pos - nxt);
      if (r[nxt] >= need) {
        chkmin(ans, dis + val);
        continue;
      }
      if (dp[nxt][need - r[nxt]] > val + dis) {
        dp[nxt][need - r[nxt]] = val + dis;
        q.emplace(dp[nxt][need - r[nxt]], mp(nxt, need - r[nxt]));
      }
    }
  }
  if (ans == inf) puts("-1");
  else printf("%d", ans);
}