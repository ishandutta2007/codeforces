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

int n, m;
int a[maxn][maxn];
string s[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  REP(i, n) cin >> s[i];
  REP(i, n) REP(j, m) {
    a[i][j] = s[i][j] == 'B';
    if (i + 1 < n) a[i][j] += s[i + 1][j] == 'B';
    if (j + 1 < m) a[i][j] += s[i][j + 1] == 'B';
    if (i + 1 < n && j + 1 < m) a[i][j] += s[i + 1][j + 1] == 'B';
    a[i][j] %= 2;
  }
  int ans = 0;
  REP(i, n - 1) REP(j, m - 1) if (a[i][j] && a[i][m - 1] && a[n - 1][j] && a[n - 1][m - 1]) {
    ans = 3;
    a[i][j] = a[i][m - 1] = a[n - 1][j] = a[n - 1][m - 1] = 0;
  }
  REP(i, n) REP(j, m) ans += a[i][j];
  cout << ans;
}