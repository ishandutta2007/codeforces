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

int n, p, k;
int a[maxn];
ll s[maxn], S[maxn];

void solve() {
  scanf("%d%d%d", &n, &p, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  FOR(i, 1, n) s[i] = s[i - 1] + a[i];
  for (int i = 1; i * k <= n; i++) S[i * k] = S[i * k - k] + a[i * k];
  int grp = 0;
  for (grp = 1; grp * k <= n; grp++) if (S[grp * k] > p) break;
  grp--;
  int ans = grp * k, inc = 0;
  for (inc = 1; inc < k; inc++) {
    int en = ans + inc; if (en > n) break;
    ll cost = 0;
    while (en > k) {
      cost += a[en];
      en -= k;
    }
    cost += s[en];
    if (cost > p) break;
  }
  printf("%d\n", ans + inc - 1);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}