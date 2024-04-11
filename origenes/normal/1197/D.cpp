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

const int maxn = 312345;

int n, m, k;
int a[maxn];
ll s[maxn], ans, lo[10];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) s[i] = s[i - 1] + a[i];
  FOR(i, 1, n) s[i] -= i / m * ll(k);
  fill(lo, lo + m, 1e18);
  lo[0] = 0;
  FOR(i, 1, n) {
    REP(j, m) {
      int r = i % m;
      ll now = s[i] - lo[j];
      if (r > j) now -= k;
      chkmax(ans, now);
    }
    chkmin(lo[i % m], s[i]);
  }
  printf("%lld", ans);
}