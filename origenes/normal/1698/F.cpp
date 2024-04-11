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
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  if (a[0] != b[0] || a.back() != b.back()) {
    cout << "NO\n";
    return;
  }
  vector<pii> ops;
  FOR(i, 1, n - 2) if (a[i] != b[i]) {
    int pos = 0;
    FOR(j, i + 1, n - 1) if (a[j] == a[i - 1] && a[j - 1] == b[i]) {
      pos = j;
      break;
    }
    int p = 0;
    FOR(j, i, n - 2) FOR(k, j + 1, n - 1) {
      if (pos || a[j] != a[k]) continue;
      chkmax(p, j);
      for (; p < k; p++) if (a[p] == a[i - 1] && a[p + 1] == b[i]) {
        reverse(a.begin() + j, a.begin() + k + 1);
        ops.eb(j, k);
        pos = j + k - p;
        break;
      }
    }
    if (pos) {
      reverse(a.begin() + i - 1, a.begin() + pos + 1);
      ops.eb(i - 1, pos);
    } else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n" << size(ops) << '\n';
  for (auto [l, r] : ops) cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}