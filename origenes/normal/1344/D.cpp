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

int n, a[maxn], b[maxn];
ll k;

ll check(ll x) {
  ll ret = 0;
  FOR(i, 1, n) {
    long double d = 9 - 12 * ((long double)x - a[i] + 1);
    if (d < 0) continue;
    ret += min(ll(sqrt(d) / 6 + 0.5), ll(a[i]));
  }
  return ret;
}

int main() {
  scanf("%d%lld", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  ll lo = -4e18, hi = 2e9;
  while (lo < hi) {
    ll mi = (lo + hi + 1) / 2;
    if (check(mi) >= k) lo = mi;
    else hi = mi - 1;
  }
  vector<pair<ll, int>> q;
  FOR(i, 1, n) {
    long double d = 9 - 12 * ((long double)lo - a[i] + 1);
    if (d < 0) continue;
    b[i] = min(ll(sqrt(d) / 6 + 0.5), ll(a[i]));
    k -= b[i];
    q.eb(-3 * sqr(ll(b[i])) + 3LL * b[i] + a[i] - 1, i);
  }
  sort(all(q), greater<>());
  while (k++) {
    b[q.back()._2]--;
    q.pop_back();
  }
  FOR(i, 1, n) printf("%d ", b[i]);
}