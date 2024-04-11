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
  int cr = 0, cb = 0;
  for (auto ch : s) {
    if (ch == 'R') cr++;
    else cb++;
  }
  if (cr != cb) {
    if (cr > cb) cout << "Alice\n";
    else cout << "Bob\n";
    return;
  }
  vector<int> sg(n + 1);
  FOR(i, 2, n) {
    if (i <= 2000) {
      vector<bool> vis(n + 2);
      REP(j, i - 1) vis[sg[j] ^ sg[i - j - 2]] = true;
      sg[i] = 0;
      while (vis[sg[i]]) sg[i]++;
    } else sg[i] = sg[i - 34];
  }
  int sum = 0;
  REP(i, n) {
    int j = 1;
    while (i < n - 1 && s[i] != s[i + 1]) i++, j++;
    sum ^= sg[j];
  }
  if (sum) cout << "Alice\n";
  else cout << "Bob\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}