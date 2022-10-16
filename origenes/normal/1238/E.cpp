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

inline int lowbit(int x) {
  return x & -x;
}

char s[maxn];
int n, m, cnt[21][21];
int f[1 << 20], g[20][1 << 20];

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  FOR(i, 1, n - 1) {
    int x = s[i] - 'a', y = s[i - 1] - 'a';
    if (x != y) cnt[x][y]++, cnt[y][x]++;
  }
  int ALL = (1 << m) - 1;
  REP(i, m) FOR(mask, 1, ALL) {
    int pre = mask ^ lowbit(mask), j = __builtin_ctz(lowbit(mask));
    g[i][mask] = g[i][pre] + cnt[i][j];
  }
  reset(f, 0x3f);
  f[0] = 0;
  REP(mask, ALL) REP(j, m) if (!(mask & (1 << j))) chkmin(f[mask | (1 << j)], f[mask] + (__builtin_popcount(mask) + 1) * (g[j][mask] - g[j][ALL ^ mask]));
  printf("%d", f[ALL]);
}