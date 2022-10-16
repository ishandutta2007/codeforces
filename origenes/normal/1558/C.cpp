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

const int maxn = 2123;

int a[maxn];

void solve() {
  int n; cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) if (a[i] % 2 != i % 2) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans;
  for (int i = n; i > 1; i -= 2) {
    int x, y;
    for (x = 1; x <= i; x++) if (a[x] == i) break;
    ans.eb(x);
    reverse(a + 1, a + x + 1);
    for (y = 1; y <= i; y++) if (a[y] == i - 1) break;
    ans.eb(y - 1);
    reverse(a + 1, a + y);
    ans.eb(y + 1);
    reverse(a + 1, a + y + 2);
    ans.eb(3);
    reverse(a + 1, a + 4);
    ans.eb(i);
    reverse(a + 1, a + i + 1);
  }
  cout << ans.size() << '\n';
  for (auto p : ans) cout << p << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}