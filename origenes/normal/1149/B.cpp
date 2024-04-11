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

const int maxn = 1123456;
const int maxm = 255;

int n, q, l0, l1, l2;
char s[maxn], op[5];
int nxt[maxn][26], dp[maxm][maxm][maxm];
vector<int> lis[3];

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  fill(nxt[n], nxt[n] + 26, n);
  fill(nxt[n + 1], nxt[n + 1] + 26, n);
  ROF(i, n - 1, 0) {
    int idx = s[i] - 'a';
    REP(j, 26) {
      nxt[i][j] = nxt[i + 1][j];
      if (j == idx) nxt[i][j] = i;
    }
  }
  dp[0][0][0] = -1;
  while (q--) {
    scanf("%s", op);
    if (op[0] == '+') {
      int idx;
      char ch;
      scanf("%d %c", &idx, &ch);
      idx--;
      ch -= 'a';
      lis[idx].eb(ch);
      switch (idx) {
        case 0: {
          l0++;
          REP(j, l1 + 1) REP(k, l2 + 1) {
            dp[l0][j][k] = nxt[dp[l0 - 1][j][k] + 1][ch];
            if (j) chkmin(dp[l0][j][k], nxt[dp[l0][j - 1][k] + 1][lis[1][j - 1]]);
            if (k) chkmin(dp[l0][j][k], nxt[dp[l0][j][k - 1] + 1][lis[2][k - 1]]);
          }
          break;
        }
        case 1: {
          l1++;
          REP(i, l0 + 1) REP(k, l2 + 1) {
            dp[i][l1][k] = nxt[dp[i][l1 - 1][k] + 1][ch];
            if (i) chkmin(dp[i][l1][k], nxt[dp[i - 1][l1][k] + 1][lis[0][i - 1]]);
            if (k) chkmin(dp[i][l1][k], nxt[dp[i][l1][k - 1] + 1][lis[2][k - 1]]);
          }
          break;
        }
        case 2: {
          l2++;
          REP(i, l0 + 1) REP(j, l1 + 1) {
            dp[i][j][l2] = nxt[dp[i][j][l2 - 1] + 1][ch];
            if (i) chkmin(dp[i][j][l2], nxt[dp[i - 1][j][l2] + 1][lis[0][i - 1]]);
            if (j) chkmin(dp[i][j][l2], nxt[dp[i][j - 1][l2] + 1][lis[1][j - 1]]);
          }
          break;
        }
        default: assert(0);
      }
    } else {
      int idx;
      scanf("%d", &idx);
      idx--;
      if (!idx) l0--;
      else if (idx == 1) l1--;
      else l2--;
      lis[idx].pop_back();
    }
    puts(dp[l0][l1][l2] == n ? "NO" : "YES");
  }
}