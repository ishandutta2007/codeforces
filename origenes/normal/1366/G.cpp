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

const int maxn = 11234;

int f[maxn][maxn], g[maxn];
char s[maxn], t[maxn];

int main() {
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  reset(f, 0x3f);
  FOR(i, 1, n) if (s[i] != '.') {
    int cnt = 0, j = i;
    while (j <= n) {
      if (s[j] != '.') cnt++;
      else cnt--;
      if (cnt == 0) break;
      j++;
    }
    g[i] = j;
  }
  f[0][0] = 0;
  REP(i, n) REP(j, m + 1) {
    if (j != m && s[i + 1] == t[j + 1]) chkmin(f[i + 1][j + 1], f[i][j]);
    else {
      chkmin(f[i + 1][j], f[i][j] + 1);
      if (s[i + 1] == '.' && j) chkmin(f[i + 1][j - 1], f[i][j]);
      if (s[i + 1] != '.' && g[i + 1] <= n) chkmin(f[g[i + 1]][j], f[i][j]);
    }
  }
  printf("%d", f[n][m]);
}