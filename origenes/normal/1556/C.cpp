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

const int maxn = 1123;

int n;
ll mn[maxn][maxn], mx[maxn][maxn];
ll c[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> c[i];
  if (n % 2 == 1) n--;
  FOR(i, 1, n) FOR(j, 1, n) mx[i][j] = mn[i][j] = 1;
  for (int i = 1; i <= n; i += 2) {
    ll pre = 0, best = 0;
    FOR(j, i + 1, n) {
      if (j % 2 == 0) {
        chkmax(mn[i][j], -best);
        pre -= c[j];
        chkmin(best, pre);
      } else pre += c[j];
    }
  }
  for (int i = n; i >= 1; i -= 2) {
    ll suf = 0, best = 0;
    ROF(j, i - 1, 1) {
      if (j % 2 == 1) {
        chkmax(mx[j][i], -best);
        suf -= c[j];
        chkmin(best, suf);
      } else suf += c[j];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i += 2) for (int j = i + 1; j <= n; j += 2) {
    if (mn[i][j] <= c[i] && mx[i][j] <= c[j]) ans += min(c[i] - mn[i][j] + 1, c[j] - mx[i][j] + 1);
  }
  cout << ans << '\n';
}