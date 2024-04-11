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

const int maxn = 5123;
const int MOD = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

int n;
char s[maxn][2];
int f[maxn][maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%s", s[i]);
  f[1][1] = 1;
  FOR(i, 2, n) {
    if (s[i - 1][0] == 'f') {
      FOR(j, 1, i - 1) f[i][j + 1] = f[i - 1][j];
    } else {
      int sum = 0;
      ROF(j, i - 1, 0) {
        sum = add(sum, f[i - 1][j]);
        f[i][j] = sum;
      }
    }
  }
  int ans = 0;
  FOR(j, 1, n) ans = add(ans, f[n][j]);
  printf("%d", ans);
}