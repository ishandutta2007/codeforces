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

const int maxn = 212;

int R, G, B;
ll r[maxn], g[maxn], b[maxn], f[maxn][maxn][maxn];

int main() {
  scanf("%d%d%d", &R, &G, &B);
  FOR(i, 1, R) scanf("%lld", r + i);
  FOR(j, 1, G) scanf("%lld", g + j);
  FOR(k, 1, B) scanf("%lld", b + k);
  sort(r + 1, r + R + 1, greater<>());
  sort(g + 1, g + G + 1, greater<>());
  sort(b + 1, b + B + 1, greater<>());
  REP(i, R + 1) REP(j, G + 1) REP(k, B + 1) {
    if (i != R) chkmax(f[i + 1][j][k], f[i][j][k]);
    if (j != G) chkmax(f[i][j + 1][k], f[i][j][k]);
    if (k != B) chkmax(f[i][j][k + 1], f[i][j][k]);
    if (i != R && j != G) chkmax(f[i + 1][j + 1][k], f[i][j][k] + r[i + 1] * g[j + 1]);
    if (i != R && k != B) chkmax(f[i + 1][j][k + 1], f[i][j][k] + r[i + 1] * b[k + 1]);
    if (j != G && k != B) chkmax(f[i][j + 1][k + 1], f[i][j][k] + g[j + 1] * b[k + 1]);
  }
  printf("%lld", f[R][G][B]);
}