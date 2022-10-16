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

int n;
ll a[maxn], odd[maxn], even[maxn], diff[maxn], suf[maxn], pre[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  odd[1] = a[1];
  for (int i = 3; i <= n; i += 2) odd[i] = odd[i - 2] + a[i];
  even[2] = a[2];
  for (int i = 2; i <= n; i += 2) even[i] = even[i - 2] + a[i];
  FOR(i, 1, n) diff[i] = a[i] - diff[i - 1];
  ROF(i, n, 1) {
    suf[i] = diff[i];
    if (i <= n - 2) chkmin(suf[i], suf[i + 2]);
  }
  FOR(i, 1, n) {
    pre[i] = diff[i];
    if (i >= 3) chkmin(pre[i], pre[i - 2]);
  }
  if (pre[n] >= 0 && pre[n - 1] >= 0 && diff[n] == 0) {
    cout << "YES\n";
    return;
  }
  FOR(i, 1, n - 1) {
    if (pre[i - 1] < 0) break;
    ll d = a[i + 1] - a[i];
    if (diff[i] + d < 0) continue;
    if (diff[i + 1] - 2 * d < 0) continue;
    bool fi = false;
    if (i % 2 == n % 2) fi = true;
    ll nd = diff[n];
    if (fi) nd += 2 * d;
    else nd -= 2 * d;
    if (nd != 0) continue;
    if ((i + 2 > n || suf[i + 2] + 2 * d >= 0) && suf[i + 1] - 2 * d >= 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}