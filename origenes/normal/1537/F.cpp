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
ll from[maxn], to[maxn], change[maxn];
bool odd;
vector<int> G[maxn];

void dfs(int u, int val) {
  c[u] = val;
  for (auto v : G[u]) {
    if (c[v] == -1) dfs(v, 1 - val);
    if (c[v] == val) odd = true;
  }
}

void solve() {
  cin >> n >> m;
  FOR(i, 1, n) cin >> from[i];
  FOR(i, 1, n) cin >> to[i];
  FOR(i, 1, n) change[i] = to[i] - from[i];
  FOR(i, 1, n) G[i].clear();
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) c[i] = -1;
  odd = false;
  dfs(1, 0);
  if (odd) {
    ll delta = 0;
    FOR(i, 1, n) delta += change[i];
    if (delta % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
  } else {
    vector<ll> zeros, ones;
    FOR(i, 1, n) {
      if (c[i] == 0) zeros.eb(change[i]);
      else ones.eb(change[i]);
    }
    ll &d = ones[0];
    for (auto x : zeros) d -= x;
    ll tot = 0;
    for (auto x : ones) tot += x;
    if (tot == 0) cout << "YES\n";
    else cout << "NO\n";
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