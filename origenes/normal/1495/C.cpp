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

const int maxn = 512;

int n, m;
string s[maxn];

void solve() {
  cin >> n >> m;
  int strike = 2;
  if (n % 3 == 1) strike = 1;
  FOR(i, 1, n) cin >> s[i];
  for (int i = strike; i <= n; i += 3) REP(j, m) s[i][j] = 'X';
  for (int i = strike + 3; i <= n; i += 3) {
    if (m >= 2 && (s[i - 2][1] == 'X' || s[i - 1][1] == 'X')) s[i - 2][1] = s[i - 1][1] = 'X';
    else s[i - 2][0] = s[i - 1][0] = 'X';
  }
  FOR(i, 1, n) cout << s[i] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}