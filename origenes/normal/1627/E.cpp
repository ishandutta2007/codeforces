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
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> x(n + 1);
  FOR(i, 1, n) cin >> x[i];
  vector<int> a(k + 1), b(k + 1), c(k + 1), d(k + 1), h(k + 1);
  vector<vector<int>> st(n + 1), en(n + 1);
  FOR(i, 1, k) {
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> h[i];
    st[a[i]].eb(i);
    en[c[i]].eb(i);
  }
  d[0] = 1;
  vector<ll> f(k + 1, 1e18); f[0] = 0;
  en[1].eb(0);
  FOR(i, 1, n) {
    set<ll> l, r;
    sort(all(en[i]), [&](int x, int y) { return d[x] < d[y]; });
    for (auto j : en[i]) if (f[j] != 1e18) r.emplace(d[j] * x[i] + f[j]);
    sort(all(st[i]), [&](int x, int y) { return b[x] < b[y]; });
    int p = 0;
    for (auto nj : st[i]) {
      int pos = b[nj];
      while (p < size(en[i]) && d[en[i][p]] <= pos) {
        int j = en[i][p];
        if (f[j] != 1e18) {
          r.erase(d[j] * x[i] + f[j]);
          l.emplace(f[j] - d[j] * x[i]);
        }
        p++;
      }
      if (!l.empty()) chkmin(f[nj], *l.begin() + pos * x[i] - h[nj]);
      if (!r.empty()) chkmin(f[nj], *r.begin() - pos * x[i] - h[nj]);
    }
  }
  ll ans = 1e18;
  for (auto i : en[n]) if (f[i] != 1e18) chkmin(ans, f[i] + (m - d[i]) * x[n]);
  if (ans == 1e18) cout << "NO ESCAPE\n";
  else cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}