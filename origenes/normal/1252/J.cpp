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

const int upp = 1e6;

ll f[1 << 15];

int main() {
  ll x;
  cin >> x;
  if (x == 1) {
    cout << 1 << ' ' << 1;
    return 0;
  }
  vector<ll> facs;
  ll best = x + 1, X = x;
  FOR(i, 2, upp) if (x % i == 0) {
    facs.eb(1);
    while (x % i == 0) facs.back() *= i, x /= i;
  }
  if (x > 1) facs.eb(x);
  REP(mask, 1 << facs.size()) {
    f[mask] = 1;
    REP(i, int(facs.size())) if (mask & (1 << i)) f[mask] *= facs[i];
  }
  ll a, b;
  int ALL = (1 << facs.size()) - 1;
  REP(mask, 1 << facs.size()) {
    if (f[mask] < best && f[ALL ^ mask] < best) {
      best = max(f[mask], f[ALL ^ mask]);
      a = 1, b = 1;
      REP(i, int(facs.size())) if (mask & (1 << i)) a *= facs[i];
      b = X / a;
    }
  }
  cout << a << ' ' << b;
}