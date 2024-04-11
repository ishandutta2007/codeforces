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
  int x, y;
  bool good = true;
  for (int i = 0; i <= n - 1 - i; i++) if (a[i] != a[n - 1 - i]) {
    good = false;
    x = a[i];
    y = a[n - 1 - i];
    break;
  }
  if (good) {
    cout << "YES\n";
    return;
  }
  vector<int> b;
  REP(i, n) if (a[i] != x) b.eb(a[i]);
  int m = b.size();
  good = true;
  for (int i = 0; i <= m - 1 - i; i++) if (b[i] != b[m - 1 - i]) {
    good = false;
    break;
  }
  if (good) {
    cout << "YES\n";
    return;
  }
  b.clear();
  REP(i, n) if (a[i] != y) b.eb(a[i]);
  m = b.size(); good = true;
  for (int i = 0; i <= m - 1 - i; i++) if (b[i] != b[m - 1 - i]) {
    good = false;
    break;
  }
  if (good) {
    cout << "YES\n";
    return;
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