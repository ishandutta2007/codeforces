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

const int maxn = 212;

int n;
ll c[maxn][maxn], f[maxn][maxn], s[maxn][maxn];
int idx[maxn][maxn], ans[maxn];

void dfs(int l, int r) {
  int p = idx[l][r];
  if (l < p) {
    dfs(l, p - 1);
    ans[idx[l][p - 1]] = p;
  }
  if (p < r) {
    dfs(p + 1, r);
    ans[idx[p + 1][r]] = p;
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) FOR(j, 1, n) cin >> c[i][j];
  FOR(i, 1, n) {
    ll tot = accumulate(c[i] + 1, c[i] + n + 1, 0LL);
    FOR(j, 1, i) {
      s[j][i] = s[j][i - 1] + tot;
      f[j][i] = 1e18;
      FOR(k, j, i) s[j][i] -= 2 * c[k][i];
    }
  }
  FOR(i, 1, n) {
    f[i][i] = 0;
    idx[i][i] = i;
  }
  FOR(k, 2, n) FOR(i, 1, n) {
    int j = i + k - 1;
    FOR(p, i, j) {
      ll now = f[i][p - 1] + f[p + 1][j] + s[i][p - 1] + s[p + 1][j];
      if (f[i][j] > now) {
        f[i][j] = now;
        idx[i][j] = p;
      }
    }
  }
  dfs(1, n);
  FOR(i, 1, n) cout << ans[i] << ' ';
}