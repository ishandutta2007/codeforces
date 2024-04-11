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

const int maxn = 212345;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[maxn], b[maxn], rec[maxn];
int n, k;
vector<int> G[maxn];

bool check(ll now) {
  REP(i, k) G[i].clear();
  FOR(i, 1, n) {
    ll to = a[i] / b[i];
    if (to < k) G[to].eb(i);
  }
  reset(rec, 0);
  int j = 0;
  REP(i, k - 1) {
    while (j < k && G[j].empty()) j++;
    if (j < k) {
      int idx = G[j].back();
      G[j].pop_back();
      rec[idx] = min(inf, rec[idx] + now);
      ll to = (a[idx] + rec[idx]) / b[idx];
      if (to < k) G[to].eb(idx);
    }
    if (!G[i].empty()) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n) scanf("%lld", b + i);
  ll lo = 0, hi = 2e12 + 123;
  while (lo < hi) {
    ll mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  if (lo > 2e12 + 100) puts("-1");
  else printf("%lld", lo);
}