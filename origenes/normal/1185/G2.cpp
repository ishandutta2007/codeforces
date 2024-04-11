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
const int maxt = 2512;
const int MOD = 1e9 + 7;

int T;

void upd(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

vector<vector<vector<int>>> dp;

void go(vector<vector<pii>> &ret, const vector<int> &t, int n) {
  dp.clear();
  dp.resize(n + 1);
  for (auto &it1 : dp) {
    it1.resize(n + 1);
    for (auto &it2 : it1) it2.resize(T + 1);
  }
  dp[0][0][0] = 1;
  REP(i, n) REP(j, i + 1) REP(k, T + 1) if (dp[i][j][k]) {
    upd(dp[i + 1][j][k], dp[i][j][k]);
    if (k + t[i + 1] <= T) upd(dp[i + 1][j + 1][k + t[i + 1]], dp[i][j][k]);
  }
  REP(j, n + 1) REP(k, T + 1) if (dp[n][j][k]) ret[j].eb(k, dp[n][j][k]);
}

int n, cnt[3], memo[maxn][maxn][maxn][4];
vector<int> t[3];
vector<vector<pii>> way[3];

int dfs(int x, int y, int z, int last) {
  if (x + y + z == 0) return 1;
  int &ret = memo[x][y][z][last];
  if (ret != -1) return ret;
  ret = 0;
  if (x && last != 0) upd(ret, mul(x, dfs(x - 1, y, z, 0)));
  if (y && last != 1) upd(ret, mul(y, dfs(x, y - 1, z, 1)));
  if (z && last != 2) upd(ret, mul(z, dfs(x, y, z - 1, 2)));
  return ret;
}

int main() {
  scanf("%d%d", &n, &T);
  REP(i, 3) t[i] = {0};
  FOR(i, 1, n) {
    int w, g;
    scanf("%d%d", &w, &g);
    t[g - 1].eb(w);
    cnt[g - 1]++;
  }
  REP(i, 3) {
    way[i].resize(cnt[i] + 1);
    go(way[i], t[i], cnt[i]);
  }
  int ans = 0;
  reset(memo, -1);
  REP(x, cnt[0] + 1) REP(y, cnt[1] + 1) REP(z, cnt[2] + 1) if (dfs(x, y, z, 3)) {
    for (auto i : way[0][x]) for (auto j : way[1][y]) {
      if (i._1 + j._1 > T) break;
      int now = mul(mul(mul(i._2, j._2), dfs(x, y, z, 3)), dp[cnt[2]][z][T - i._1 - j._1]);
      upd(ans, now);
    }
  }
  printf("%d", ans);
}