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

const int maxn = 312345;

int n;
ll a[maxn], b[maxn], c[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld%lld", a + i, b + i);
  b[0] = b[n];
  ll s = 0;
  FOR(i, 1, n) {
    c[i] = max(a[i] - b[i - 1], 0LL);
    s += c[i];
  }
  ll ans = 1e18;
  FOR(i, 1, n) chkmin(ans, s - c[i] + a[i]);
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}