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
  vector<string> G(n);
  REP(i, n) cin >> G[i];
  int cx[3] = {}, co[3] = {};
  int k = 0;
  REP(i, n) REP(j, n) {
    if (G[i][j] == 'X') cx[(i + j) % 3]++, k++;
    if (G[i][j] == 'O') co[(i + j) % 3]++, k++;
  }
  REP(i, 3) REP(j, 3) if (i != j) {
    if (cx[i] + co[j] <= k / 3) {
      REP(x, n) REP(y, n) {
        if ((x + y) % 3 == i && G[x][y] == 'X') G[x][y] = 'O';
        if ((x + y) % 3 == j && G[x][y] == 'O') G[x][y] = 'X';
      }
      REP(x, n) cout << G[x] << '\n';
      return;
    }
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