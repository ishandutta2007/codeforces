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

const int maxn = 512;

int n;
int ans[maxn][maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> ans[i][i];
  FOR(i, 1, n) {
    int x = i, y = i;
    REP(j, ans[i][i] - 1) {
      if (y > 1 && ans[x][y - 1] == 0) {
        ans[x][y - 1] = ans[i][i];
        y--;
      } else {
        assert(ans[x + 1][y] == 0);
        ans[x + 1][y] = ans[i][i];
        x++;
      }
    }
  }
  FOR(i, 1, n) {
    FOR(j, 1, i) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}