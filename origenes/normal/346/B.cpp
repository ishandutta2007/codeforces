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

const int maxn = 112;

int G[maxn][26];

int match(string &s, string &t) {
  ROF(i, int(s.length()) - 1, 1) if (s.substr(0, i) == t.substr(t.length() - i, i)) return i;
  return 0;
}

void build(const char *t, int n) {
  string tar, have;
  FOR(i, 1, n) {
    tar += t[i];
    have += t[i];
    REP(idx, 26) {
      char ch = idx + 'A';
      if (ch == t[i]) continue;
      have[i - 1] = ch;
      G[i - 1][idx] = match(tar, have);
    }
    have.back() = t[i];
  }
}

int f[maxn][maxn][maxn], x[maxn][maxn][maxn], y[maxn][maxn][maxn], z[maxn][maxn][maxn];
char s[maxn], t[maxn], v[maxn], ch[maxn][maxn][maxn];

void upd(int ni, int nj, int nk, int i, int j, int k, int inc) {
  if (f[ni][nj][nk] < f[i][j][k] + inc) {
    f[ni][nj][nk] = f[i][j][k] + inc;
    x[ni][nj][nk] = i;
    y[ni][nj][nk] = j;
    z[ni][nj][nk] = k;
    if (inc) ch[ni][nj][nk] = s[i + 1];
  }
}

int main() {
  scanf("%s%s%s", s + 1, t + 1, v + 1);
  int n = strlen(s + 1), m = strlen(t + 1), p = strlen(v + 1);
  build(v, p);
  reset(f, 0xc0);
  reset(x, -1);
  reset(y, -1);
  reset(z, -1);
  REP(i, n) f[i][0][0] = 0;
  REP(j, m) f[0][j][0] = 0;
  REP(i, n + 1) REP(j, m + 1) REP(k, p) {
    if (i + 1 <= n) upd(i + 1, j, k, i, j, k, 0);
    if (j + 1 <= m) upd(i, j + 1, k, i, j, k, 0);
    if (i < n && j < m && s[i + 1] == t[j + 1]) {
      if (k + 1 < p && v[k + 1] == s[i + 1]) upd(i + 1, j + 1, k + 1, i, j, k, 1);
      else if (v[k + 1] != s[i + 1]) upd(i + 1, j + 1, G[k][s[i + 1] - 'A'], i, j, k, 1);
    }
  }
  int tail = -1;
  REP(k, p) {
    if (tail == -1) {
      if (f[n][m][k] > 0) tail = k;
    } else if (f[n][m][k] > f[n][m][tail]) tail = k;
  }
  if (tail == -1) {
    puts("0");
    return 0;
  }
  string ans;
  for (int i = n, j = m, k = tail; x[i][j][k] != -1; ) {
    if (i - x[i][j][k] == 1 && j - y[i][j][k] == 1) ans += ch[i][j][k];
    int pi = i, pj = j, pk = k;
    i = x[pi][pj][pk];
    j = y[pi][pj][pk];
    k = z[pi][pj][pk];
  }
  reverse(all(ans));
  cout << ans;
}