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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;
const int maxm = 55;

void get(const char *s, int n, int G[maxm][26], int &shift) {
  vector<int> f(maxm);
  G[0][s[0] - 'a'] = 1;
  FOR(i, 1, n - 1) {
    int j = f[i];
    while (j && s[i] != s[j]) j = f[j];
    f[i + 1] = s[i] == s[j] ? j + 1 : 0;
    FOR(c, 'a', 'z') {
      j = i;
      while (j && s[j] != c) j = f[j];
      if (s[j] == c) j++;
      G[i][c - 'a'] = j;
    }
  }
  string buff(s);
  ROF(len, n - 1, 1) if (buff.substr(0, len) == buff.substr(n - len, len)) {
    shift = len;
    break;
  }
}

char c[maxn], s[maxm], t[maxm];
int dp[maxn][maxm][maxm], gs[maxm][26], gt[maxm][26], shift[2];
int n, ms, mt, ans = 0xc0c0c0c0;

int main() {
  scanf("%s%s%s", c, s, t);
  n = strlen(c), ms = strlen(s), mt = strlen(t);
  get(s, ms, gs, shift[0]);
  get(t, mt, gt, shift[1]);
  reset(dp, 0xc0);
  dp[0][0][0] = 0;
  REP(i, n) REP(j, ms) REP(k, mt) {
    if (c[i] == '*') {
      REP(u, 26) {
        int nj = gs[j][u], nk = gt[k][u], inc = 0;
        if (nj == ms) inc++, nj = shift[0];
        if (nk == mt) inc--, nk = shift[1];
        chkmax(dp[i + 1][nj][nk], dp[i][j][k] + inc);
      }
    } else {
      int u = c[i] - 'a', nj = gs[j][u], nk = gt[k][u], inc = 0;
      if (nj == ms) inc++, nj = shift[0];
      if (nk == mt) inc--, nk = shift[1];
      chkmax(dp[i + 1][nj][nk], dp[i][j][k] + inc);
    }
  }
  REP(i, ms) REP(j, mt) chkmax(ans, dp[n][i][j]);
  printf("%d", ans);
}