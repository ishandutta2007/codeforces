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

const int maxn = 212345;
const int upp = 1e6 + 5;
const int ROUND = 20;

ll a[maxn];
bool vis[upp];
int n;
vector<int> primes;

vector<ll> get(ll tar) {
  vector<ll> ret;
  if (tar <= 1) return ret;
  for (auto j : primes) if (tar % j == 0) {
    ret.eb(j);
    while (tar % j == 0) tar /= j;
  }
  if (tar != 1) ret.eb(tar);
  return ret;
}

ll check(ll x) {
  ll ret = 0;
  FOR(i, 1, n) {
    ll cur = x - a[i] % x;
    if (a[i] >= x) chkmin(cur, a[i] % x);
    ret += cur;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 2, 1e6) if (!vis[i]) {
    primes.eb(i);
    for (int j = i + i; j <= 1e6; j += i) vis[j] = true;
  }
  ll ans = 0;
  FOR(i, 1, n) ans += a[i] % 2;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(a + 1, a + n + 1, rng);
  FOR(i, 1, min(n, ROUND)) FOR(x, -1, 1) {
    auto factors = get(a[i] + x);
    for (auto j : factors) chkmin(ans, check(j));
  }
  printf("%lld", ans);
}