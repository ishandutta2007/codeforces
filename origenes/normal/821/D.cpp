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

const int maxn = 11234;

int dis[maxn * 3], n, m, k;
pii pos[maxn];
map<pii, int> lis;
vector<pii> G[maxn * 3];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  int s, t[2] = {};
  reset(dis, 0x3f);
  FOR(i, 1, k) {
    scanf("%d%d", &pos[i]._1, &pos[i]._2);
    lis[pos[i]] = i;
    if (pos[i] == mp(1, 1)) s = i;
  }
  FOR(i, 1, k) {
    int x = pos[i]._1, y = pos[i]._2;
    if (lis.count(mp(x - 1, y))) G[i].eb(lis[mp(x - 1, y)], 0);
    if (lis.count(mp(x + 1, y))) G[i].eb(lis[mp(x + 1, y)], 0);
    if (lis.count(mp(x, y - 1))) G[i].eb(lis[mp(x, y - 1)], 0);
    if (lis.count(mp(x, y + 1))) G[i].eb(lis[mp(x, y + 1)], 0);
    G[i].eb(x + k, 1);
    G[x + k].eb(i, 0);
    G[i].eb(y + k + n, 1);
    G[y + k + n].eb(i, 0);
    if (x > 1) {
      G[i].eb(x + k - 1, 1);
      G[x + k - 1].eb(i, 0);
    }
    if (x < n) {
      G[i].eb(x + k + 1, 1);
      G[x + k + 1].eb(i, 0);
    }
    if (y > 1) {
      G[i].eb(y + k + n - 1, 1);
      G[y + k + n - 1].eb(i, 0);
    }
    if (y < m) {
      G[i].eb(y + k + n + 1, 1);
      G[y + k + n + 1].eb(i, 0);
    }
  }
  if (lis.count(mp(n, m))) t[0] = lis[mp(n, m)];
  else t[0] = k + n, t[1] = k + n + m;
  set<pii> st;
  st.insert(mp(0, s));
  int ans = -1;
  while (!st.empty()) {
    auto now = *st.begin(); st.erase(st.begin());
    int d = now._1, u = now._2;
    if (d >= dis[u]) continue;
    dis[u] = d;
    if (u == t[0] || u == t[1]) {
      ans = chkmax(ans, d);
      break;
    }
    for (auto vv : G[u]) st.insert(mp(d + vv._2, vv._1));
  }
  printf("%d", ans);
}