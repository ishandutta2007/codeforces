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

const int maxn = 112345;

bitset<100000> mask[1 << 9];
int n, m;
int cnt[1 << 9];
vector<int> G[1 << 9];
int cost[maxn];

inline int lowbit(int x) {
  return x & -x;
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) {
    int f, now = 0;
    scanf("%d", &f);
    while (f--) {
      int b;
      scanf("%d", &b);
      b--;
      now |= (1 << b);
    }
    mask[now].set(i);
  }
  REP(s, 1 << 9)
    for (int sub = s; sub; sub = (sub - 1) & s)
      mask[s] |= mask[sub];
  REP(i, 1 << 9) cnt[i] = mask[i].count();
  FOR(i, 1, m) {
    scanf("%d", cost + i);
    int now = 0, r;
    scanf("%d", &r);
    while (r--) {
      int b;
      scanf("%d", &b);
      b--;
      now |= (1 << b);
    }
    G[now].eb(i);
  }
  REP(i, 1 << 9) sort(all(G[i]), [](int x, int y) { return cost[x] < cost[y]; });
  pii best = {-1, 0};
  pii ans;
  REP(i, 1 << 9) {
    if (G[i].empty()) continue;
    REP(j, i) {
      if (G[j].empty()) continue;
      int pleased = cnt[i | j], spent = cost[G[i][0]] + cost[G[j][0]];
      if (best < mp(pleased, -spent)) {
        best = mp(pleased, -spent);
        ans = {G[i][0], G[j][0]};
      }
    }
    if (G[i].size() >= 2) {
      int pleased = cnt[i], spent = cost[G[i][0]] + cost[G[i][1]];
      if (best < mp(pleased, -spent)) {
        best = mp(pleased, -spent);
        ans = {G[i][0], G[i][1]};
      }
    }
  }
  assert(ans._1 != ans._2);
  printf("%d %d", ans._1, ans._2);
}