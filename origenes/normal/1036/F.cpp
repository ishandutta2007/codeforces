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

const int maxn = 65;

int mo[maxn], primes[maxn];
bool vis[maxn];

void init() {
  mo[1] = 1;
  int pcnt = 0;
  FOR(i, 2, 60) {
    if (!vis[i]) mo[i] = -1, primes[pcnt++] = i;
    for (int j = 0; j < pcnt && i * primes[j] <= 60; j++) {
      vis[i * primes[j]] = true;
      if (i % primes[j]) mo[i * primes[j]] = -mo[i];
      else {
        mo[i * primes[j]] = 0;
        break;
      }
    }
  }
}

long double get(long double a, int pw) {
  long double ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * a;
    a = a * a;
    pw >>= 1;
  }
  return ret;
}

inline int dcmp(long double x) {
  if (abs(x) < 1e-16) return 0;
  return x > 0 ? 1 : -1;
}

int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    ll ans = 0, n;
    scanf("%lld", &n);
    FOR(i, 1, 60) {
      ll now = pow((long double) n, double(1) / i) + 1;
      while (dcmp(get(now, i) - n) > 0) now--;
      ans += mo[i] * (now - 1);
    }
    printf("%lld\n", ans);
  }
}