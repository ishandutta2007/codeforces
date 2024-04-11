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
  vector<vector<int>> f(n + 1, vector<int>(m + 1));
  FOR(i, 1, n) {
    string s; cin >> s;
    REP(j, m) f[i][j + 1] = s[j] - '0';
  }
  FOR(i, 1, n) FOR(j, 1, m) f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
  int ans = n * m;
  auto sum = [&](int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
  };
  FOR(u, 1, n) FOR(d, u + 4, n) {
    int l = 1;
    auto get_cost = [&](int l, int r) {
      int ret = sum(u + 1, l + 1, d - 1, r - 1);
      ret += (r - l - 1) - sum(u, l + 1, u, r - 1);
      ret += (r - l - 1) - sum(d, l + 1, d, r - 1);
      ret += (d - u - 1) - sum(u + 1, l, d - 1, l);
      ret += (d - u - 1) - sum(u + 1, r, d - 1, r);
      return ret;
    };
    chkmin(ans, get_cost(1, 4));
    FOR(r, 5, m) {
      int a1 = get_cost(l, r), a2 = get_cost(r - 3, r);
      chkmin(ans, a1); chkmin(ans, a2);
      if (a2 < a1) l = r - 3;
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