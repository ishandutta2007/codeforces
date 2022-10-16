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

const int maxn = (1 << 18) + 123;
const int inf = 1e9 + 5;

int n, a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int me = -1;
  FOR(i, 1, n) if (a[i] == -1) me = i;
  fill(a + 1, a + me + 1, 0);
  ll ans = a[n]; a[n] = inf;
  int lo = n >> 1;
  while (lo) {
    int mn = inf, rec;
    ROF(i, n, lo) if (a[i] < mn) {
      mn = a[i];
      rec = i;
    }
    ans += mn, a[rec] = inf;
    lo >>= 1;
  }
  printf("%lld", ans);
}