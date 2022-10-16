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

const int maxn = 3512;

int a[maxn];

void solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  int ans = 0;
  chkmin(k, m - 1);
  if (k == m - 1) {
    FOR(i, 1, k + 1) {
      int j = n - k + i - 1;
      chkmax(ans, a[i]); chkmax(ans, a[j]);
    }
    printf("%d\n", ans);
    return;
  }
  int to = m - 1 - k;
  FOR(i, 1, k + 1) {
    int st = i, en = n - k + i - 1;
    auto get = [&]() -> int {
      int ret = 1e9 + 5;
      FOR(j, en - to, en) {
        chkmin(ret, max(a[st], a[j]));
        st++;
      }
      return ret;
    };
    chkmax(ans, get());
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}