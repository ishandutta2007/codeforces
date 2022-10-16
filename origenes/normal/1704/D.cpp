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
  vector<vector<int>> c(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> c[i][j];
  ll v1 = -1, v2 = -1;
  vector<int> cnt[2] = {};
  REP(i, n) {
    ll now = 0;
    REP(j, m) now += c[i][j] * ll(j);
    if (now == v1 || v1 == -1) {
      v1 = now;
      cnt[0].eb(i);
    } else {
      v2 = now;
      cnt[1].eb(i);
    }
  }
  if (size(cnt[0]) == 1) {
    swap(cnt[0], cnt[1]);
    swap(v1, v2);
  }
  cout << cnt[1][0] + 1 << ' ' << v2 - v1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}