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
  ll a, b, c;
  cin >> n >> a >> b >> c;
  string s; cin >> s;
  int cnt00 = 0, cnt11 = 0, cnt101 = 0;
  REP(i, n - 1) {
    if (s[i] == '0' && s[i + 1] == '0') cnt00++;
    if (s[i] == '1' && s[i + 1] == '1') cnt11++;
  }
  int mn = min(cnt00, cnt11);
  cnt00 -= mn, cnt11 -= mn;
  ll ans = (a + b) * mn;
  if (cnt00) {
    ans += a;
    cnt00--;
  } else if (cnt11) {
    ans += b;
    cnt11--;
  }
  if (b > c) {
    vector<int> segs;
    for (int l = 0; l < n; ) {
      int r = l;
      while (r < n && s[r] == '0') r++;
      if (l && r != n && r > l) segs.eb(r - l - 1);
      l = r + 1;
    }
    sort(all(segs));
    for (auto len : segs) {
      if (mn >= len) {
        mn -= len;
        cnt101++;
      } else break;
    }
    int extra = min(cnt11, (s[0] == '0') + (s[n - 1] == '0'));
    ans += (b - c) * (cnt101 + extra);
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