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

int n, ans;
vector<int> G[maxn];
int a[maxn], sz[maxn], s[maxn];
map<int, int> cnt;

void dfs(int u, int par) {
  sz[u] = 1;
  for (auto v : G[u]) if (v != par) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void dfs(int u, int par, map<int, int> &pre) {
  int heavy = 0;
  for (auto v : G[u]) if (v != par && sz[v] > sz[heavy]) heavy = v;
  if (heavy) dfs(heavy, u, pre);
  map<int, int> aux;
  for (auto v : G[u]) if (v != par && v != heavy) {
    dfs(v, u, aux);
    for (auto [x, c] : aux) pre[x] += c;
    aux.clear();
  }
  pre[a[u]]++;
  if (pre[a[u]] != cnt[a[u]]) s[u]++;
  if (u != 1 && pre[a[par]] > 0) {
    s[1]++;
    s[u]--;
  }
}

void dfs2(int u, int par) {
  ans += s[u] == 0;
  for (auto v : G[u]) if (v != par) {
    s[v] += s[u];
    dfs2(v, u);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  REP(i, n - 1) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  map<int, int> aux;
  dfs(1, 0, aux);
  dfs2(1, 0);
  cout << ans;
}