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

ll cnt1, cnt2, x, y;

bool check(ll v) {
  ll s1 = v / x, s2 = v / y, s12 = v / (x * y);
  ll rem = v - s1 - s2 + s12;
  ll only2 = s1 - s12, only1 = s2 - s12;
  ll extra1 = max(cnt1 - only1, 0LL), extra2 = max(cnt2 - only2, 0LL);
  return extra1 + extra2 <= rem;
}

int main() {
  scanf("%lld%lld%lld%lld", &cnt1, &cnt2, &x, &y);
  ll lo = 1, hi = 1e18;
  while (lo < hi) {
    ll mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%lld", lo);
}