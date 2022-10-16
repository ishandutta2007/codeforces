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
const int MOD = 1e9 + 7;

int b[maxn], n, dp[maxn][maxn];
bool vis[maxn][maxn];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int dfs(int l, int r) {
  if (l > r) return 0;
  if (vis[l][r]) return dp[l][r];
  int &ret = dp[l][r];
  vis[l][r] = true;
  if (l == r) return ret = 1;
  FOR(i, l + 1, r) if (i == r || b[i + 1] > b[l + 1])
      ret = add(ret, mul(dfs(l + 1, i), dfs(i, r)));
  return ret;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", b + i);
  printf("%d", dfs(1, n));
}