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

const int maxn = 212345;
const int maxa = 1123456;

int n, e, a[maxn];
bool vis[maxa];

void solve() {
  cin >> n >> e;
  REP(i, n) cin >> a[i];
  ll ans = 0;
  REP(r, e) {
    int ones = 0, now = 0;
    bool good = false;
    for (int i = 0; i * e + r < n; i++) {
      if (a[i * e + r] == 1) {
        now++;
        continue;
      }
      if (good) ans += ll(now + 1) * (ones + 1) - 1;
      good = !vis[a[i * e + r]];
      ones = now;
      now = 0;
    }
    if (good) ans += ll(now + 1) * (ones + 1) - 1;
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  FOR(i, 2, 1e6) if (!vis[i]) for (int j = i + i; j <= 1e6; j += i) vis[j] = true;
  int T; cin >> T;
  while (T--) solve();
}