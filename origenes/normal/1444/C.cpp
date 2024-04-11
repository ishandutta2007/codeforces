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

const int maxn = 512345;

int n, m, k;
bool bipartite[maxn], rev[maxn];
int c[maxn], sz[maxn], par[maxn];
stack<tuple<int, int, int>> S;
map<int, vector<pii>> edges[maxn];

int Find(int x) {
  return par[x] == x ? x : Find(par[x]);
}

bool Get(int x) {
  return par[x] == x ? false : rev[x] ^ Get(par[x]);
}

bool Union(int u, int v) {
  bool cu = Get(u), cv = Get(v);
  u = Find(u), v = Find(v);
  if (u == v) return cu != cv;
  if (sz[u] < sz[v]) {
    swap(u, v);
    swap(cu, cv);
  }
  S.emplace(u, v, rev[v]);
  par[v] = u;
  sz[u] += sz[v];
  if (cu == cv) rev[v] = true;
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> k;
  FOR(i, 1, n) cin >> c[i];
  fill(sz + 1, sz + n + 1, 1);
  fill(bipartite + 1, bipartite + k + 1, true);
  iota(par + 1, par + n + 1, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (c[u] < c[v]) swap(u, v);
    if (c[u] != c[v]) edges[c[u]][c[v]].eb(u, v);
    else if (!Union(u, v)) bipartite[c[u]] = false;
  }
  ll ans = count(bipartite + 1, bipartite + k + 1, true);
  ans = ans * (ans - 1) / 2;
  FOR(i, 1, k) if (bipartite[i]) for (auto [j, E] : edges[i]) if (bipartite[j]) {
    int ini = S.size();
    for (auto [u, v] : E) if (!Union(u, v)) {
      ans--;
      break;
    }
    while (S.size() > ini) {
      auto [u, v, r] = S.top(); S.pop();
      par[v] = v;
      sz[u] -= sz[v];
      rev[v] = r;
    }
  }
  cout << ans;
}