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

const int maxn = 20;

bool vis[maxn][3][2];
ll dp[maxn][3][2];
int s[maxn], n;

void conv(ll up) {
  n = 0;
  while (up) {
    s[n++] = up % 10;
    up /= 10;
  }
  reverse(s, s + n);
}

ll dfs(int pos, int cnt, bool small) {
  if (cnt == 3 || pos == n) return 1;
  if (vis[pos][cnt][small]) return dp[pos][cnt][small];
  vis[pos][cnt][small] = true;
  ll &ret = dp[pos][cnt][small];
  if (small) {
    ret += dfs(pos + 1, cnt, true);
    FOR(i, 1, 9) ret += dfs(pos + 1, cnt + 1, true);
  } else {
    if (s[pos]) {
      ret += dfs(pos + 1, cnt, true);
      FOR(i, 1, s[pos]) ret += dfs(pos + 1, cnt + 1, i != s[pos]);
    } else ret += dfs(pos + 1, cnt, false);
  }
  return ret;
}

ll solve(ll now) {
  if (!now) return 1;
  conv(now);
  reset(vis, 0);
  reset(dp, 0);
  return dfs(0, 0, false);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ll hi, lo;
    scanf("%lld%lld", &lo, &hi);
    lo--;
    printf("%lld\n", solve(hi) - solve(lo));
  }
}