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

const int maxn = 212;
const int inf = 0x3f3f3f3f;

struct Edge {
  int hh, tt, nh, nt;

  Edge(int hh, int tt, int nh, int nt) : hh(hh), tt(tt), nh(nh), nt(nt) {}
};

int val[maxn][maxn], dp[maxn][maxn];
int h, t, n, m, r;
vector<Edge> vec;

int dfs(int hh, int tt) {
  if (hh + tt > r) return 0;
  if (val[hh][tt] == 1) return dp[hh][tt];
  if (val[hh][tt] == -1) return inf;
  int &ret = dp[hh][tt];
  val[hh][tt] = -1;
  for (const auto &it : vec) if (hh >= it.nh && tt >= it.nt)
      chkmax(ret, dfs(hh - it.nh + it.hh, tt - it.nt + it.tt) + 1);
  val[hh][tt] = 1;
  return ret;
}

int main() {
  scanf("%d%d%d", &h, &t, &r);
  scanf("%d", &n);
  FOR(i, 1, n) {
    int hh, tt;
    scanf("%d%d", &hh, &tt);
    vec.eb(hh, tt, i, 0);
  }
  scanf("%d", &m);
  FOR(i, 1, m) {
    int hh, tt;
    scanf("%d%d", &hh, &tt);
    vec.eb(hh, tt, 0, i);
  }
  queue<pii> q; q.emplace(0, 0);
  val[0][0] = 1, dp[0][0] = -1;
  while (!q.empty()) {
    auto now = q.front(); q.pop();
    int curh = now._1, curt = now._2;
    for (const auto &it : vec) if (curh >= it.hh && curt >= it.tt) {
        int nh = curh - it.hh + it.nh, nt = curt - it.tt + it.nt;
        if (nh + nt <= r && !val[nh][nt]) {
          val[nh][nt] = 1;
          dp[nh][nt] = dp[curh][curt] - 1;
          q.emplace(nh, nt);
        }
      }
  }
  int ans = dfs(h, t);
  if (ans < 0) printf("Ivan\n%d", -ans - 1);
  else if (ans >= inf) puts("Draw");
  else printf("Zmey\n%d", ans);
}