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

int solve(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();
  if (n == 0 || m == 0) return 0;
  vector<int> suf(n + 1);
  ROF(i, n - 1, 0) {
    suf[i] = suf[i + 1];
    auto it = lower_bound(all(b), a[i]);
    if (it != b.end() && *it == a[i]) suf[i]++;
  }
  int ans = suf[0], j = 0;
  a.eb(2e9);
  REP(i, n) {
    while (j < m && b[j] < a[i]) j++;
    while (j < m && b[j] < a[i + 1]) {
      auto it = lower_bound(all(b), b[j] - i);
      chkmax(ans, int(b.begin() + j - it) + 1 + suf[i + 1]);
      j++;
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> b[i];
  vector<int> al, ar;
  vector<int> bl, br;
  REP(i, n) {
    if (a[i] < 0) al.eb(-a[i]);
    else ar.eb(a[i]);
  }
  REP(i, m) {
    if (b[i] < 0) bl.eb(-b[i]);
    else br.eb(b[i]);
  }
  reverse(all(al)); reverse(all(bl));
  cout << solve(al, bl) + solve(ar, br) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}