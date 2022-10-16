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
  int u, v; cin >> u >> v;
  int cnt[2][30] = {};
  ROF(i, 29, 0) cnt[0][i] = (u >> i) & 1;
  ROF(i, 29, 0) cnt[1][i] = (v >> i) & 1;
  REP(j, 2) FOR(i, 1, 29) cnt[j][i] += cnt[j][i - 1];
  ROF(i, 29, 0) if (cnt[1][i] > cnt[0][i]) {
    cout << "NO\n";
    return;
  }
  if (v < u) cout << "NO\n";
  else cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int q; cin >> q;
  while (q--) solve();
}