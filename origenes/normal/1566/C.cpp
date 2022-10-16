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
  int n;
  string s, t;
  cin >> n >> s >> t;
  int zero = -1, one = -1, ans = 0;
  REP(i, n) {
    bool z = s[i] == '0' || t[i] == '0', o = s[i] == '1' || t[i] == '1';
    if (z && o) {
      zero = one = -1;
      ans += 2;
    } else if (z) {
      if (one != -1) {
        ans += 2;
        zero = one = -1;
      } else {
        ans++;
        zero = i;
      }
    } else if (o) {
      if (zero != -1) {
        ans++;
        zero = one = -1;
      } else one = i;
    }
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