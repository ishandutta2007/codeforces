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

const int maxn = 212345;

bool vis[maxn][10];
ll dp[maxn][10];
int n;

int main() {
  scanf("%d", &n);
  vis[0][0] = true;
  FOR(i, 1, n) {
    int k, c, d;
    priority_queue<int, vector<int>, greater<>> tab[4];
    scanf("%d", &k);
    while (k--) {
      scanf("%d%d", &c, &d);
      tab[c].emplace(d);
      if (c == 1) {
        if (tab[1].size() > 3) tab[1].pop();
      } else {
        if (tab[c].size() > 1) tab[c].pop();
      }
    }
    // sel 0
    REP(j, 10) if (vis[i - 1][j]) {
      dp[i][j] = dp[i - 1][j];
      vis[i][j] = true;
    }
    vector<int> lis[4];
    // sel 1
    int now = -1;
    FOR(j, 1, 3) while (!tab[j].empty()) {
      lis[j].eb(tab[j].top());
      chkmax(now, tab[j].top());
      tab[j].pop();
    }
    REP(j, 10) if (vis[i - 1][j]) {
      if (j != 9) {
        vis[i][j + 1] = true;
        chkmax(dp[i][j + 1], dp[i - 1][j] + now);
      } else {
        vis[i][0] = true;
        chkmax(dp[i][0], dp[i - 1][j] + 2 * now);
      }
    }
    // sel 2
    vector<int> tmp;
    for (auto it : lis[1]) tmp.eb(it);
    for (auto it : lis[2]) tmp.eb(it);
    sort(all(tmp), greater<>());
    if (tmp.size() >= 2) {
      REP(j, 8) if (vis[i - 1][j]) {
        vis[i][j + 2] = true;
        chkmax(dp[i][j + 2], dp[i - 1][j] + tmp[0] + tmp[1]);
      }
      FOR(j, 8, 9) if (vis[i - 1][j]) {
        vis[i][(j + 2) % 10] = true;
        chkmax(dp[i][(j + 2) % 10], dp[i - 1][j] + 2 * ll(tmp[0]) + tmp[1]);
      }
    }
    // sel 3
    tmp.clear();
    for (auto it : lis[1]) tmp.eb(it);
    sort(all(tmp), greater<>());
    if (tmp.size() == 3) {
      REP(j, 7) if (vis[i - 1][j]) {
        vis[i][j + 3] = true;
        chkmax(dp[i][j + 3], dp[i - 1][j] + ll(tmp[0]) + tmp[1] + tmp[2]);
      }
      FOR(j, 7, 9) if (vis[i - 1][j]) {
        vis[i][(j + 3) % 10] = true;
        chkmax(dp[i][(j + 3) % 10], dp[i - 1][j] + 2 * ll(tmp[0]) + tmp[1] + tmp[2]);
      }
    }
  }
  ll ans = 0;
  REP(j, 10) if (vis[n][j]) chkmax(ans, dp[n][j]);
  printf("%lld", ans);
}