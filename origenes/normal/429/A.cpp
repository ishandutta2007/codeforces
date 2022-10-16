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

int n;
int goal[maxn], f[maxn][2][2];
bool flip[maxn][2][2];
vector<int> G[maxn];

void dfs(int u, int par) {
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    REP(i, 2) REP(j, 2) f[u][i][j] += f[v][j][i];
  }
  REP(i, 2) f[u][i][1 - goal[u]] = 1e9;
  REP(i, 2) REP(j, 2) if (f[u][i][1 - j] > f[u][i][j] + 1) {
    f[u][i][1 - j] = f[u][i][j] + 1;
    flip[u][i][1 - j] = true;
  }
}

void print(int u, int i, int j, int par) {
  if (flip[u][i][j]) {
    cout << u << '\n';
    j = 1 - j;
  }
  swap(i, j);
  for (auto v : G[u]) if (v != par) print(v, i, j, u);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) cin >> goal[i];
  FOR(i, 1, n) {
    int x; cin >> x;
    goal[i] ^= x;
  }
  dfs(1, 0);
  cout << f[1][0][0] << '\n';
  print(1, 0, 0, 0);
}