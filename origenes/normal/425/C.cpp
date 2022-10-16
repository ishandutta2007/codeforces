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

int n, m, s, e;
int a[maxn], b[maxn], last[maxn], f[2][312];
vector<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> s >> e;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, m) cin >> b[i];
  FOR(i, 1, m) {
    G[b[i]].eb(i);
    last[b[i]] = i;
  }
  reset(f, 0x3f);
  f[0][0] = 0;
  int ans = 0;
  FOR(i, 1, n) {
    int now = i & 1, pre = 1 - now;
    reset(f[now], 0x3f);
    for (int j = 0; j * e <= s; j++) f[now][j] = f[pre][j];
    if (last[a[i]]) for (int j = 0; (j + 1) * e <= s; j++) {
      int lo = f[pre][j];
      if (lo < m) {
        auto it = lower_bound(all(G[a[i]]), lo + 1);
        if (it != G[a[i]].end()) {
          chkmin(f[now][j + 1], *it);
          int cost = i + f[now][j + 1];
          if (cost + (j + 1) * e <= s) chkmax(ans, j + 1);
        }
      }
    }
  }
  cout << ans;
}