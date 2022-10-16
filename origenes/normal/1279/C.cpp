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

int n, m;
int a[maxn], b[maxn], pos[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, m) scanf("%d", b + i);
  FOR(i, 1, n) pos[a[i]] = i;
  ll ans = 0;
  int mx = 0;
  FOR(i, 1, m) {
    int dep = pos[b[i]];
    if (dep < mx) {
      ans++;
      continue;
    }
    ans += 2 * (dep - i + 1) - 1;
    mx = dep;
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}