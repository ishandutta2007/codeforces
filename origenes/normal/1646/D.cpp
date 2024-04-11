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

vector<int> G[maxn];
pii f[maxn][2];
int w[maxn];

pii operator+(const pii &lhs, const pii &rhs) {
  return {lhs._1 + rhs._1, lhs._2 + rhs._2};
}

void dfs(int u, int par) {
  f[u][1] = {1, -int(size(G[u]))};
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    f[u][1] = f[u][1] + f[v][0];
    f[u][0] = f[u][0] + max(f[v][0], f[v][1]);
  }
}

void dfs(int u, int par, bool good) {
  if (good && f[u][1] > f[u][0]) {
    w[u] = size(G[u]);
    for (auto v : G[u]) if (v != par) dfs(v, u, false);
  } else {
    w[u] = 1;
    for (auto v : G[u]) if (v != par) dfs(v, u, true);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  if (n == 2) {
    cout << "2 2\n1 1";
    return 0;
  }
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  auto ans = max(f[1][0], f[1][1]);
  cout << ans._1 << ' ' << -ans._2 + n - ans._1 << '\n';
  dfs(1, 0, true);
  FOR(i, 1, n) cout << w[i] << ' ';
}