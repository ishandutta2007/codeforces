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

const int maxn = 112345;

int n;
ll a[maxn], b[maxn], c[maxn];

void solve() {
  cin >> n;
  FOR(i, 1, n) cin >> c[i];
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) cin >> b[i];
  ll pre = abs(a[2] - b[2]) + 2, ans = 0;
  FOR(i, 2, n) {
    chkmax(ans, pre + c[i] - 1);
    if (i != n) {
      if (a[i + 1] != b[i + 1]) {
        pre += min(a[i + 1], b[i + 1]) - 1 + c[i] - max(a[i + 1], b[i + 1]) + 2;
        chkmax(pre, max(a[i + 1], b[i + 1]) - min(a[i + 1], b[i + 1]) + 2);
      }
      else pre = 2;
    }
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