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

const int maxn = 512345;

int n, a[maxn];

int solve(int peak) {
  vector<int> f(n + 1, 1e9 + 1), g(n + 1, 1e9 + 1), mn(n + 1, 1e9 + 1), mx(n + 1, -1e9);
  f[1] = 0;
  FOR(i, 2, peak) {
    if (a[i - 1] < a[i]) chkmin(f[i], f[i - 1]);
    if (f[i - 1] < a[i]) chkmin(f[i], a[i - 1]);
  }
  g[n] = 0;
  ROF(i, n - 1, peak + 1) {
    if (a[i] > a[i + 1]) chkmin(g[i], g[i + 1]);
    if (a[i] > g[i + 1]) chkmin(g[i], a[i + 1]);
  }
  mn[peak] = f[peak];
  int ret = 0;
  FOR(i, peak + 1, n) {
    if (a[i - 1] > a[i]) chkmin(mn[i], mn[i - 1]);
    if (mx[i - 1] > a[i]) chkmin(mn[i], a[i - 1]);
    if (a[i - 1] < a[i]) chkmax(mx[i], mx[i - 1]);
    if (mn[i - 1] < a[i]) chkmax(mx[i], a[i - 1]);
    if (mx[i] > g[i]) ret++;
  }
  return ret;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  int p = max_element(a + 1, a + n + 1) - a, ans = 0;
  ans += solve(p);
  reverse(a + 1, a + n + 1);
  ans += solve(n - p + 1);
  cout << ans;
}