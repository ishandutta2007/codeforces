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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n * m);
  REP(i, n * m) cin >> a[i];
  map<int, int> lo, hi, cnt;
  auto b = a;
  sort(all(b));
  REP(i, n * m) {
    if (!lo.count(b[i])) lo[b[i]] = i;
    hi[b[i]] = i;
  }
  int ans = 0;
  vector<vector<bool>> f(n, vector<bool>(m));
  REP(i, n * m) {
    int mn_row = lo[a[i]] / m, mn_col = lo[a[i]] % m;
    int mx_row = hi[a[i]] / m, mx_col = hi[a[i]] % m;
    if (mn_row == mx_row) {
       REP(j, mn_col) ans += f[mn_row][j];
       f[mn_row][mx_col - cnt[a[i]]] = true;
       cnt[a[i]]++;
    } else {
      if (cnt[a[i]] < m - mn_col) {
        REP(j, mn_col) ans += f[mn_row][j];
        f[mn_row][m - 1 - cnt[a[i]]] = true;
        cnt[a[i]]++;
      } else {
        int idx = cnt[a[i]] - m + mn_col;
        int r = idx / m + mn_row + 1, c = -idx % m;
        if (r != mx_row) c += m - 1;
        else c += mx_col;
        f[r][c] = true;
        cnt[a[i]]++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}