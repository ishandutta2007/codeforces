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

const int maxn = 412;

int n, m, f[maxn][maxn];
char s[maxn], t[maxn];

bool check(int en) {
  REP(i, n + 1) REP(j, en + 1) f[i][j] = 0;
  f[0][0] = en;
  FOR(i, 1, n) REP(j, en + 1) {
    f[i][j] = f[i - 1][j];
    if (j && s[i] == t[j]) chkmax(f[i][j], f[i - 1][j - 1]);
    if (f[i - 1][j] && s[i] == t[f[i - 1][j] + 1]) chkmax(f[i][j], f[i - 1][j] + 1);
  }
  return f[n][en] == m;
}

void solve() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1), m = strlen(t + 1);
  if (m == 1) {
    FOR(i, 1, n) if (s[i] == t[1]) {
      puts("YES");
      return;
    }
    puts("NO");
    return;
  }
  FOR(i, 1, m - 1) if (check(i)) {
    puts("YES");
    return;
  }
  puts("NO");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}