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

const int maxn = 312;

int n, k;
int a[maxn][maxn];

void solve() {
  scanf("%d%d", &n, &k);
  int b = k / n;
  REP(i, b) a[0][i] = 1;
  FOR(i, b, n - 1) a[0][i] = 0;
  FOR(i, 1, n - 1) REP(j, n) a[i][j] = a[i - 1][(j - 1 + n) % n];
  int ex = k - b * n;
  printf("%d\n", ex ? 2 : 0);
  int i = 0;
  while (ex--) {
    int j = (i + b) % n;
    a[i][j] = 1;
    i++;
  }
  REP(i, n) {
    REP(j, n) printf("%d", a[i][j]);
    putchar('\n');
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}