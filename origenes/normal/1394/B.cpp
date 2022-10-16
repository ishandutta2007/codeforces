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

const int maxn = 212345;

int n, m, k;
bool ban[10][10][10][10];
vector<pii> G[maxn];
map<pii, int> pre[maxn];
int nxt[maxn][10];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].eb(v, w);
  }
  FOR(i, 1, n) sort(all(G[i]), [&](pii a, pii b) { return a._2 < b._2; });
  FOR(i, 1, n) FOR(j, 1, int(G[i].size())) {
    nxt[i][j] = G[i][j - 1]._1;
    pre[G[i][j - 1]._1][mp(G[i].size(), j)]++;
  }
  FOR(i, 1, n) {
    if (pre[i].empty()) {
      puts("0");
      return 0;
    }
    for (auto [_, cnt] : pre[i]) {
      auto [x, y] = _;
      if (cnt > 1) ban[x][y][x][y] = true;
    }
    for (auto it1 = pre[i].begin(); it1 != pre[i].end(); ++it1) {
      auto it2 = it1; it2++;
      auto [x1, y1] = it1->_1;
      for (; it2 != pre[i].end(); ++it2) {
        auto [x2, y2] = it2->_1;
        ban[x1][y1][x2][y2] = ban[x2][y2][x1][y1] = true;
      }
    }
  }
  vector<int> perm(k + 1, 1);
  int ans = 0;
  do {
    bool f = true;
    FOR(i, 1, k) FOR(j, i, k) if (ban[i][perm[i]][j][perm[j]]) {
      f = false;
      goto en;
    }
    en: ans += f;
    perm[k]++;
    ROF(i, k, 2) if (perm[i] > i) {
      perm[i] = 1;
      perm[i - 1]++;
    }
  } while (perm[1] == 1);
  printf("%d", ans);
}