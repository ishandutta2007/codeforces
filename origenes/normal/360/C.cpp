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

const int MOD = 1e9 + 7;
const int maxn = 2123;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, k;
char s[maxn];
int f[maxn][maxn], g[maxn][maxn];

void gen() {
  n = 2000, k = 2000;
  srand(time(NULL));
  FOR(i, 1, n) s[i] = rand() % 26 + 'a';
}

int main() {
#ifndef LOCAL
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
#endif
  f[0][k] = g[0][k] = 1;
  FOR(i, 1, n) REP(j, k + 1) {
    f[i][j] = mul(s[i] - 'a', g[i - 1][j]);
    ROF(p, i - 1, 0) {
      if ((n - i + 1) * (i - p) + j > k) break;
      f[i][j] = add(f[i][j], mul('z' - s[i], f[p][j + (n - i + 1) * (i - p)]));
    }
    g[i][j] = add(g[i - 1][j], f[i][j]);
  }
  int ans = 0;
  REP(i, n + 1) ans = add(ans, f[i][0]);
  printf("%d", ans);
}