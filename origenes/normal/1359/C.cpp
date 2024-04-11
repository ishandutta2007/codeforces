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

void solve() {
  int h, c, t;
  scanf("%d%d%d", &h, &c, &t);
  if (t == h) {
    puts("1");
    return;
  }
  if (t * 2 <= h + c) {
    puts("2");
    return;
  }
  int i = (h - t) / (2 * t - h - c);
  ll p = abs(ll(i + 1) * h + ll(i) * c - (2LL * i + 1) * t);
  ll q = abs(ll(i + 2) * h + ll(i + 1) * c - (2LL * (i + 1) + 1) * t);
  if (p * (2 * i + 3) <= q * (2 * i + 1)) printf("%d\n", 2 * i + 1);
  else printf("%d\n", 2 * i + 3);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}