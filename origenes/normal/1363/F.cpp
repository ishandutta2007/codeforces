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

int f[maxn][maxn], ps[maxn][26], pt[maxn][26];
char s[maxn], t[maxn];
int n;

void solve() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  FOR(i, 1, n) {
    REP(j, 26) {
      ps[i][j] = ps[i - 1][j];
      pt[i][j] = pt[i - 1][j];
    }
    ps[i][s[i] - 'a']++;
    pt[i][t[i] - 'a']++;
  }
  REP(j, 26) if (ps[n][j] != pt[n][j]) {
    puts("-1");
    return;
  }
  REP(i, n + 1) REP(j, n + 1) f[i][j] = 1e9;
  REP(i, n + 1) f[i][0] = f[0][i] = 0;
  FOR(i, 1, n) FOR(j, 1, n) {
    f[i][j] = f[i - 1][j] + 1;
    if (s[i] == t[j]) chkmin(f[i][j], f[i - 1][j - 1]);
    if (ps[i][t[j] - 'a'] < pt[j][t[j] - 'a']) chkmin(f[i][j], f[i][j - 1]);
  }
  printf("%d\n", f[n][n]);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}