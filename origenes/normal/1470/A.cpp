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

const int maxn = 312345;

int n, m;
int k[maxn], c[maxn];

void solve() {
  cin >> n >> m;
  FOR(i, 1, n) cin >> k[i];
  FOR(i, 1, m) cin >> c[i];
  sort(k + 1, k + n + 1);
  ll ans = 0;
  FOR(i, 1, n) ans += c[k[i]];
  ll now = ans;
  ROF(i, n, 1) if (n - i + 1 <= m) {
    now -= c[k[i]];
    now += c[n - i + 1];
    chkmin(ans, now);
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