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

const int maxn = 312345;

int n, m;
int par[maxn], deg[maxn];
vector<int> G[maxn];

int Find(int x) {
  return par[x] == x ? par[x] : par[x] = Find(par[x]);
}

void Union(int x, int y) {
  x = Find(x), y = Find(y);
  par[x] = y;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  iota(par + 1, par + n + 1, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (Find(u) != Find(v)) {
      G[u].eb(v);
      G[v].eb(u);
      Union(u, v);
    }
  }
  int q; cin >> q;
  vector<pii> queries(q);
  for (auto &[u, v] : queries) {
    cin >> u >> v;
    deg[u]++, deg[v]++;
  }
  vector<int> odds;
  FOR(i, 1, n) if (deg[i] % 2 == 1) odds.eb(i);
  if (!odds.empty()) {
    cout << "NO\n";
    cout << odds.size() / 2;
    return 0;
  }
  cout << "YES\n";
  for (auto [u, v] : queries) {
    vector<int> pre(n + 1);
    queue<int> Q; Q.emplace(u);
    while (!Q.empty()) {
      auto x = Q.front(); Q.pop();
      if (x == v) break;
      for (auto y : G[x]) if (!pre[y]) {
        pre[y] = x;
        Q.emplace(y);
      }
    }
    vector<int> ans;
    for (; v != u; v = pre[v]) ans.eb(v);
    ans.eb(u);
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
  }
}