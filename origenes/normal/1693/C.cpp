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

int n, m, f[maxn], deg[maxn];
vector<int> G[maxn];
bool vis[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  reset(f, 0x3f);
  f[n] = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[v].eb(u);
    deg[u]++;
  }
  set<pii> q; q.emplace(0, n);
  while (!q.empty()) {
    auto u = q.begin()->_2;
    q.erase(q.begin());
    if (vis[u]) continue;
    vis[u] = true;
    for (auto v : G[u]) {
      if (f[v] > f[u] + deg[v]) {
        f[v] = f[u] + deg[v];
        q.emplace(f[v], v);
      }
      deg[v]--;
    }
  }
  cout << f[1];
}