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
const char *digits[] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int calc(const char *have, int d) {
  int ret = 0;
  REP(i, 7) {
    if (have[i] == '1' && digits[d][i] == '0') return 1e5;
    if (have[i] == '0' && digits[d][i] == '1') ret++;
  }
  return ret;
}

int ans[maxn], a[maxn][10];
bool f[maxn][maxn];
int n, k;
char have[maxn][7];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%s", have[i]);
  FOR(i, 1, n) REP(j, 10) a[i][j] = calc(have[i], j);
  f[n][k] = true;
  ROF(i, n - 1, 0) REP(j, k + 1) REP(v, 10) if (a[i + 1][v] <= j) f[i][j - a[i + 1][v]] |= f[i + 1][j];
  if (!f[0][0]) {
    puts("-1");
    return 0;
  }
  int j = 0;
  REP(i, n) ROF(v, 9, 0) if (a[i + 1][v] + j <= k && f[i + 1][a[i + 1][v] + j]) {
    ans[i + 1] = v;
    j += a[i + 1][v];
    break;
  }
  FOR(i, 1, n) printf("%d", ans[i]);
}