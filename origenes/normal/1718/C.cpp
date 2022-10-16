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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), facs;
  FOR(i, 1, n) cin >> a[i];
  int tmp = n;
  FOR(i, 2, tmp) if (tmp % i == 0) {
    facs.eb(n / i);
    while (tmp % i == 0) tmp /= i;
  }
  vector<vector<ll>> f(size(facs), vector<ll>(n + 1));
  multiset<ll> s;
  REP(i, size(facs)) {
    FOR(j, 1, n) f[i][j % facs[i]] += a[j];
    REP(j, facs[i]) s.emplace(facs[i] * f[i][j]);
  }
  cout << *s.rbegin() << '\n';
  while (q--) {
    int p, x;
    cin >> p >> x;
    REP(i, size(facs)) {
      s.erase(s.find(facs[i] * f[i][p % facs[i]]));
      f[i][p % facs[i]] += x - a[p];
      s.emplace(facs[i] * f[i][p % facs[i]]);
    }
    a[p] = x;
    cout << *s.rbegin() << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}