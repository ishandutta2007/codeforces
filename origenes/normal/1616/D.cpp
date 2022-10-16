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
  int n, x;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  cin >> x;
  REP(i, n) a[i] -= x;
  vector<int> sel(n, 1);
  FOR(i, 1, n - 1) {
    if (sel[i - 1] && a[i] + a[i - 1] < 0) sel[i] = 0;
    if (i >= 2 && sel[i - 1] && sel[i - 2] && a[i] + a[i - 1] + a[i - 2] < 0) sel[i] = 0;
  }
  cout << accumulate(all(sel), 0) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}