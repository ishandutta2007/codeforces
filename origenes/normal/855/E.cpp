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

const int maxn = 65;

ll dp[11][1 << 10][maxn];
bool vis[11][1 << 10][maxn];

ll dfs(int b, int mask, int n) {
  if (!n) return !mask;
  if (vis[b][mask][n]) return dp[b][mask][n];
  vis[b][mask][n] = true;
  ll &ret = dp[b][mask][n];
  REP(i, b) ret += dfs(b, mask ^ (1 << i), n - 1);
  return ret;
}

int a[maxn];

int conv(int b, ll x) {
  int ret = 0;
  while (x) {
    a[ret++] = x % b;
    x /= b;
  }
  return ret;
}

ll solve(int b, ll upp) {
  if (!upp) return 0;
  reset(a, 0);
  int n = conv(b, upp), mask = 0;
  ll ret = 0;
  FOR(i, 1, n - 1) FOR(j, 1, b - 1) ret += dfs(b, 1 << j, i - 1);
  ROF(i, n - 1, 0) {
    FOR(j, 1, a[i] - 1) ret += dfs(b, mask ^ (1 << j), i);
    if (i != n - 1 && a[i]) ret += dfs(b, mask ^ 1, i);
    mask ^= 1 << a[i];
  }
  return ret + !mask;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int b;
    ll l, r;
    scanf("%d%lld%lld", &b, &l, &r);
    printf("%lld\n", solve(b, r) - solve(b, l - 1));
  }
}