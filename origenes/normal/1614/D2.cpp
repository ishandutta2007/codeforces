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

const int maxn = 21234567;

bool vis[maxn];
int cnt[maxn];
ll f[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  vis[1] = true;
  vector<int> primes;
  FOR(i, 2, 2e7) {
    if (!vis[i]) primes.eb(i);
    for (auto p : primes) {
      if (ll(p) * i > 2e7) break;
      vis[p * i] = true;
      if (i % p == 0) break;
    }
  }
  int n; cin >> n;
  REP(_, n) {
    int x; cin >> x;
    for (int i = 1; sqr(i) <= x; i++) if (x % i == 0) {
      cnt[i]++;
      if (sqr(i) != x) cnt[x / i]++;
    }
  }
  ll ans = 0;
  ROF(i, 2e7, 1) {
    if (cnt[i]) f[i] = ll(i) * cnt[i];
    for (auto p : primes) {
      if (ll(p) * i > 2e7) break;
      chkmax(f[i], f[i * p] + ll(cnt[i] - cnt[i * p]) * i);
    }
    if (cnt[i] == n) chkmax(ans, f[i]);
  }
  cout << ans;
}