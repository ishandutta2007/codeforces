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
  string s; cin >> s;
  if (s[0] != '1' || s[n - 1] != '1') {
    cout << "NO\n";
    return;
  }
  int cnt = 0;
  REP(i, n) if (s[i] == '1') cnt++;
  if (cnt % 2 == 1) {
    cout << "NO\n";
    return;
  }
  int tot = cnt;
  vector<vector<char>> ans(2, vector<char>(n));
  bool f = true;
  REP(i, n) {
    if (s[i] == '1') {
      if (cnt > tot / 2) ans[0][i] = ans[1][i] = '(';
      else ans[0][i] = ans[1][i] = ')';
      cnt--;
    } else {
      ans[0][i] = '('; ans[1][i] = ')';
      if (f) swap(ans[0][i], ans[1][i]);
      f = !f;
    }
  }
  cout << "YES\n";
  REP(i, 2) {
    REP(j, n) cout << ans[i][j];
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