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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m + 1));
  map<int, int> to;
  REP(i, n) {
    FOR(j, 1, m) {
      cin >> a[i][j];
      if (!to.count(a[i][j])) {
        int x = size(to);
        to[a[i][j]] = x;
      }
      a[i][j] = to[a[i][j]];
    }
    cin >> a[i][0];
  }
  sort(all(a));
  vector<vector<int>> occ(size(to));
  REP(i, n) FOR(j, 1, m) occ[a[i][j]].eb(i);
  vector<int> idx(size(to), -1);
  vector<bitset<100001>> bs;
  REP(i, size(to)) if (size(occ[i]) > 500) {
    idx[i] = size(bs);
    bitset<100001> b;
    b.set();
    for (auto j : occ[i]) b[j] = 0;
    bs.eb(b);
  }
  int ans = 2e9 + 5;
  REP(i, n) {
    bitset<100001> cur; cur.set();
    FOR(j, 1, m) {
      int x = a[i][j];
      if (idx[x] != -1) cur &= bs[idx[x]];
      else for (auto k : occ[x]) cur[k] = 0;
    }
    int other = cur._Find_first();
    if (other < n) chkmin(ans, a[i][0] + a[other][0]);
  }
  if (ans == 2e9 + 5) ans = -1;
  cout << ans;
}