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

const int maxn = 2123;

bitset<maxn> b[maxn], pre[maxn];
set<pii> s, good;
int cnt[maxn], n, m, q;

int main() {
  scanf("%d%d%d", &n, &m, &q);
  FOR(i, 1, n) s.emplace(0, i);
  REP(i, m + 1) FOR(j, 1, i) pre[i].set(j);
  while (q--) {
    int a, l, r;
    scanf("%d%d%d", &a, &l, &r);
    b[a] ^= pre[r] ^ pre[l - 1];
    auto it = s.find(mp(cnt[a], a));
    if (it != s.begin()) {
      auto it2 = it, it3 = it;
      it2--, it3++;
      good.erase(mp(it2->_2, a));
      if (it3 != s.end() && (b[it2->_2] ^ b[it3->_2]).count() != it3->_1 - it2->_1) good.emplace(it2->_2, it3->_2);
    }
    auto it2 = it; it2++;
    if (it2 != s.end()) good.erase(mp(a, it2->_2));
    s.erase(it);
    cnt[a] = b[a].count();
    s.emplace(cnt[a], a);
    it = s.find(mp(cnt[a], a));
    if (it != s.begin()) {
      it2 = it; it2--;
      auto it3 = it; it3++;
      if (it3 != s.end()) good.erase(mp(it2->_2, it3->_2));
      if ((b[it2->_2] ^ b[a]).count() != cnt[a] - it2->_1) good.emplace(it2->_2, a);
    }
    it2 = it; it2++;
    if (it2 != s.end()) if ((b[a] ^ b[it2->_2]).count() != it2->_1 - cnt[a]) good.emplace(a, it2->_2);
    if (good.empty()) puts("-1");
    else {
      auto _ = *good.begin();
      auto x1 = _._1, x2 = _._2;
      int y1 = (b[x1] & (~b[x2]))._Find_first(), y2 = (b[x2] & (~b[x1]))._Find_first();
      if (x1 > x2) swap(x1, x2); if (y1 > y2) swap(y1, y2);
      printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
  }
}