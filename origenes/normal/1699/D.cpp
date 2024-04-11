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
  vector<int> a(n), cnt(n + 1), f(n + 1);
  REP(i, n) cin >> a[i];
  int mx = 0;
  f[0] = 1;
  REP(i, n - 1) {
    if (++cnt[a[i]] > mx) mx = cnt[a[i]];
    if (i % 2 == 1 && mx <= (i + 1) / 2) f[i + 1] = 1;
  }
  FOR(i, 1, n - 1) {
    fill(all(cnt), 0);
    mx = 0;
    if (a[i - 1] == a[i] && f[i - 1]) chkmax(f[i], f[i - 1] + 1);
    ROF(j, i - 1, 1) {
      if (++cnt[a[j]] > mx) mx = cnt[a[j]];
      if ((i - j) % 2 == 0 && mx <= (i - j) / 2 && a[i] == a[j - 1] && f[j - 1]) chkmax(f[i], f[j - 1] + 1);
    }
  }
  fill(all(cnt), 0);
  mx = 0;
  int ans = f[n - 1];
  ROF(j, n - 1, 1) {
    if (++cnt[a[j]] > mx) mx = cnt[a[j]];
    if ((n - j) % 2 == 0 && mx <= (n - j) / 2 && f[j - 1]) chkmax(ans, f[j - 1]);
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}