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

const int maxn = 612;

int n, m, q;
int w[maxn][maxn];
ll f[maxn][maxn], way[maxn][maxn];
bool vis[maxn][maxn];
vector<pii> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  reset(f, 0x3f);
  FOR(i, 1, n) f[i][i] = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cin >> w[u][v];
    f[u][v] = f[v][u] = w[v][u] = w[u][v];
  }
  FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) chkmin(f[i][j], f[i][k] + f[k][j]);
  cin >> q;
  while (q--) {
    int u, v, l;
    cin >> u >> v >> l;
    G[u].eb(v, l);
    G[v].eb(u, l);
  }
  reset(way, -1);
  FOR(i, 1, n) for (auto [j, l] : G[i]) FOR(v, 1, n) chkmax(way[i][v], l - f[v][j]);
  FOR(i, 1, n) FOR(u, 1, n) FOR(v, 1, n) if (w[u][v] && f[i][u] + w[u][v] <= way[i][v]) vis[u][v] = vis[v][u] = true;
  int ans = 0;
  FOR(i, 1, n) FOR(j, i + 1, n) if (vis[i][j]) ans++;
  cout << ans;
}