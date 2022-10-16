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
  ll n, k;
  ll l1, r1, l2, r2;
  scanf("%lld%lld", &n, &k);
  scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
  if (l1 > l2) {
    swap(l1, l2);
    swap(r1, r2);
  }
  ll s1 = 0, s2 = 0;
  if (l2 > r1) s1 = l2 - r1;
  ll ins = 0;
  if (l2 <= r1) ins = min(r1, r2) - l2;
  s2 = r1 - l1 + r2 - l2 - ins * 2;
  if (ins * n >= k) {
    puts("0");
    return;
  }
  if (s1 && k <= s1) {
    printf("%lld\n", s1 + k);
    return;
  }
  ll ans = 1e18;
  FOR(i, 1, n) {
    ll cnt = i * s1 * 2, now = ins * n + i * s1;
    if (now >= k) {
      chkmin(ans, cnt);
      break;
    }
    if (now + i * s2 >= k) {
      cnt += k - now;
      chkmin(ans, cnt);
      continue;
    }
    now += i * s2;
    cnt += i * s2;
    cnt += (k - now) * 2;
    chkmin(ans, cnt);
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}