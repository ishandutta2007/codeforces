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
  int cnt = 0;
  vector<int> a;
  REP(i, n) {
    int x; cin >> x;
    if (x == 0) cnt++;
    else a.eb(x);
  }
  REP(i, n - 1) {
    vector<int> b;
    int nc = max(cnt - 1, 0);
    if (!a.empty() && cnt) b.eb(a[0]);
    FOR(j, 1, int(size(a)) - 1) {
      int d = a[j] - a[j - 1];
      if (d == 0) nc++;
      else b.eb(d);
    }
    sort(all(b));
    swap(a, b);
    cnt = nc;
  }
  if (cnt > 0) cout << "0\n";
  else cout << a[0] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}