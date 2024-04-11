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

void clr(set<ll> &s, ll g, ll b) {
  vector<ll> v;
  for (auto it : s) if (it <= g || it > b) v.eb(it);
  for (auto it : v) s.erase(it);
}

ll gcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll ret = gcd(b, a % b, y, x);
  y -= x * (a / b);
  return ret;
}

ll inv(ll a, ll n) {
  ll x, y;
  return gcd(a, n, x, y) == 1 ? (x + n) % n : -1;
}

int main() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  ll g = __gcd(a, b), ans = 0;
  int upp = sqrt(a) + 0.5;
  set<ll> fac;
  FOR(i, 1, upp) if (a % i == 0) {
      fac.insert(i);
      fac.insert(a / i);
    }
  clr(fac, g, b);
  while (true) {
    ll rec = -1, gg;
    for (auto it : fac) {
      ll d = __gcd(b % it, g);
      ll k = b % it / d * inv(g / d, it) % it;
      double kk = double(b % it / d) * (inv(g / d, it) % it);
      if (kk < -1e-8 || kk > (b / g + 1e-8) || k < 0 || k >= b / g) continue;
      if (b - k * g >= rec) {
        rec = b - k * g;
        gg = it;
      }
    }
    if (rec == -1) {
      ans += b / g;
      break;
    }
    ans += (b - rec) / g;
    b = rec;
    g = gg;
    clr(fac, g, b);
  }
  printf("%lld", ans);
}