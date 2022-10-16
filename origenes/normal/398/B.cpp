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

const int maxn = 2123;

int n, m;
double f[maxn][maxn];
bool vx[maxn], vy[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    vx[x] = true; vy[y] = true;
  }
  int tx = n, ty = n;
  FOR(i, 1, n) tx -= vx[i];
  FOR(i, 1, n) ty -= vy[i];
  REP(i, tx + 1) REP(j, ty + 1) {
    if (i == 0 && j == 0) continue;
    if (i > 0) f[i][j] += f[i - 1][j] * (i * n - i * j) / sqr(n);
    if (j > 0) f[i][j] += f[i][j - 1] * (j * n - i * j) / sqr(n);
    if (i > 0 && j > 0) f[i][j] += f[i - 1][j - 1] * i * j / sqr(n);
    double p = double(i * n + j * n - i * j) / sqr(n);
    f[i][j] = (f[i][j] + 1) / p;
  }
  printf("%.10lf", f[tx][ty]);
}