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

int n;
vector<int> G[maxn];
bool bud[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (!bud[v]) bud[u] = true;
  }
}

void solve() {
  cin >> n;
  FOR(i, 1, n) G[i].clear();
  FOR(i, 1, n) bud[i] = false;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  bud[1] = false;
  bool leaf = false;
  for (auto u : G[1]) if (!bud[u]) leaf = true;
  int buds = 0;
  FOR(i, 1, n) buds += bud[i];
  cout << n - 2 * buds - leaf << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}