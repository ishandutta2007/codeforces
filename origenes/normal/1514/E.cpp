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
  int n; cin >> n;
  vector<vector<bool>> G(n, vector<bool>(n));
  vector<int> id(n), need(n + 1);
  iota(all(id), 0);
  stable_sort(all(id), [](int u, int v) {
    cout << "1 " << u << ' ' << v << endl;
    int res; cin >> res;
    return res == 1;
  });
  need[n] = n - 1;
  ROF(i, n - 1, 0) {
    need[i] = min(need[i + 1], i - 1);
    while (need[i] >= 0) {
      cout << 2 << ' ' << id[i] << ' ' << need[i] + 1;
      REP(j, need[i] + 1) cout << ' ' << id[j];
      cout << endl;
      int res; cin >> res;
      if (res == 0) break;
      need[i]--;
    }
  }
  int j = n - 1, mn = need[n - 1];
  for (int i = n - 1; i >= 0; i = j, mn = need[max(i, 0)]) {
    while (j > mn) chkmin(mn, need[j--]);
    FOR(x, j + 1, i) REP(y, i + 1) G[id[y]][id[x]] = true;;
  }
  cout << 3 << endl;
  REP(x, n) {
    REP(y, n) cout << G[x][y];
    cout << endl;
  }
  int x; cin >> x;
  assert(x == 1);
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}