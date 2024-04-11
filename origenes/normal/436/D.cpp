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

int n, m;
int a[maxn], b[maxn], st[maxn], en[maxn], f[maxn], g[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1);
  FOR(i, 1, m) cin >> b[i];
  sort(b + 1, b + m + 1);
  FOR(i, 1, n) {
    if (i == 1 || a[i - 1] < a[i] - 1) st[i] = i;
    else st[i] = st[i - 1];
  }
  ROF(i, n, 1) {
    if (i == n || a[i + 1] > a[i] + 1) en[i] = i;
    else en[i] = en[i + 1];
  }
  FOR(i, 1, n) if (en[i] == i) {
    int j = lower_bound(b + 1, b + m + 1, a[i] + 1) - b - 1, jj = j;
    chkmax(f[i], max(f[st[i] - 1], g[st[i] - 1]));
    while (jj > 0) {
      int need = a[i] - b[jj], pi = i - need;
      if (pi < 1) break;
      pi = st[pi];
      chkmax(f[i], max(g[pi - 1], f[pi - 1]) + j - jj + 1);
      jj--;
    }
    for (jj = j + 1; jj <= m; jj++) {
      int need = b[jj] - a[i], ni = i + need;
      if (ni > n) break;
      ni = en[ni];
      chkmax(g[ni], f[i] + jj - j);
    }
  }
  cout << max(f[n], g[n]);
}