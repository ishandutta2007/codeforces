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

const int maxn = 2123;
const int inf = 2e9 + 15;

struct Circle {
  int c, r, id;

  bool operator<(const Circle &rhs) const {
    if (c + r != rhs.c + rhs.r) return c + r < rhs.c + rhs.r;
    return r < rhs.r;
  }
} lis[maxn];

int dp[maxn][maxn], l[maxn], r[maxn], to_l[maxn], to_r[maxn];
int n;
pair<pii, pii> pre[maxn][maxn];
bool vis[maxn][maxn];

void print(int i, int j) {
  if (vis[i][j]) printf("%d ", lis[i].id);
  if (pre[i][j]._1 != mp(-1, -1)) print(pre[i][j]._1._1, pre[i][j]._1._2);
  if (pre[i][j]._2 != mp(-1, -1)) print(pre[i][j]._2._1, pre[i][j]._2._2);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d%d", &lis[i].c, &lis[i].r);
    lis[i].id = i;
  }
  sort(lis + 1, lis + n + 1);
  set<pii> s;
  FOR(i, 1, n) {
    l[i] = lis[i].c - lis[i].r;
    r[i] = lis[i].c + lis[i].r;
    s.emplace(r[i], i);
  }
  reset(to_l, -1);
  reset(to_r, -1);
  FOR(i, 1, n) {
    auto it = s.lower_bound(mp(l[i], inf));
    if (it != s.begin()) {
      --it;
      to_l[i] = it->_2;
    }
  }
  s.clear();
  FOR(i, 1, n) s.emplace(l[i], i);
  FOR(i, 1, n) {
    s.erase(mp(l[i], i));
    auto it = s.lower_bound(mp(l[i], 0));
    if (it != s.end()) to_r[i] = it->_2;
    s.emplace(l[i], i);
  }
  reset(pre, -1);
  FOR(i, 1, n) dp[1][i] = vis[1][i] = (l[1] >= l[i]);
  FOR(i, 2, n) FOR(j, 1, n) {
      dp[i][j] = dp[i - 1][j];
      pre[i][j]._1 = {i - 1, j};
      if (l[i] < l[j]) continue;
      auto rec = mp(mp(-1, -1), mp(-1, -1));
      int now = 0;
      if (to_r[i] > -1) {
        now += dp[i - 1][to_r[i]];
        rec._1 = mp(i - 1, to_r[i]);
      }
      if (to_l[i] > -1) {
        now += dp[to_l[i]][j];
        rec._2 = mp(to_l[i], j);
      }
      now++;
      if (now > dp[i][j]) {
        dp[i][j] = now;
        pre[i][j] = rec;
        vis[i][j] = true;
      }
    }
  int ans = 0, r;
  FOR(i, 1, n) if (dp[n][i] > ans) {
      ans = dp[n][i];
      r = i;
    }
  printf("%d\n", ans);
  print(n, r);
}