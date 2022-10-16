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

const int maxn = 255;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int n, k;
int f[maxn][maxn], g[maxn][2], comb[maxn][maxn], p0[maxn * maxn], p1[maxn * maxn];

int main() {
  scanf("%d%d", &n, &k);
  f[0][0] = p0[0] = p1[0] = 1;
  FOR(i, 1, n * n) p0[i] = mul(p0[i - 1], k), p1[i] = mul(p1[i - 1], k - 1);
  REP(i, n + 1) {
    comb[i][0] = 1;
    FOR(j, 1, i) comb[i][j] = add(comb[i - 1][j - 1], comb[i - 1][j]);
  }
  int ans = 0;
  REP(i, n + 1) REP(j, n + 1) {
    int now = mul(mul(comb[n][i], comb[n][j]), mul(p0[(n - i) * (n - j)], p1[sqr(n) - (n - i) * (n - j)]));
    if ((i + j) & 1) now = MOD - now;
    ans = add(ans, now);
  }
  printf("%d", ans);
}