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
  vector<vector<int>> cnt(26, vector<int>(26));
  REP(i, n) {
    int a = s[i] - 'a', b = t[n - i - 1] - 'a';
    if (a > b) swap(a, b);
    cnt[a][b]++;
  }
  int bad = 0;
  REP(i, 26) {
    bad += cnt[i][i] & 1;
    FOR(j, i + 1, 25) if (cnt[i][j] % 2 == 1) {
      cout << "NO\n";
      return;
    }
  }
  if (bad > 1) cout << "NO\n";
  else cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}