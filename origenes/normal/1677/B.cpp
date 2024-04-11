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
  int n, m;
  cin >> n >> m;
  string s; cin >> s;
  vector<vector<int>> f(n, vector<int>(m));
  vector<bool> col(m);
  int balance = 0;
  REP(i, n) REP(j, m) {
    int idx = i * m + j;
    if (s[idx] == '1') balance = m;
    f[i][j] = balance > 0;
    if (i > 0) f[i][j] += f[i - 1][j];
    balance--;
  }
  int cnt = 0;
  REP(i, n) REP(j, m) {
    int idx = i * m + j;
    if (s[idx] == '1' && !col[j]) {
      cnt++;
      col[j] = true;
    }
    cout << cnt + f[i][j] << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}