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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(n));
  REP(i, n) REP(j, n) {
    cin >> a[i][j];
    a[i][j]--;
  }
  string op; cin >> op;
  int x = 0, y = 0, z = 0, dx = 0, dy = 1, dz = 2;
  REP(i, m) {
    switch (op[i]) {
      case 'L':
        y--;
        break;
      case 'R':
        y++;
        break;
      case 'U':
        x--;
        break;
      case 'D':
        x++;
        break;
      case 'I':
        swap(y, z);
        swap(dy, dz);
        break;
      case 'C':
        swap(x, z);
        swap(dx, dz);
    }
  }
  vector<vector<int>> ans(n, vector<int>(n));
  REP(i, n) REP(j, n) {
    vector<int> v = {i, j, a[i][j]};
    ans[((v[dx] + x) % n + n) % n][((v[dy] + y) % n + n) % n] = ((v[dz] + z) % n + n) % n + 1;
  }
  REP(i, n) {
    REP(j, n) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}