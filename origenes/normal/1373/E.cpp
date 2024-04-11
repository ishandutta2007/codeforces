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

ll f(int x) {
  stack<ll> s;
  for (int i = 0; x; i++) {
    s.emplace(min(x, i ? 9 : 8));
    x -= s.top();
  }
  ll ret = 0;
  while (!s.empty()) {
    ret = ret * 10 + s.top();
    s.pop();
  }
  return ret;
}

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  ll b = 1, ans = 1e18;
  REP(x, 17) {
    b *= 10;
    REP(i, 10) {
      int d = min(10 - i, k + 1), m = n - (k + 1 - d) - 9 * x * d;
      REP(j, k + 1) m -= (i + j) % 10;
      if (m >= 0 && m % (k + 1) == 0) {
        ll e = f(m / (k + 1));
        chkmin(ans, (e + 1) * b - 10 + i);
      }
    }
  }
  if (ans == 1e18) ans = -1;
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}