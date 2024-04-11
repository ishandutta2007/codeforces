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
int a[maxn], s[maxn][7], id[maxn];
ll f[maxn][1 << 7];

int main() {
  scanf("%d%d%d", &n, &p, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) REP(j, p) scanf("%d", &s[i][j]);
  iota(id + 1, id + n + 1, 1);
  sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] > a[y]; });
  reset(f, 0xc0);
  f[0][0] = 0;
  FOR(i, 1, n) {
    int now = i & 1, pre = 1 - now;
    reset(f[now], 0xc0);
    REP(mask, 1 << p) {
      int skipped = __builtin_popcount(mask);
      chkmax(f[now][mask], f[pre][mask] + (i - skipped <= k ? a[id[i]] : 0));
      REP(j, p) if (mask & (1 << j)) chkmax(f[now][mask], f[pre][mask ^ (1 << j)] + s[id[i]][j]);
    }
  }
  printf("%lld", f[n & 1][(1 << p) - 1]);
}