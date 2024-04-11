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

const int maxn = 1123;
const int MOD = 2520;

int n, q, comp;
int f[maxn][MOD], k[maxn], last[maxn];
bool vis[maxn][MOD];
vector<int> G[maxn];

void go(int i, int j) {
  ++comp;
  int ans = 0;
  vector<pii> rec;
  while (true) {
    if (f[i][j]) {
      ans = f[i][j];
      break;
    }
    if (vis[i][j]) {
      int pre;
      for (pre = 0; pre < rec.size(); pre++) if (rec[pre] == mp(i, j)) break;
      FOR(ii, pre, int(rec.size()) - 1) {
        if (last[rec[ii]._1] != comp) ans++;
        last[rec[ii]._1] = comp;
      }
      break;
    }
    rec.eb(i, j);
    vis[i][j] = true;
    int nj = (j + k[i]) % MOD, ni = G[i][nj % G[i].size()];
    i = ni, j = nj;
  }
  for (auto now : rec) f[now._1][now._2] = ans;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", k + i);
    k[i] = (k[i] % MOD + MOD) % MOD;
  }
  FOR(i, 1, n) {
    int m;
    scanf("%d", &m);
    while (m--) {
      int u;
      scanf("%d", &u);
      G[i].eb(u);
    }
  }
  FOR(i, 1, n) REP(j, MOD) if (!f[i][j]) go(i, j);
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    y = (y % MOD + MOD) % MOD;
    printf("%d\n", f[x][y]);
  }
}