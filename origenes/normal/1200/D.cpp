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

char mat[maxn][maxn];
int n, k;
int r[maxn][2], c[maxn][2], s[maxn][maxn];

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    r[i][0] = c[i][0] = n + 1;
    r[i][1] = c[i][1] = 0;
  }
  FOR(i, 1, n) {
    scanf("%s", mat[i] + 1);
    FOR(j, 1, n) if (mat[i][j] == 'B') {
      chkmin(r[i][0], j);
      chkmax(r[i][1], j);
      chkmin(c[j][0], i);
      chkmax(c[j][1], i);
    }
  }
  int now = 0, ans = 0;
  FOR(i, 1, n) {
    if (r[i][0] > r[i][1]) now++;
    else if (r[i][0] > r[i][1] - k) {
      int fr = max(1, i - k + 1), fc = max(1, r[i][1] - k + 1);
      s[fr][fc]++; s[fr][r[i][0] + 1]--;
      s[i + 1][fc]--; s[i + 1][r[i][0] + 1]++;
    }
  }
  FOR(i, 1, n) {
    if (c[i][0] > c[i][1]) now++;
    else if (c[i][0] > c[i][1] - k) {
      int fr = max(1, c[i][1] - k + 1), fc = max(1, i - k + 1);
      s[fr][fc]++; s[fr][i + 1]--;
      s[c[i][0] + 1][fc]--; s[c[i][0] + 1][i + 1]++;
    }
  }
  FOR(i, 1, n) FOR(j, 1, n) {
    s[i][j] -= s[i - 1][j - 1];
    s[i][j] += s[i - 1][j];
    s[i][j] += s[i][j - 1];
    chkmax(ans, s[i][j]);
  }
  printf("%d", ans + now);
}