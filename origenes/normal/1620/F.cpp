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
  vector<int> a(n), f(2 * n, n + 1), p(2 * n, -1);
  REP(i, n) cin >> a[i];
  f[0] = f[1] = -n;
  FOR(i, 1, n - 1) REP(x, 2) REP(y, 2) {
    int nxt[2] = {f[i * 2 - 2 + y], a[i - 1] * (2 * y - 1)};
    REP(j, 2) if (nxt[j] <= a[i] * (2 * x - 1) && nxt[1 - j] < f[i * 2 + x]) {
      f[i * 2 + x] = nxt[1 - j];
      p[i * 2 + x] = i * 2 - 2 + y;
    }
  }
  if (f[2 * n - 1] <= n) {
    cout << "YES\n";
    int now = 2 * n - 1;
    ROF(i, n - 1, 0) {
      if (now % 2 == 0) a[i] = -a[i];
      now = p[now];
    }
    REP(i, n) cout << a[i] << ' ';
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