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
const int MOD = 1e9 + 7;

int n;
int b[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> b[i];
  ll s = 0, ans = 1;
  map<ll, ll> f;
  f[0] = 1;
  FOR(i, 1, n) {
    ll p = (ans - f[s]) % MOD;
    s -= b[i];
    ans = (ans + p) % MOD;
    f[b[i] + s] = (f[b[i] + s] + p) % MOD;
  }
  if (ans < 0) ans += MOD;
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