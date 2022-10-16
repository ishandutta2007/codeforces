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

const int maxn = 112345;

int n, q;

int main() {
  scanf("%d", &n);
  set<ll> tmp;
  FOR(i, 1, n) {
    ll now;
    scanf("%lld", &now);
    tmp.emplace(now);
  }
  int base = tmp.size();
  vector<ll> diff;
  ll last = -1;
  for (auto it : tmp) {
    if (last == -1) {
      last = it;
      continue;
    }
    diff.eb(it - last - 1);
    last = it;
  }
  diff.eb(3e18);
  sort(all(diff));
  vector<ll> s = diff;
  FOR(i, 1, int(s.size()) - 1) s[i] = s[i - 1] + s[i];
  scanf("%d", &q);
  while (q--) {
    ll lo, hi;
    scanf("%lld%lld", &lo, &hi);
    ll now = hi - lo;
    auto it = lower_bound(all(diff), now);
    int idx = it - diff.begin();
    idx--;
    ll ans = base;
    if (idx >= 0) ans += s[idx];
    printf("%lld ", ans + ll(s.size() - idx - 1) * now);
  }
}