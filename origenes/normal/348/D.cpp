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

const int maxn = 3123;
const int MOD = 1e9 + 7;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

char mat[maxn][maxn];
int n, m, f[maxn][maxn], g[maxn][maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%s", mat[i] + 1);
  f[1][1] = g[1][1] = 1;
  FOR(i, 1, n) FOR(j, 2, m) if (mat[i][j] == '.') f[i][j] = add(f[i - 1][j], f[i][j - 1]);
  FOR(i, 2, n) FOR(j, 1, m) if (mat[i][j] == '.') g[i][j] = add(g[i - 1][j], g[i][j - 1]);
  printf("%d", add(mul(f[n - 1][m], g[n][m - 1]), MOD - mul(f[n][m - 1], g[n - 1][m])));
}