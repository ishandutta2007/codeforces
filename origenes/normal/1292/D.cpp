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

const int maxn = 5123;

int n, w[maxn], vis[maxn], dep[maxn], f[maxn][maxn], g[maxn][maxn];
vector<int> fac[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int k;
    scanf("%d", &k);
    if (k == 0) k = 1;
    w[k]++;
  }
  vector<int> primes;
  FOR(i, 2, 5000) if (!vis[i]) {
    primes.eb(i);
    for (int j = i; j <= 5000; j += i) if (!vis[j]) vis[j] = i;
  }
  REP(i, 5001) fac[i].resize(primes.size());
  FOR(i, 2, 5000) {
    REP(j, int(primes.size())) fac[i][j] = fac[i - 1][j];
    int now = i;
    dep[i] = dep[i - 1];
    REP(j, int(primes.size())) while (now % primes[j] == 0) {
      now /= primes[j];
      dep[i]++;
      fac[i][primes.size() - 1 - j]++;
    }
  }
  FOR(i, 2, 5000) {
    int lcp = 0;
    REP(j, int(primes.size())) {
      if (fac[i][j] == fac[i - 1][j]) lcp += fac[i][j];
      else {
        lcp += min(fac[i][j], fac[i - 1][j]);
        break;
      }
    }
    f[i - 1][i] = f[i][i - 1] = lcp;
  }
  FOR(i, 1, 5000) FOR(j, i + 2, 5000) f[j][i] = f[i][j] = min(f[i][j - 1], f[j - 1][j]);
  FOR(i, 1, 5000) FOR(j, i + 1, 5000) g[j][i] = g[i][j] = dep[i] + dep[j] - 2 * f[i][j];
  ll ans = 1e18;
  FOR(i, 1, 5000) {
    ll now = 0;
    f[i][i] = 1e9;
    FOR(j, 1, 5000) now += w[j] * ll(g[i][j]);
    chkmin(ans, now);
  }
  FOR(i, 1, 4999) {
    ll now = 0;
    FOR(j, 1, 5000) {
      ll dis = f[i][j] >= f[i][i + 1] ? dep[j] - f[i][i + 1] : dep[j] + f[i][i + 1] - 2 * f[i][j];
      now += dis * w[j];
    }
    chkmin(ans, now);
  }
  printf("%lld", ans);
}