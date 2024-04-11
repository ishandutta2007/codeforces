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

const int maxn = 2123456;

char s[maxn];
int n, need[15][15][15], ans[15][15];

int main() {
  reset(need, 0x3f);
  REP(tar, 10) REP(i, 10) REP(j, 10) REP(k1, 11) REP(k2, 11) if ((k1 * i + k2 * j) % 10 == tar && (k1 || k2))
    chkmin(need[tar][i][j], k1 + k2 - 1);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  FOR(i, 1, n - 1) {
    int tar = (s[i + 1] - s[i] + 10) % 10;
    REP(j, 10) REP(k, 10) if (ans[j][k] != -1) {
      if (need[tar][j][k] < 1e9) ans[j][k] += need[tar][j][k];
      else ans[j][k] = -1;
    }
  }
  REP(i, 10) {
    REP(j, 10) printf("%d ", ans[i][j]);
    putchar('\n');
  }
}