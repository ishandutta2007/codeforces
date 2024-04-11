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

ll lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

ll a, b, k, ans;

void check(ll g) {
  ll cur = 0;
  if (a % g) cur = g - a % g;
  ll now = lcm(a + cur, b + cur);
  if (now < ans) {
    ans = now;
    k = cur;
  }
}

int main() {
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b) {
    cout << 0;
    return 0;
  }
  ll d = b - a, upp = sqrt(d) + 0.5;
  ans = lcm(a, b);
  FOR(i, 1, upp) if (d % i == 0) {
    check(i);
    check(d / i);
  }
  cout << k;
}