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
  int n; cin >> n;
  vector<int> a(n + 1), f(8192, n + 1), last(5001, -1), pre(n + 1, -1);
  FOR(i, 1, n) cin >> a[i];
  pre[0] = last[0] = f[0] = 0;
  FOR(i, 1, n) {
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  set<pii> q; q.emplace(0, 0);
  FOR(i, 1, n) {
    map<int, int> del, inc;
    for (auto it = q.rbegin(); it != q.rend(); ++it) {
      auto [pos, u] = *it;
      if (pos <= pre[i]) break;
      if (a[f[u]] >= a[i]) continue;
      int v = u ^ a[i];
      if (f[v] == n + 1 || a[f[v]] > a[i]) {
        inc[v] = i;
        if (!del.count(v)) del[v] = f[v];
        f[v] = i;
      }
    }
    for (auto [u, pos] : del) q.erase(mp(pos, u));
    for (auto [u, pos] : inc) q.emplace(pos, u);
  }
  vector<int> ans;
  REP(i, 8192) if (f[i] <= n) ans.eb(i);
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
}