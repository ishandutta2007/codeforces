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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  vector<pii> edges(m);
  vector<int> dep(n, -1);
  REP(i, m) {
    auto &[u, v] = edges[i];
    cin >> u >> v;
    u--, v--;
    G[u].eb(i); G[v].eb(i);
  }
  dep[0] = 0;
  string ans(m, '0');
  vector<int> par(n, -1), backs;
  function<void(int, int)> dfs = [&](int u, int e) {
    for (auto id : G[u]) if (id != e) {
      int v = edges[id]._1 ^ edges[id]._2 ^ u;
      if (dep[v] == -1) {
        dep[v] = dep[u] + 1;
        par[v] = id;
        dfs(v, id);
        ans[id] = '1';
      } else if (dep[v] < dep[u]) backs.eb(id);
    }
  };
  dfs(0, -1);
  if (size(backs) == 3) {
    vector<int> voi;
    for (auto id : backs) {
      voi.eb(edges[id]._1);
      voi.eb(edges[id]._2);
    }
    sort(all(voi), [&dep](int x, int y) { return dep[x] < dep[y]; });
    uni(voi);
    if (size(voi) == 3) {
      for (auto id : backs) if (edges[id]._1 == voi[2] || edges[id]._2 == voi[2]) {
        swap(ans[id], ans[par[voi[2]]]);
        break;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}