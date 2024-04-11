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

const int maxn = 5123;

char a[maxn], b[maxn];
int f[maxn][maxn];
int n, m;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  scanf("%d%d", &n, &m);
  scanf("%s%s", a + 1, b + 1);
  FOR(i, 1, n) FOR(j, 1, m) {
    if (a[i] == b[j]) chkmax(f[i][j], f[i - 1][j - 1] + 2);
    chkmax(f[i][j], f[i - 1][j] - 1);
    chkmax(f[i][j], f[i][j - 1] - 1);
  }
  int ans = 0;
  FOR(i, 1, n) FOR(j, 1, m) chkmax(ans, f[i][j]);
  printf("%d", ans);
}