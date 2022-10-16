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

int n, k;
int a[maxn], w[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, k) scanf("%d", w + i);
  int one = 0;
  FOR(i, 1, k) if (w[i] == 1) one++;
  sort(a + 1, a + n + 1, greater<>());
  ll ans = 0;
  FOR(i, 1, k) ans += a[i];
  vector<int> buff;
  FOR(i, 1, k) {
    if (w[i] == 1) continue;
    buff.eb(w[i] - 1);
  }
  if (buff.empty()) {
    printf("%lld\n", ans * 2);
    return;
  }
  sort(all(buff), greater<>());
  int j = n;
  for (auto x : buff) {
    ans += a[j];
    j -= x;
  }
  FOR(i, 1, one) ans += a[i];
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}