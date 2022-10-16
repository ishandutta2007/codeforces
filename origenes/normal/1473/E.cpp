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

ll f[maxn][2][2];
int n, m;
vector<pii> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  reset(f, 0x3f);
  f[1][0][0] = 0;
  set<tuple<ll, int, int, int>> q;
  q.emplace(0, 1, 0, 0);
  while (!q.empty()) {
    auto [d, u, i, j] = *q.begin(); q.erase(q.begin());
    if (f[u][i][j] < d) continue;
    for (auto [v, w] : G[u]) {
      FOR(ni, i, 1) FOR(nj, j, 1) {
        if ((ni == i) == (nj == j)) {
          if (f[v][ni][nj] > f[u][i][j] + w) {
            f[v][ni][nj] = f[u][i][j] + w;
            q.emplace(f[v][ni][nj], v, ni, nj);
          }
        } else if (ni != i) {
          if (f[v][ni][nj] > f[u][i][j]) {
            f[v][ni][nj] = f[u][i][j];
            q.emplace(f[v][ni][nj], v, ni, nj);
          }
        } else {
          if (f[v][ni][nj] > f[u][i][j] + w + w) {
            f[v][ni][nj] = f[u][i][j] + w + w;
            q.emplace(f[v][ni][nj], v, ni, nj);
          }
        }
      }
    }
  }
  FOR(i, 2, n) cout << f[i][1][1] << ' ';
}