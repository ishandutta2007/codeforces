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

int n, m;
int c[maxn];
bool bad;
vector<pii> G[maxn];
vector<int> T[maxn];

void dfs(int u, int now) {
  c[u] = now;
  for (auto [v, w] : G[u]) {
    int nxt = now ^ w;
    if (c[v] == -1) dfs(v, nxt);
    else if (c[v] != nxt) bad = true;
  }
}

void solve() {
  map<pii, int> ans;
  cin >> n >> m;
  FOR(i, 1, n) {
    G[i].clear();
    T[i].clear();
    c[i] = -1;
  }
  bad = false;
  REP(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    T[u].eb(v); T[v].eb(u);
    if (u > v) swap(u, v);
    ans[mp(u, v)] = w;
    if (w != -1) {
      int par = __builtin_popcount(w) % 2;
      G[u].eb(v, par);
      G[v].eb(u, par);
    }
  }
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }
  FOR(i, 1, n) if (c[i] == -1) dfs(i, 0);
  if (bad) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (auto [k, v] : ans) {
    auto [x, y] = k;
    if (v == -1) v = c[x] ^ c[y];
    cout << x << ' ' << y << ' ' << v << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}