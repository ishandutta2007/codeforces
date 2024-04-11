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
const int inf = 0x3f3f3f3f;

int n;
int a[maxn], b[maxn], c[maxn];
int fa[maxn * 3], fb[maxn * 3], fc[maxn * 3];
set<pii> s;
multiset<int> val;

void update(int x, int y) {
  auto it = s.upper_bound(mp(x, y));
  if (it->_2 >= y) return;
  int nx, ny = it->_2; it--;
  auto it2 = val.find(it->_1 + ny);
  val.erase(it2);
  while (it->_2 <= y) {
    tie(nx, ny) = *it;
    it--;
    val.erase(it->_1 + ny);
    it++;
    s.erase(it);
    it = s.lower_bound(mp(x, y));
    it--;
  }
  tie(nx, ny) = *it;
  val.emplace(nx + y);
  it++;
  val.emplace(x + it->_2);
  s.emplace(x, y);
}

int main() {
  scanf("%d", &n);
  vector<int> tmp; tmp.reserve(3 * n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    tmp.eb(a[i]);
  }
  FOR(i, 1, n) {
    scanf("%d", b + i);
    tmp.eb(b[i]);
  }
  FOR(i, 1, n) {
    scanf("%d", c + i);
    tmp.eb(c[i]);
  }
  sort(all(tmp)); uni(tmp);
  map<int, int> mmap;
  REP(i, int(tmp.size())) mmap[tmp[i]] = i + 1;
  FOR(i, 1, n) a[i] = mmap[a[i]];
  FOR(i, 1, n) b[i] = mmap[b[i]];
  FOR(i, 1, n) c[i] = mmap[c[i]];
  reset(fa, 0x3f); reset(fb, 0x3f), reset(fc, 0x3f);
  FOR(i, 1, n) chkmin(fa[a[i]], i);
  FOR(i, 1, n) chkmin(fb[b[i]], i);
  FOR(i, 1, n) chkmin(fc[c[i]], i);
  s.emplace(0, inf + 1);
  s.emplace(inf + 1, 0);
  val.emplace(0);
  FOR(i, 1, int(tmp.size())) if (fa[i] == inf) update(fb[i], fc[i]);
  int ans = inf;
  bool stop = false;
  ROF(i, n, 1) {
    chkmin(ans, i + *val.begin());
    if (fa[a[i]] == i) {
      if (fb[a[i]] == inf && fc[a[i]] == inf) {
        stop = true;
        break;
      }
      update(fb[a[i]], fc[a[i]]);
    }
  }
  if (!stop) chkmin(ans, *val.begin());
  printf("%d", ans);
}