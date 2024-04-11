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

int n, k;
ll a[maxn];

ll f(ll x, int y) {
  ll mx = (x + y - 1) / y, mn = x / y;
  ll cx = x % y, cn = y - x % y;
  return cx * sqr(mx) + cn * sqr(mn);
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%lld", a + i);
  priority_queue<tuple<ll, int, int>> q;
  int cut = k - n;
  ll ans = 0;
  FOR(i, 1, n) {
    ans += sqr(a[i]);
    q.emplace(f(a[i], 1) - f(a[i], 2), i, 1);
  }
  while (cut--) {
    auto [d, i, c] = q.top(); q.pop();
    ans -= d;
    q.emplace(f(a[i], c + 1) - f(a[i], c + 2), i, c + 1);
  }
  printf("%lld", ans);
}