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
  vector<bool> occ(m + 1);
  int mx = 0, mn = 1e9;
  REP(i, n) {
    int a; cin >> a;
    occ[a] = true;
    chkmax(mx, a);
    chkmin(mn, a);
  }
  if (mx == mn) {
    cout << "0\n";
    return;
  }
  vector<int> f(mx + 1, 1e9), cnt(mx + 1);
  vector<bool> inq(mx + 1);
  set<int, greater<>> q;
  int ans = 1e9;
  ROF(j, mx, 1) {
    f[j] = j;
    if (occ[j]) {
      inq[j] = true;
      q.emplace(j);
      cnt[j]++;
    }
    for (int i = 2 * j; i <= mx; i += j) {
      if (occ[i]) cnt[f[i]]--;
      chkmin(f[i], f[i / j]);
      if (occ[i]) cnt[f[i]]++;
      if (occ[i] && cnt[f[i]] && !inq[f[i]]) {
        q.emplace(f[i]);
        inq[f[i]] = true;
      }
    }
    while (!q.empty() && cnt[*q.begin()] == 0) q.erase(q.begin());
    if (j <= mn) chkmin(ans, *q.begin() - j);
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