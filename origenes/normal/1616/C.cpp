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
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  if (n == 1) {
    cout << "0\n";
    return;
  }
  int ans = 2;
  REP(i, n) FOR(j, i + 1, n - 1) {
    int D = j - i, inc = a[j] - a[i];
    FOR(d, 1, D) if (D % d == 0 && inc % (D / d) == 0) {
      int in = inc / (D / d), now = 2, need = in;
      for (int k = j + d; k < n; k += d) {
        if (a[k] - a[j] == need) now++;
        need += in;
      }
      chkmax(ans, now);
    }
  }
  cout << n - ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}