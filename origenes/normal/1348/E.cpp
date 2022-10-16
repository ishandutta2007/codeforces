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

const int maxn = 512;

int n, k;
pair<ll, ll> f[maxn][maxn];
int a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d%d", a + i, b + i);
  reset(f, 0xc0);
  f[0][0] = {0LL, 0LL};
  FOR(i, 1, n) REP(j, k) REP(jj, k) {
    int nr = jj <= j ? j - jj : k + j - jj, inc = jj <= j ? 0 : 1;
    if (nr > a[i]) continue;
    ll r = a[i] - nr, v = f[i - 1][jj]._1 + inc + (r + b[i]) / k;
    ll rb = (r + b[i]) % k;
    if (rb > b[i]) continue;
    rb += f[i - 1][jj]._2;
    if (rb >= k) v++, rb -= k;
    chkmax(f[i][j], mp(v, rb));
  }
  ll ans = 0;
  REP(j, k) chkmax(ans, f[n][j]._1);
  printf("%lld", ans);
}