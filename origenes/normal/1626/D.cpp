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
  vector<int> cnt(n + 1), pre(n + 1), suf(n + 1);
  REP(i, n) {
    int a; cin >> a;
    cnt[a]++;
  }
  int tot = 0;
  FOR(i, 1, n) {
    FOR(j, tot, tot + cnt[i] - 1) pre[j] = tot;
    tot += cnt[i];
  }
  tot = 0;
  ROF(i, n, 1) {
    FOR(j, tot, tot + cnt[i] - 1) suf[j] = tot;
    tot += cnt[i];
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i <<= 1) for (int j = 1; j <= n; j <<= 1) {
    int x = pre[i], y = suf[j], z = 1;
    while (z < n - x - y) z <<= 1;
    chkmin(ans, i + j + z);
  }
  cout << ans - n << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}