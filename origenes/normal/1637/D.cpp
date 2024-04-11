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
  vector<int> a(n + 1), b(n + 1), c(n + 1);
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  FOR(i, 1, n) c[i] = c[i - 1] + a[i] + b[i];
  vector<int> f(10001, 1e9);
  f[0] = 0;
  FOR(i, 1, n) {
    vector<int> nf(10001, 1e9);
    REP(j, c[i - 1] + 1) {
      int sb = c[i - 1] - j;
      if (j > 10000 || sb > 10000 || sb < 0) continue;
      if (f[j] == 1e9) continue;
      int extra = (n - 1) * sqr(a[i]) + (n - 1) * sqr(b[i]);
      chkmin(nf[j + a[i]], f[j] + 2 * j * a[i] + 2 * sb * b[i] + extra);
      chkmin(nf[j + b[i]], f[j] + 2 * j * b[i] + 2 * sb * a[i] + extra);
    }
    swap(nf, f);
  }
  cout << *min_element(all(f)) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}