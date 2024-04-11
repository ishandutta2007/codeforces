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

int n, m, k, t;
int a[maxn], l[maxn], r[maxn], d[maxn];

bool check(int tot) {
  int ignored = a[tot];
  vector<pii> traps; traps.reserve(k);
  FOR(i, 1, k) if (d[i] > ignored) traps.eb(l[i] - 1, r[i]);
  sort(all(traps));
  int last = 0, one = 0;
  for (auto now : traps) {
    if (now._1 > last) {
      one += now._1 - last;
      last = now._2;
    } else chkmax(last, now._2);
  }
  one += n + 1 - last;
  return (n + 1 - one) * 3 + one <= t;
}

int main() {
  scanf("%d%d%d%d", &m, &n, &k, &t);
  FOR(i, 1, m) scanf("%d", a + i);
  a[0] = 1e9;
  sort(a + 1, a + m + 1, greater<>());
  FOR(i, 1, k) scanf("%d%d%d", l + i, r + i, d + i);
  int lo = 0, hi = m;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d", lo);
}