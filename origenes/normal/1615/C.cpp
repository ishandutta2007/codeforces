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
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << "0\n";
    return;
  }
  int odd[2] = {}, even[2] = {};
  REP(i, n) {
    if (s[i] != t[i]) even[s[i] - '0']++;
    else odd[s[i] - '0']++;
  }
  int ans = n + 1;
  if (odd[1] - odd[0] == 1 && (odd[0] + odd[1]) % 2 == 1) chkmin(ans, odd[0] + odd[1]);
  if (even[1] == even[0] && (even[0] + even[1]) % 2 == 0) chkmin(ans, even[0] + even[1]);
  if (ans == n + 1) ans = -1;
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