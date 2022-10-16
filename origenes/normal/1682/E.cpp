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

vector<pii> events[maxn];
vector<int> G[maxn];
int p[maxn], pos[maxn], deg[maxn];
bool vis[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) cin >> p[i];
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    events[u].eb(i, v);
    events[v].eb(i, u);
  }
  FOR(i, 1, n) if (!vis[i]) {
    vis[i] = true;
    vector<int> cyc{i};
    int nex = i;
    for (int j = 1; p[nex] != i; j++) {
      nex = p[nex];
      vis[nex] = true;
      pos[nex] = j;
      cyc.eb(nex);
    }
    int sz = size(cyc);
    vector<int> heads;
    REP(j, sz) {
      int u = cyc[j];
      sort(all(events[u]), [&](auto x, auto y) {
        int a = x._2, b = y._2;
        return (pos[a] - j + sz) % sz < (pos[b] - j + sz) % sz;
      });
      if (!events[u].empty()) heads.eb(events[u].front()._1);
      FOR(k, 1, int(size(events[u])) - 1) {
        G[events[u][k - 1]._1].eb(events[u][k]._1);
        deg[events[u][k]._1]++;
      }
    }
    queue<int> q;
    for (auto e : heads) if (deg[e] == 0) {
      q.emplace(e);
      deg[e] = -1;
    }
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      cout << u << ' ';
      for (auto v : G[u]) if (!--deg[v]) q.emplace(v);
    }
  }
}