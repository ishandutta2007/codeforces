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

const int maxn = 1123456;

int n, k, l;
char s[maxn];
int f[maxn], g[maxn];

pii F(int allowed) {
  reset(f, 0x3f);
  f[0] = 0;
  FOR(i, 1, n) {
    g[i] = 0;
    if (f[i - 1] + s[i - 1] < f[i]) {
      f[i] = f[i - 1] + s[i - 1];
      g[i] = g[i - 1];
    }
    if (i >= l && f[i - l] + allowed < f[i]) {
      f[i] = f[i - l] + allowed;
      g[i] = g[i - l] + 1;
    }
  }
  return {f[n], g[n]};
}

int solve() {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (F(mi)._2 > k) lo = mi + 1;
    else hi = mi;
  }
  return F(lo)._1 - k * lo;
}

int main() {
  scanf("%d%d%d", &n, &k, &l);
  scanf("%s", s);
  if (k * ll(l) >= n) {
    puts("0");
    return 0;
  }
  REP(i, n) s[i] = (islower(s[i]) == 0);
  int ans = solve();
  REP(i, n) s[i] ^= 1;
  chkmin(ans, solve());
  printf("%d", ans);
}