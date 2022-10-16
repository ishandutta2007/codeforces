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

const int maxn = 312345;

int a[maxn], ans[maxn];
int n;
vector<int> G[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) G[i] = {0};
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) G[a[i]].eb(i);
  FOR(i, 1, n) G[i].eb(n + 1);
  fill(ans, ans + n + 1, n + 1);
  FOR(i, 1, n) {
    int d = 0;
    FOR(j, 1, int(G[i].size()) - 1) chkmax(d, G[i][j] - G[i][j - 1]);
    chkmin(ans[d], i);
  }
  FOR(i, 1, n) {
    chkmin(ans[i], ans[i - 1]);
    printf("%d ", ans[i] == n + 1 ? -1 : ans[i]);
  }
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}