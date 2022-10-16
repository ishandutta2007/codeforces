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

const int maxn = 35;

int n, m;
int a[maxn][maxn];

void solve() {
  scanf("%d%d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
  int tot = n + m - 1;
  vector<vector<int>> cnt(tot, vector<int>(2));
  REP(i, n) REP(j, m) cnt[i + j][a[i][j]]++;
  int ans = 0;
  REP(i, tot / 2) {
    int now = min(cnt[i][0] + cnt[tot - i - 1][0], cnt[i][1] + cnt[tot - i - 1][1]);
    ans += now;
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}