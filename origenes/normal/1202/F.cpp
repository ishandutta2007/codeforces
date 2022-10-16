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

ll a, b, ans;

int main() {
  scanf("%lld%lld", &a, &b);
  for (ll i = 1; i <= a + b; ) {
    ll n = (a + b) / i, hi = (a + b) / n;
    if (n > a || n > b) {
      i = (a + b) / n + 1;
      continue;
    }
    ll l = ceil(double(a) / (n + 1)), r = a / n;
    ll L = ceil(double(b) / (n + 1)), R = b / n;
    if (l <= r && L <= R) ans += max(0LL, min(hi, r + R) - max(i, l + L) + 1);
    i = hi + 1;
  }
  printf("%lld", ans);
}