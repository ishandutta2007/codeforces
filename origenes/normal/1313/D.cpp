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

int n, m, k;
int f[2][1 << 8];
vector<pii> events;

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) {
    int l, r; scanf("%d%d", &l, &r);
    events.eb(l, i);
    events.eb(r + 1, -i);
  }
  sort(all(events));
  set<int> avail;
  avail.emplace(events[0]._2);
  map<int, int> tab[2];
  int now = 0;
  FOR(i, 1, 2 * n - 1) {
    int d = events[i]._1 - events[i - 1]._1;
    if (d && !avail.empty()) {
      now ^= 1;
      reset(f[now], 0xc0);
      tab[now].clear();
      int cnt = 0, ALL = 1 << avail.size();
      for (auto it : avail) tab[now][it] = cnt++;
      REP(mask, ALL) {
        int sub = 0, j = 0;
        for (auto[id, seq] : tab[now]) if (mask & (1 << j++)) if (tab[now ^ 1].count(id)) sub ^= 1 << tab[now ^ 1][id];
        chkmax(f[now][mask], f[now ^ 1][sub] + (__builtin_popcount(mask) & 1) * d);
      }
    }
    int id = events[i]._2;
    if (id < 0) {
      id = -id;
      avail.erase(id);
      now ^= 1;
      reset(f[now], 0xc0);
      tab[now].clear();
      int cnt = 0, ALL = 1 << avail.size();
      for (auto it : avail) tab[now][it] = cnt++;
      REP(mask, ALL) {
        int sub = 0, j = 0;
        for (auto [id, seq] : tab[now]) if (mask & (1 << j++)) if (tab[now ^ 1].count(id)) sub ^= 1 << tab[now ^ 1][id];
        f[now][mask] = max(f[now ^ 1][sub], f[now ^ 1][sub ^ (1 << tab[now ^ 1][id])]);
      }
    } else avail.emplace(id);
  }
  int ans = 0;
  REP(i, 1 << k) chkmax(ans, f[now][i]);
  printf("%d", ans);
}