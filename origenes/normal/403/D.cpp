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

const int maxn = 1005;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int f[45][maxn][maxn], C[maxn][maxn], fac[45];

int main() {
  REP(j, 1001) f[1][j][j] = 1;
  REP(j, 1001) FOR(k, 1, 1000) f[1][j][k] = add(f[1][j][k], f[1][j][k - 1]);
  FOR(i, 2, 44) FOR(j, 1, 1000) {
    FOR(k, 1, j) f[i][j][k] = f[i - 1][j - k][k - 1];
    FOR(k, 1, 1000) f[i][j][k] = add(f[i][j][k - 1], f[i][j][k]);
  }
  C[0][0] = 1;
  FOR(i, 1, 1000) {
    C[i][0] = 1;
    FOR(j, 1, i) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  }
  fac[1] = 1;
  FOR(i, 2, 44) fac[i] = mul(fac[i - 1], i);
  int T; scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k * (k + 1) / 2 > n) {
      puts("0");
      continue;
    }
    int ans = 0;
    FOR(j, k * (k - 1) / 2, n - k) ans = add(ans, mul(C[n - j][k], f[k][j][1000]));
    printf("%d\n", mul(ans, fac[k]));
  }
}