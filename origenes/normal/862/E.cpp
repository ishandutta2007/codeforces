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

int b[maxn], m, n, q;
ll a;
vector<ll> s;

int main() {
  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) {
    int now;
    scanf("%d", &now);
    a += i & 1 ? -now : now;
  }
  ll tot = 0;
  REP(i, m) scanf("%d", b + i);
  REP(i, n) tot += i & 1 ? -b[i] : b[i];
  s.eb(tot);
  REP(i, m - n) {
    tot = s.back() - b[i];
    tot = -tot;
    tot += n & 1 ? b[n + i] : -b[n + i];
    s.eb(tot);
  }
  sort(all(s));
  auto it = lower_bound(all(s), a);
  ll ans = 1e18;
  if (it != s.end()) chkmin(ans, abs(a - *it));
  if (it != s.begin()) chkmin(ans, abs(a - *(it - 1)));
  printf("%lld\n", ans);
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    if ((r - l + 1) & 1) a += l & 1 ? x : -x;
    it = lower_bound(all(s), a);
    ans = 1e18;
    if (it != s.end()) chkmin(ans, abs(a - *it));
    if (it != s.begin()) chkmin(ans, abs(a - *(it - 1)));
    printf("%lld\n", ans);
  }
}