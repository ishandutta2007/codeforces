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
const int MOD = 998244353;

int n;
ll ans;
ll a[maxn], s[maxn], ss[maxn];

void f(int st, int en) {
  ll p = 0, c = 0;
  if (st) p += a[1];
  if (en) c += a[n];
  int L = st + 1, R = n - en - 1;
  FOR(i, L, R) {
    c += a[i];
    int lo = -1, hi = (R - i) / 2;
    while (lo < hi) {
      int mi = (lo + hi + 1) >> 1, len = 2 * mi;
      if(c + ss[i + len] - ss[i] < p + s[R + 1] - s[i + len] + ss[i + len - 1] - ss[i - 1]) lo = mi;
      else hi = mi - 1;
    }
    ans = (ans + lo + 1) % MOD;
  }
}

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) {
    s[i] = s[i - 1] + a[i];
    ss[i] = ss[max(i - 2, 0)] + a[i];
  }
  ans = 0;
  FOR(i, 1, n) if (s[i] > s[n] - s[i]) ans++;
  REP(i, 2) REP(j, 2) f(i, j);
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