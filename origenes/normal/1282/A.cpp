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

int a, b, c, r;

void solve() {
  scanf("%d%d%d%d", &a, &b, &c, &r);
  if (a > b) swap(a, b);
  int ans;
  if (c <= a) {
    ans = b - a;
    if (c + r > a && c + r < b) {
      ans -= c + r - a;
    }
    if (c + r >= b) ans = 0;
  } else if (c >= b) {
    ans = b - a;
    if (c - r <= a) ans = 0;
    else if (c - r <= b) ans -= b - (c - r);
  } else {
    int mn = max(c - r, a), mx = min(c + r, b);
    ans = b - a - (mx - mn);
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}