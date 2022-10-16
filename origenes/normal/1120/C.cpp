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

const int maxn = 5123;

int n, a, b;
int f[maxn][maxn], dp[maxn];
char s[maxn];

int main() {
  scanf("%d%d%d", &n, &a, &b);
  scanf("%s", s + 1);
  FOR(i, 1, n) FOR(j, 1, n) if (s[i] == s[j]) f[i][j] = f[i - 1][j - 1] + 1;
  FOR(i, 1, n) {
    dp[i] = dp[i - 1] + a;
    FOR(j, 1, i - 1) {
      int pre = min(i - j, f[i][j]);
      chkmin(dp[i], dp[i - pre] + b);
    }
  }
  printf("%d", dp[n]);
}