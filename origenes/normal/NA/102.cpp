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

int n, k, a, b;
ll mmax, mmin;

void solve (int r) {
  REP(i, n) {
    if (!r && !i) continue;
    ll now = ll(n) * k / __gcd(ll(n) * k, ll(i) * k + r);
    chkmin(mmin, now);
    chkmax(mmax, now);
  }
  if (!r) mmin = 1;
}

int main() {
  scanf("%d%d%d%d", &n, &k, &a, &b);
  mmax = 1;
  mmin = 1e15;
  solve(a + b);
  solve((k - b + a) % k);
  solve((k - a + b) % k);
  solve((2 * k - a - b) % k);
  printf("%lld %lld", mmin, mmax);
}