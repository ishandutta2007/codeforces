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

const int upp = 5e4;
const int inf = 0x3f3f3f3f;

inline ll mul(ll a, ll b, ll mod) {
  return a * b % mod;
}

int a, b, p, q;
pii x[upp];

void get(int lim, int r, int i, pii &ret) {
  int j = lower_bound(x, x + upp, mp(lim, -inf)) - x;
  if (j < upp) chkmin(ret, mp(abs(2 * ((x[j]._1 + r) % q) - q), x[j]._2 + i * upp));
  if (j) chkmin(ret, mp(abs(2 * ((x[j - 1]._1 + r) % q) - q), x[j - 1]._2 + i * upp));
}

pii solve() {
  pii ret = {inf, inf};
  REP(i, b % upp) chkmin(ret, mp(int(abs(2 * mul(a + i, p, q) - q)), a + i));
  a += b % upp, b -= b % upp;
  REP(i, upp) x[i] = {mul(a + i, p, q), a + i};
  sort(x, x + upp);
  int r = 0;
  REP(i, b / upp) {
    chkmin(ret, mp(abs(2 * (x[0]._1 + r) - q), x[0]._1 + i * upp));
    get((q + 1) / 2 - r, r, i, ret);
    get(q - r, r, i, ret);
    get(q + (q + 1) / 2 - r, r, i, ret);
    r = (r + mul(p, upp, q)) % q;
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> p >> q;
    ll g = __gcd(p, q);
    p /= g, q /= g;
    p %= q;
    b -= a - 1;
    pii ans = {inf, inf};
    if (b <= upp || q < upp) REP(i, min(b, q)) chkmin(ans, mp(int(abs(2 * mul(a + i, p, q) - q)), a + i));
    else ans = solve();
    cout << ans._2 << '\n';
  }
}