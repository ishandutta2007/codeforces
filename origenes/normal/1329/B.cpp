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

const int maxn = 35;

int f[maxn][maxn];
int d, m;

inline int add(int a, int b) {
  a += b;
  if (a >= m) a -= m;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % m;
}

void solve() {
  scanf("%d%d", &d, &m);
  reset(f, 0);
  REP(j, 30) if (d >= 1 << j) f[1][j] = min(1 << j, d - (1 << j) + 1) % m;
  FOR(i, 1, 29) REP(j, 30) FOR(k, j + 1, 30) if (d >= 1 << k) {
    if (d >= (1 << k + 1) - 1) f[i + 1][k] = add(f[i + 1][k], mul(f[i][j], (1 << k) % m));
    else f[i + 1][k] = add(f[i + 1][k], mul(f[i][j], (d - (1 << k) + 1) % m));
  }
  int ans = 0;
  FOR(i, 1, 30) REP(j, 31) ans = add(ans, f[i][j]);
  printf("%d\n", ans % m);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}