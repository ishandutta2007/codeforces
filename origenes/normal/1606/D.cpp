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
  vector<vector<int>> a(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> a[i][j];
  vector<vector<int>> pmn(n, vector<int>(m));
  auto pmx = pmn, smn = pmn, smx = pmn;
  REP(i, n) pmn[i][0] = pmx[i][0] = a[i][0];
  REP(i, n) FOR(j, 1, m - 1) {
    pmn[i][j] = min(pmn[i][j - 1], a[i][j]);
    pmx[i][j] = max(pmx[i][j - 1], a[i][j]);
  }
  REP(i, n) smn[i][m - 1] = smx[i][m - 1] = a[i][m - 1];
  REP(i, n) ROF(j, m - 2, 0) {
    smn[i][j] = min(smn[i][j + 1], a[i][j]);
    smx[i][j] = max(smx[i][j + 1], a[i][j]);
  }
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int x, int y) { return a[x][0] < a[y][0]; });
  REP(j, m - 1) {
    vector<int> l_red(n), l_blue(n), r_red(n), r_blue(n);
    REP(i, n - 1) {
      int idx = id[i];
      if (i == 0) l_blue[i] = pmx[idx][j];
      else l_blue[i] = max(l_blue[i - 1], pmx[idx][j]);
      if (i == 0) r_blue[i] = smn[idx][j + 1];
      else r_blue[i] = min(r_blue[i - 1], smn[idx][j + 1]);
    }
    ROF(i, n - 1, 1) {
      int idx = id[i];
      if (i == n - 1) l_red[i - 1] = pmn[idx][j];
      else l_red[i - 1] = min(l_red[i], pmn[idx][j]);
      if (i == n - 1) r_red[i - 1] = smx[idx][j + 1];
      else r_red[i - 1] = max(r_red[i], smx[idx][j + 1]);
    }
    REP(i, n - 1) {
      if (l_red[i] > l_blue[i] && r_red[i] < r_blue[i]) {
        cout << "YES\n";
        vector<char> colour(n, 'R');
        REP(cur, i + 1) colour[id[cur]] = 'B';
        for (auto x : colour) cout << x;
        cout << ' ' << j + 1 << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}