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

int n, p[maxn], f[maxn][2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> p[i];
  ll ans = 0;
  int last = n + 1;
  ROF(i, n, 1) {
    f[i][0] = n + 1, f[i][1] = 0;
    FOR(j, i + 1, n) {
      int g[2] = {0, n + 1};
      if (f[j - 1][1] < p[j]) chkmax(g[0], p[j - 1]);
      if (p[j - 1] < p[j]) chkmax(g[0], f[j - 1][0]);
      if (f[j - 1][0] > p[j]) chkmin(g[1], p[j - 1]);
      if (p[j - 1] > p[j]) chkmin(g[1], f[j - 1][1]);
      if (g[0] == f[j][0] && g[1] == f[j][1]) break;
      f[j][0] = g[0], f[j][1] = g[1];
      if (g[0] == 0 && g[1] == n + 1) {
        last = j;
        break;
      }
    }
    ans += last - i;
  }
  cout << ans;
}