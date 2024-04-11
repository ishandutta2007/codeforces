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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n, vector<int>(n));
  vector<tuple<int, int, int>> q;
  REP(i, n) REP(j, n) {
    cin >> v[i][j];
    q.eb(v[i][j], i, j);
  }
  sort(all(q));
  vector<vector<char>> f(n, vector<char>(n, 'G'));
  auto [_, x, y] = q.back(); q.pop_back();
  f[x][y] = 'M';
  int l = x - y, r = x - y, u = x + y, d = x + y;
  while (!q.empty()) {
    tie(_, x, y) = q.back(); q.pop_back();
    if (abs(x - y - l) <= k && abs(x - y - r) <= k && abs(x + y - u) <= k && abs(x + y - d) <= k) {
      f[x][y] = 'M';
      chkmin(l, x - y);
      chkmax(r, x - y);
      chkmin(u, x + y);
      chkmax(d, x + y);
    }
  }
  REP(i, n) {
    REP(j, n) cout << f[i][j];
    cout << '\n';
  }
}