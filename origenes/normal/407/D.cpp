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

const int maxn = 412;
const int maxa = 161234;

int n, m;
int a[maxn][maxn], f[maxn][maxn], last[maxn][maxa];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
  int ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) {
    FOR(r, j, m) {
      int l = r - j + 1;
      if (l == r) chkmax(f[l][l], last[l][a[i][l]]);
      else if (a[i][l] == a[i][r]) f[l][r] = i;
      else f[l][r] = max({f[l][r], f[l][r - 1], f[l + 1][r], last[r][a[i][l]], last[l][a[i][r]]});
      chkmax(ans, (i - f[l][r]) * (r - l + 1));
    }
    FOR(k, 1, m) last[k][a[i][k]] = i;
  }
  cout << ans;
}