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

const int maxn = 112;

int n, m, k;
int a[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  REP(i, n) REP(j, m) cin >> a[i][j];
  int ans = k + 1;
  if (n <= k) {
    REP(mask, 1 << n) {
      int now = 0;
      REP(j, m) {
        int same = 0, diff = 0;
        REP(i, n) {
          if (((mask >> i) & 1) == a[i][j]) same++;
          else diff++;
        }
        now += min(same, diff);
      }
      chkmin(ans, now);
    }
  } else {
    REP(fixed, n) {
      int now = 0;
      REP(i, n) {
        int same = 0, diff = 0;
        REP(j, m) {
          if (a[i][j] == a[fixed][j]) same++;
          else diff++;
        }
        now += min(same, diff);
      }
      chkmin(ans, now);
    }
  }
  if (ans == k + 1) ans = -1;
  cout << ans;
}