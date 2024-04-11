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

const int MOD = 998244353;
const int maxn = 212;

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = mul(ret, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ret;
}

ll D;
int q, fac[maxn], ifac[maxn];

int main() {
  scanf("%lld", &D);
  vector<ll> primes;
  for (ll i = 2; sqr(i) <= D; i++) if (D % i == 0) {
    primes.eb(i);
    while (D % i == 0) D /= i;
  }
  if (D != 1) primes.eb(D);
  fac[0] = ifac[0] = 1;
  FOR(i, 1, 200) {
    fac[i] = mul(fac[i - 1], i);
    ifac[i] = pow_mod(fac[i], MOD - 2);
  }
  scanf("%d", &q);
  while (q--) {
    ll u, v;
    scanf("%lld%lld", &u, &v);
    int ans1 = 1, ans2 = 1, s1 = 0, s2 = 0;
    for (auto p : primes) {
      int p1 = 0, p2 = 0;
      while (u % p == 0) u /= p, p1++;
      while (v % p == 0) v /= p, p2++;
      if (p1 > p2) {
        ans2 = mul(ans2, ifac[p1 - p2]);
        s2 += p1 - p2;
      } else {
        ans1 = mul(ans1, ifac[p2 - p1]);
        s1 += p2 - p1;
      }
    }
    printf("%d\n", mul(mul(ans1, ans2), mul(fac[s1], fac[s2])));
  }
}