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

const int maxn = 60;

ll f[maxn];

void solve() {
  ll k; cin >> k;
  vector<int> ans;
  ROF(i, 59, 1) while (k >= f[i]) {
    ans.eb(1);
    REP(j, i - 1) ans.eb(0);
    k -= f[i];
  }
  if (k > 0 || ans.size() > 2000) {
    cout << "-1\n";
    return;
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  FOR(i, 1, 59) f[i] = (1LL << i + 1) - 2;
  while (T--) solve();
}