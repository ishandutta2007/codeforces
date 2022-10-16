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

int a[maxn], n, x;

void solve() {
  scanf("%d%d", &n, &x);
  FOR(i, 1, n) scanf("%d", a + i);
  int tot = 0, l = n + 1, r = 0;
  FOR(i, 1, n) {
    a[i] %= x;
    tot = tot + a[i];
    if (a[i]) {
      chkmin(l, i);
      chkmax(r, i);
    }
  }
  if (tot % x != 0) {
    printf("%d\n", n);
    return;
  }
  if (l > r) {
    puts("-1");
    return;
  }
  printf("%d\n", l < n - r + 1 ? n - l : r - 1);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}