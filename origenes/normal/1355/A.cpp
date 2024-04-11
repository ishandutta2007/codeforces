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

ll calc(ll a) {
  int mx = 0, mn = 10;
  while (a) {
    int d = a % 10;
    chkmax(mx, d);
    chkmin(mn, d);
    a /= 10;
  }
  return mx * mn;
}

void solve() {
  ll a, K;
  scanf("%lld%lld", &a, &K);
  if (K == 1) {
    printf("%lld\n", a);
    return;
  }
  K--;
  while (K--) {
    ll d = calc(a);
    if (d == 0) {
      printf("%lld\n", a);
      return;
    }
    a += d;
  }
  printf("%lld\n", a);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}