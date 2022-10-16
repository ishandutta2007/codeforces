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
set<int> val[maxn];
int s[maxn], a[maxn], n, ans;

void dfs(int u, int par) {
  s[u] = s[par] ^ a[u];
  val[u].emplace(s[u]);
  bool bad = false;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    if (size(val[u]) < size(val[v])) swap(val[u], val[v]);
    for (auto x : val[v]) bad |= val[u].count(x ^ a[u]);
    for (auto x : val[v]) val[u].emplace(x);
  }
  if (bad) {
    ans++;
    val[u].clear();
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  cout << ans;
}