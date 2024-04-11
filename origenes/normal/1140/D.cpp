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

const int maxn = 512;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dp[maxn][maxn], n;

ll dfs(int l, int r) {
  if (r - l < 2) return 0;
  if (dp[l][r] != inf) return dp[l][r];
  FOR(m, l + 1, r - 1) chkmin(dp[l][r], l * r * m + dfs(l, m) + dfs(m, r));
  return dp[l][r];
}

int main() {
  scanf("%d", &n);
  reset(dp, 0x3f);
  printf("%d", dfs(1, n));
}