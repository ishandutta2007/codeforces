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
int sz[maxn], fib[40], rf[maxn];
set<int> G[maxn];

void dfs(int u, int par) {
  sz[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

pii cut(int u, int par, int n1, int n2) {
  for (auto v : G[u]) if (v != par) {
    if (sz[v] == n1 || sz[v] == n2) return {v, u};
    auto rv = cut(v, u, n1, n2);
    if (rv != mp(-1, -1)) return rv;
  }
  return {-1, -1};
}

bool solve(int r, int tot) {
  if (tot <= 3) return true;
  dfs(r, 0);
  int id = rf[tot];
  auto [u, v] = cut(r, 0, fib[id - 1], fib[id - 2]);
  if (u == -1) return false;
  G[u].erase(v);
  G[v].erase(u);
  if (sz[v] == fib[id - 1] || sz[u] == fib[id - 2]) swap(u, v);
  return solve(u, fib[id - 1]) && solve(v, fib[id - 2]);
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
    G[u].emplace(v);
    G[v].emplace(u);
  }
  fib[0] = fib[1] = 1;
  for (int i = 1; fib[i] <= n; i++) fib[i + 1] = fib[i] + fib[i - 1];
  for (int i = 2; fib[i] <= n; i++) rf[fib[i]] = i;
  if (n > 3 && !rf[n]) {
    cout << "NO";
    return 0;
  }
  cout << (solve(1, n) ? "YES" : "NO");
}