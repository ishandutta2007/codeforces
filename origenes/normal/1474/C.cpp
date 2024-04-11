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
  int n;
  cin >> n;
  vector<int> a(2 * n);
  REP(i, 2 * n) cin >> a[i];
  sort(all(a), greater<>());
  FOR(i, 1, 2 * n - 1) {
    vector<pii> ans;
    ans.eb(a[0], a[i]);
    int tar = a[0];
    map<int, int> cnt;
    FOR(j, 1, 2 * n - 1) if (j != i) cnt[a[j]]++;
    FOR(j, 1, 2 * n - 1) if (cnt[a[j]] > 0) {
      int x = a[j], y = tar - x;
      cnt[x]--;
      if (cnt[y] > 0) cnt[y]--;
      else goto bad;
      ans.eb(x, y);
      tar = x;
    }
    bad:
    if (ans.size() == n) {
      cout << "YES\n";
      cout << a[0] + a[i] << '\n';
      for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}