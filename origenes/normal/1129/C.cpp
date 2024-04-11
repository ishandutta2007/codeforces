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

const int maxn = 3123;
const int MOD = 1e9 + 7;

int n, lis[maxn], dp[maxn][maxn], f[maxn], pre[maxn];

inline int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}

inline bool check(int now) {
  if (!lis[now - 3] && !lis[now - 2] && lis[now - 1] && lis[now]) return true;
  if (!lis[now - 3] && lis[now - 2] && !lis[now - 1] && lis[now]) return true;
  return lis[now - 3] && lis[now - 2] && lis[now - 1];
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", lis + i);
  FOR(i, 1, n) {
    dp[i][i - 1] = 1;
    FOR(j, i, n) FOR(k, max(0, j - 4), j - 1) {
        if (k == j - 4 && check(j)) continue;
        dp[i][j] = add(dp[i][j], dp[i][k]);
      }
  }
  FOR(i, 1, n) pre[i] = i;
  FOR(i, 1, n) {
    f[i] = i - 1, f[i - 1] = i - 2;
    FOR(j, i + 1, n) {
      f[j] = f[j - 1];
      while (f[j] >= i - 1 && lis[f[j] + 1] != lis[j]) f[j] = f[f[j]];
      f[j]++;
      chkmin(pre[j], j - f[j] + i - 1);
    }
  }
  int ans = 0;
  FOR(j, 1, n) {
    FOR(i, 1, j) if (pre[j] >= i)
        ans = add(ans, dp[i][j]);
    printf("%d\n", ans);
  }
}