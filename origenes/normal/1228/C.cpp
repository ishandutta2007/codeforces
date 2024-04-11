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

const int MOD = 1e9 + 7;

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, ll pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

ll x, n;

int main() {
  scanf("%lld%lld", &x, &n);
  set<ll> fac;
  for (int i = 2; i * i <= x; i++) while (x % i == 0) {
    fac.emplace(i);
    x /= i;
  }
  if (x > 1) fac.emplace(x);
  int ans = 1;
  for (auto now : fac) {
    ll pw = 0, rem = n;
    while (rem) {
      rem /= now;
      pw += rem;
    }
    ans = mul(ans, pow_mod(now, pw));
  }
  printf("%d", ans);
}