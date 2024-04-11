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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  set<ll> s = {k};
  ll i = 0;
  while (i < t) {
    ll inc;
    auto f = [](ll x, ll y) {
      return (x + y - 1) / y;
    };
    if (k + y > r) {
      inc = min(f(k + y - r, x), (k - l) / x);
      k -= inc * x;
    } else if (x < y) {
      inc = f(r - y + 1 - k, y - x);
      k += inc * (y - x);
    } else if (x > y) {
      inc = (k - l) / (x - y);
      k += inc * (y - x);
    } else {
      cout << "Yes";
      return 0;
    }
    if (!inc) {
      cout << "No";
      return 0;
    }
    i += inc;
    if (i >= t) {
      cout << "Yes";
      return 0;
    }
    if (s.count(k)) {
      cout << "Yes";
      return 0;
    }
    s.emplace(k);
  }
}