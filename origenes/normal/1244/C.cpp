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

ll exgcd(ll a, ll b, ll &x, ll &y) {
  int g = a; x = 1, y = 0;
  if (b) g = exgcd(b, a % b, y, x), y -= a / b * x;
  return g;
}

ll inv(ll a, ll m) {
  ll x, y;
  exgcd(a, m, x, y);
  return (x + m) % m;
}

int main() {
  ll n, p, d, w;
  cin >> n >> p >> w >> d;
  if (p == 0) {
    cout << "0 0 " << n;
    return 0;
  }
  ll g = __gcd(d, w);
  if (p % g) {
    cout << -1;
    return 0;
  }
  p /= g, d /= g, w /= g;
  ll y = p % w * inv(d, w) % w;
  ll x = (p - y * d) / w;
  if (x + y > n || x < 0) {
    cout << -1;
    return 0;
  }
  cout << x << ' ' << y << ' ' << n - x - y;
}