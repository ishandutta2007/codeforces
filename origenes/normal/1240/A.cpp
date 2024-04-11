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

const int maxn = 212345;

int q, n;
ll p[maxn];
ll x, a, y, b, c, k;

bool check(int up) {
  int j = up / c;
  ll ans = 0;
  FOR(i, 1, j) ans += p[i] / 100 * (x + y);
  j += up / a - up / c;
  FOR(i, up / c + 1, j) ans += p[i] / 100 * x;
  j += up / b - up / c;
  FOR(i, up / a + 1, j) ans += p[i] / 100 * y;
  return ans >= k;
}

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", p + i);
  sort(p + 1, p + n + 1, greater<>());
  scanf("%lld%lld%lld%lld", &x, &a, &y, &b);
  scanf("%lld", &k);
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }
  c = a / __gcd(a, b) * b;
  if (!check(n)) {
    puts("-1");
    return;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d\n", lo);
}

int main() {
  scanf("%d", &q);
  while (q--) solve();
}