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

const int maxn = 4123456;

int n, a[maxn], pre[maxn], suf[maxn];
bool vis[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    vis[a[i] - a[1]] = true;
  }
  pre[0] = -1;
  suf[int(4e6)] = 4e6;
  FOR(i, 1, 4e6) {
    if (vis[i]) pre[i] = i;
    else pre[i] = pre[i - 1];
  }
  ROF(i, 4e6 - 1, 1) {
    if (vis[i]) suf[i] = i;
    else suf[i] = suf[i + 1];
  }
  FOR(i, 1, a[n]) {
    if (i * ll(i + 1) < a[1]) continue;
    ll lo = 0, hi = i;
    if (a[1] > sqr(ll(i))) lo = a[1] - sqr(i);
    ll l = 0, r = i;
    FOR(j, i, a[n]) {
      if (pre[r] >= l) chkmin(hi, r - pre[r]);
      l += 2 * j + 1;
      if (suf[r + 1] < l) chkmax(lo, l - suf[r + 1]);
      r += 2 * j + 2;
      if (l > a[n] - a[1]) break;
    }
    if (lo <= hi) {
      cout << sqr(ll(i)) + lo - a[1];
      return 0;
    }
  }
}