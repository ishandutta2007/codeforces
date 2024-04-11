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
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  int d = 0;
  REP(i, m) {
    int b; cin >> b;
    d = gcd(d, b);
  }
  vector<ll> ans(2);
  REP(r, d) {
    vector<ll> f(2);
    f[0] = a[r], f[1] = -a[r];
    for (int i = r + d; i < n; i += d) {
      vector<ll> nf(2);
      nf[0] = max(f[0] + a[i], f[1] - a[i]);
      nf[1] = max(f[0] - a[i], f[1] + a[i]);
      swap(f, nf);
    }
    ans[0] += f[0];
    ans[1] += f[1];
  }
  cout << max(ans[0], ans[1]) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}