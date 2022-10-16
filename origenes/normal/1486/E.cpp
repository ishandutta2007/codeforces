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
ll f[maxn][51];
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
  reset(f, -1);
  set<tuple<ll, int, int>> q;
  f[1][0] = 0;
  q.emplace(0, 1, 0);
  while (!q.empty()) {
    auto [d, u, pw] = *q.begin();
    q.erase(q.begin());
    if (d > f[u][pw]) continue;
    for (auto [v, w] : G[u]) {
      if (pw == 0) {
        if (f[v][w] == -1 || f[v][w] > f[u][0]) {
          f[v][w] = f[u][0];
          q.emplace(f[v][w], v, w);
        }
      } else {
        if (f[v][0] == -1 || f[v][0] > f[u][pw] + sqr(pw + w)) {
          f[v][0] = f[u][pw] + sqr(pw + w);
          q.emplace(f[v][0], v, 0);
        }
      }
    }
  }
  FOR(i, 1, n) cout << f[i][0] << ' ';
}