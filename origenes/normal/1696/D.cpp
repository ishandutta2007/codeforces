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
  vector<int> a(n), lmn(n), lmx(n), rmn(n), rmx(n);
  REP(i, n) cin >> a[i];
  lmn[0] = lmx[0] = 0;
  FOR(i, 1, n - 1) {
    if (a[i] < a[lmn[i - 1]]) lmn[i] = i;
    else lmn[i] = lmn[i - 1];
    if (a[i] > a[lmx[i - 1]]) lmx[i] = i;
    else lmx[i] = lmx[i - 1];
  }
  rmn[n - 1] = rmx[n - 1] = n - 1;
  ROF(i, n - 2, 0) {
    if (a[i] < a[rmn[i + 1]]) rmn[i] = i;
    else rmn[i] = rmn[i + 1];
    if (a[i] > a[rmx[i + 1]]) rmx[i] = i;
    else rmx[i] = rmx[i + 1];
  }
  int st = min_element(all(a)) - a.begin(), ans = 0;
  for (int i = st; i; i = lmn[i]) {
    ans++;
    i = lmx[i];
    if (i == 0) break;
    ans++;
  }
  for (int i = st; i != n - 1; i = rmn[i]) {
    ans++;
    i = rmx[i];
    if (i == n - 1) break;
    ans++;
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