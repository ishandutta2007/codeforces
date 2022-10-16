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

int p, n, clk;
int ve[1 << 17], vv[1 << 17];
vector<int> G[1 << 17];
pii edges[1 << 17];

void dfs(int u, int par) {
  for (auto i : G[u]) if (i != par) {
    int v = edges[i]._1 ^ edges[i]._2 ^ u;
    if (vv[u] & n) {
      ve[i] = n + clk;
      vv[v] = clk;
    } else {
      vv[v] = n + clk;
      ve[i] = clk;
    }
    clk++;
    dfs(v, i);
  }
}

void solve() {
  cin >> p;
  n = 1 << p;
  REP(i, n) G[i].clear();
  REP(i, n - 1) {
    auto &[u, v] = edges[i];
    cin >> u >> v;
    u--, v--;
    G[u].eb(i);
    G[v].eb(i);
  }
  clk = 1;
  vv[0] = n;
  dfs(0, -1);
  cout << "1\n";
  REP(i, n) cout << vv[i] << ' ';
  cout << '\n';
  REP(i, n - 1) cout << ve[i] << ' ';
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}