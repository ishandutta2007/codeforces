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

const int maxn = 312345;

int n, m, f[1 << 8], I, J;
int a[maxn][8], g[maxn];

bool check(int b) {
  reset(f, 0);
  int ALL = (1 << m) - 1;
  FOR(i, 1, n) {
    g[i] = 0;
    REP(j, m) if (a[i][j] >= b) g[i] |= 1 << j;
    if (!f[ALL ^ g[i]]) f[ALL ^ g[i]] = i;
  }
  REP(i, m) REP(mask, 1 << m) if (!f[mask] && mask & (1 << i)) f[mask] = f[mask ^ (1 << i)];
  FOR(i, 1, n) if (f[g[i]]) {
    I = i, J = f[g[i]];
    return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) REP(j, m) scanf("%d", &a[i][j]);
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  check(lo);
  printf("%d %d", I, J);
}