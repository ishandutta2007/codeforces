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
  string s;
  cin >> s;
  int fi = 0, se = 0, ans = 10;
  REP(i, 10) {
    if (s[i] == '1') {
      if (i & 1) se++;
      else fi++;
    } else if (i % 2 == 0 && s[i] == '?') fi++;
    if (fi > se + (10 - i) / 2) chkmin(ans, i + 1);
  }
  fi = se = 0;
  REP(i, 10) {
    if (s[i] == '1') {
      if (i & 1) se++;
      else fi++;
    } else if (i % 2 == 1 && s[i] == '?') se++;
    if (se > fi + (9 - i) / 2) chkmin(ans, i + 1);
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