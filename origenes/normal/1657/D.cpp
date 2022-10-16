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

const int maxn = 1123456;

int n, C;
ll f[maxn], pre[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> C;
  FOR(i, 1, n) {
    int c, d, h;
    cin >> c >> d >> h;
    chkmax(f[c], ll(d) * h);
  }
  FOR(i, 1, C) if (f[i]) for (int j = 1; i * j <= C; j++) chkmax(pre[i * j], j * f[i]);
  FOR(i, 1, C) chkmax(pre[i], pre[i - 1]);
  int m; cin >> m;
  while (m--) {
    ll d, h;
    cin >> d >> h;
    int lo = 1, hi = C, ans = -1;
    while (lo <= hi) {
      int mi = lo + hi >> 1;
      if (pre[mi] > d * h) {
        hi = mi - 1;
        ans = mi;
      } else lo = mi + 1;
    }
    cout << ans << ' ';
  }
}