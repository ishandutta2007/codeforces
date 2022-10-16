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

void solve() {
  ll a, m;
  scanf("%lld%lld", &a, &m);
  ll d = __gcd(a, m);
  a /= d, m /= d;
  ll ans = m;
  vector<ll> fac;
  for (ll i = 2; i <= 1e5; i++) {
    if (m % i == 0) {
      fac.eb(i);
      while (m % i == 0) m /= i;
    }
  }
  if (m > 1) fac.eb(m);
  for (auto p : fac) ans = ans / p * (p - 1);
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}