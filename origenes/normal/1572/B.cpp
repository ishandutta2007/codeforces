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
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  if (count(all(a), 1) % 2 == 1) {
    cout << "NO\n";
    return;
  }
  if (count(all(a), 1) == 0) {
    cout << "YES\n0\n";
    return;
  }
  vector<pii> gaps;
  int last = -1;
  REP(i, n) if (a[i]) {
    if (last == -1) last = i;
    else {
      gaps.eb(last, i);
      last = -1;
    }
  }
  vector<int> ans;
  auto solve = [&](int l, int r) {
    if ((r - l) % 2 == 1 && (l == 0 || a[l - 1]) && (r == n - 1 || a[r + 1])) return false;
    if ((r - l) % 2 == 1) {
      for (int i = l; i + 2 < r; i += 2) ans.eb(i);
      if (l && !a[l - 1]) {
        for (int i = l - 1; i < r; i += 2) ans.eb(i);
      } else {
        for (int i = r - 1; i >= l; i -= 2) ans.eb(i);
      }
    } else {
      for (int i = l; i + 2 < r; i += 2) ans.eb(i);
      for (int i = r - 2; i >= l; i -= 2) ans.eb(i);
    }
    a[l] = a[r] = 0;
    return true;
  };
  bool ok = false;
  REP(i, int(gaps.size())) if (solve(gaps[i]._1, gaps[i]._2)) {
    ok = true;
    FOR(j, i + 1, int(gaps.size()) - 1) solve(gaps[j]._1, gaps[j]._2);
    ROF(j, i - 1, 0) solve(gaps[j]._1, gaps[j]._2);
    break;
  }
  if (ok) {
    cout << "YES\n" << ans.size() << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
  } else cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}