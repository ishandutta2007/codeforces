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

const int maxn = 212345;

char s[maxn];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  vector<vector<int>> nxt(n + 1, vector<int>(3));
  REP(i, 3) nxt[n][i] = n;
  ROF(i, n - 1, 0) {
    REP(j, 3) nxt[i][j] = nxt[i + 1][j];
    nxt[i][s[i] - '1'] = i;
  }
  REP(i, 3) if (nxt[0][i] == n) {
    puts("0");
    return;
  }
  int ans = n;
  REP(i, n) {
    int now = 0;
    REP(j, 3) {
      if (nxt[i][j] == n) {
        printf("%d\n", ans);
        return;
      }
      chkmax(now, nxt[i][j] - i + 1);
    }
    chkmin(ans, now);
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}