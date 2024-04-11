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

const int maxn = 112345;

int n, k, z;
int a[maxn];

void solve() {
  scanf("%d%d%d", &n, &k, &z);
  FOR(i, 1, n) scanf("%d", a + i);
  int ans = 0;
  REP(j, z + 1) {
    int now = 0, mx = 0;
    FOR (i, 1, k - 2 * j + 1) {
      now += a[i];
      if (i < n) chkmax(mx, a[i] + a[i + 1]);
    }
    now += mx * j;
    chkmax(ans, now);
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}