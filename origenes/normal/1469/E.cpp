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
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  int x = 1, pre = 0;
  while ((1 << x) < n) x++;
  chkmin(x, k);
  vector<int> cnt(1 << x);
  int now = 0, ALL = (1 << x) - 1;
  REP(i, k - x) pre += s[i] - '0';
  FOR(i, k - x, k - 1) {
    now = (now << 1) | (s[i] == '1');
    now &= ALL;
  }
  if (pre == k - x) cnt[now]++;
  FOR(i, k, n - 1) {
    now = (now << 1) | (s[i] == '1');
    now &= ALL;
    pre = pre - s[i - k] + s[i - x];
    if (pre == k - x) cnt[now]++;
  }
  REP(mask, 1 << x) {
    int ban = ALL ^ mask;
    if (!cnt[ban]) {
      cout << "YES\n";
      REP(i, k - x) cout << '0';
      ROF(i, x - 1, 0) cout << ((mask >> i) & 1);
      cout << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}