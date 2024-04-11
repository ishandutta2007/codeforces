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
  string s[2]; cin >> s[0] >> s[1];
  int st, en;
  for (st = 0; s[0][st] == '.' && s[1][st] == '.'; st++);
  for (en = n - 1; s[0][en] == '.' && s[1][en] == '.'; en--);
  vector<vector<int>> f(n, vector<int>(2, 1e9));
  f[st][0] = s[1][st] == '*'; f[st][1] = s[0][st] == '*';
  FOR(i, st, en - 1) REP(j, 2) {
    chkmin(f[i + 1][j], f[i][j] + 1 + (s[1 - j][i + 1] == '*'));
    chkmin(f[i + 1][j], f[i][1 - j] + 2);
  }
  cout << min(f[en][0], f[en][1]) << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}