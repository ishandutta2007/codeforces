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

const int maxn = 112345;

int n, q;
int a[maxn], nxt[maxn], f[maxn][18];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> q;
  FOR(i, 1, n) cin >> a[i];
  reset(f, 0x3f);
  FOR(i, 1, n + 1) f[i][0] = n + 1;
  FOR(i, 1, 1e5) nxt[i] = n + 1;
  ROF(i, n, 1) {
    int x = a[i];
    for (int j = 2; sqr(j) <= x; j++) if (x % j == 0) {
      chkmin(f[i][0], nxt[j]);
      while (x % j == 0) x /= j;
      nxt[j] = i;
    }
    if (x > 1) {
      chkmin(f[i][0], nxt[x]);
      nxt[x] = i;
    }
    chkmin(f[i][0], f[i + 1][0]);
  }
  ROF(i, n, 1) FOR(j, 1, 17) {
    if (f[i][j - 1] > n) break;
    f[i][j] = f[f[i][j - 1]][j - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = 1;
    ROF(i, 17, 0) if (f[l][i] <= r) {
      l = f[l][i];
      ans += 1 << i;
    }
    cout << ans << '\n';
  }
}