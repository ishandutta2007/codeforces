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
  vector<int> ans(m);
  vector<vector<int>> f(m);
  vector<int> cnt(n + 1);
  REP(i, m) {
    int k; cin >> k;
    f[i].resize(k);
    REP(j, k) cin >> f[i][j];
    ans[i] = f[i][0];
    cnt[ans[i]]++;
  }
  int d = 0, b = 0;
  FOR(i, 1, n) if (cnt[i] > (m + 1) / 2) {
    d = cnt[i] - (m + 1) / 2;
    b = i;
    break;
  }
  if (d > 0) {
    REP(i, m) if (ans[i] == b) {
      if (f[i].size() > 1) {
        ans[i] = f[i].back();
        if (!--d) break;
      }
    }
  }
  if (d > 0) cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
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