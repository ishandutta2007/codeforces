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

int n, h[3][maxn];
ll f[maxn][3];

int main() {
  scanf("%d", &n);
  REP(j, 2) FOR(i, 1, n) scanf("%d", &h[j][i]);
  FOR(i, 1, n) REP(j, 3) REP(k, 3) if (k != j)
    chkmax(f[i][j], h[j][i] + f[i - 1][k]);
  printf("%lld", max(f[n][0], f[n][1]));
}