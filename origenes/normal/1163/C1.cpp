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

const int maxn = 1123;

int n;
pii p[maxn];
ll ans, tot;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", &p[i]._1, &p[i]._2);
  map<pii, int> mmap, tmp;
  FOR(i, 1, n) {
    tmp.clear();
    FOR(j, i + 1, n) {
      auto gr = mp(p[j]._1 - p[i]._1, p[j]._2 - p[i]._2);
      if (gr._1 < 0) gr._1 = -gr._1, gr._2 = -gr._2;
      int d = __gcd(gr._1, gr._2);
      gr._1 /= d, gr._2 /= d;
      tmp[gr]++;
    }
    for (auto it : tmp) if (it._2 == 1) mmap[it._1]++, tot++;
  }
  ans = tot * (tot - 1) / 2;
  for (auto it : mmap) ans -= it._2 * (it._2 - 1) / 2;
  printf("%lld", ans);
}