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

const int maxn = 51234;

int n, m;
map<int, vector<pii>> fx, fy;

bool check(int need) {
  map<int, vector<pii>> query;
  map<int, vector<pii>> events;
  for (auto [x, vi] : fx) for (auto [l, r] : vi) if (l + need <= r - need) query[x].eb(l + need, r - need);
  for (auto [y, vi] : fy) for (auto [l, r] : vi) if (l + need <= r - need) {
    events[l + need].eb(y, 1);
    events[r - need + 1].eb(y, -1);
  }
  map<int, int> cnt;
  auto it = events.begin();
  for (auto [x, vi] : query) {
    while (it != events.end() && it->_1 <= x) {
      for (auto [y, sig] : it->_2) {
        cnt[y] += sig;
        if (!cnt[y]) cnt.erase(y);
      }
      it++;
    }
    for (auto [l, r] : vi) {
      auto lb = cnt.lower_bound(l), rb = cnt.lower_bound(r + 1);
      if (lb != rb) return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    int x, y, l; scanf("%d%d%d", &x, &y, &l);
    fx[x].eb(y, y + l);
  }
  FOR(i, 1, m) {
    int x, y, l; scanf("%d%d%d", &x, &y, &l);
    fy[y].eb(x, x + l);
  }
  int lo = 0, hi = 1e8;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d", lo);
}