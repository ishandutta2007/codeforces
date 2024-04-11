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
  string s[3];
  REP(i, 3) cin >> s[i];
  REP(i, 3) FOR(j, i + 1, 2) {
    char ch = 0;
    if (count(all(s[i]), '0') >= n && count(all(s[j]), '0') >= n) ch = '0';
    else if (count(all(s[i]), '1') >= n && count(all(s[j]), '1') >= n) ch = '1';
    if (!ch) continue;
    vector<char> ans;
    int x = 0, y = 0, cnt = 0;
    while (cnt < n) {
      while (x < 2 * n && s[i][x] != ch) {
        ans.eb(s[i][x]);
        x++;
      }
      while (y < 2 * n && s[j][y] != ch) {
        ans.eb(s[j][y]);
        y++;
      }
      cnt++;
      x++, y++;
      ans.eb(ch);
    }
    while (x < 2 * n) {
      ans.eb(s[i][x]);
      x++;
    }
    while (y < 2 * n) {
      ans.eb(s[j][y]);
      y++;
    }
    for (auto u : ans) cout << u;
    cout << '\n';
    return;
  }
  assert(0);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}