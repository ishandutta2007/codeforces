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

vector<int> X, Y, match, vis;
vector<vector<int>> G;

bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = 1;
  for (auto v : G[u]) if (match[v] == -1) {
    match[v] = u;
    return true;
  }
  for (auto v : G[u]) if (dfs(match[v])) {
    match[v] = u;
    return true;
  }
  return false;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  REP(i, n) {
    int t; cin >> t;
    if (3LL * t > m) X.eb(t);
    else Y.eb(t);
  }
  G.resize(size(X));
  match = vector<int>(size(Y), -1);
  REP(i, int(size(X))) REP(j, int(size(Y))) if (X[i] % Y[j] == 0 && 2LL * X[i] + Y[j] <= m) G[i].eb(j);
  int cnt = 0;
  REP(i, int(size(X))) {
    vis = vector<int>(size(X));
    cnt += dfs(i);
  }
  if (cnt < size(X)) {
    cout << -1;
    return 0;
  }
  cout << size(Y) << '\n';
  REP(j, int(size(Y))) {
    if (match[j] == -1) cout << 3 * Y[j] << ' ' << 2 * Y[j] << '\n';
    else cout << 2 * X[match[j]] + Y[j] << ' ' << X[match[j]] + Y[j] << '\n';
  }
}