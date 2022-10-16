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
ll a[maxn], x;
int par[maxn];
pii e[maxn];
vector<int> G[maxn];

int Find(int u) {
  return par[u] == u ? u : par[u] = Find(par[u]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> x;
  FOR(i, 1, n) cin >> a[i];
  if (accumulate(a + 1, a + n + 1, 0LL) < (n - 1) * x) {
    cout << "NO";
    return 0;
  }
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, m) {
    int u, v; cin >> u >> v;
    if (Find(u) == Find(v)) continue;
    G[u].eb(i);
    G[v].eb(i);
    par[u] = v;
    e[i] = {u, v};
  }
  iota(par + 1, par + n + 1, 1);
  priority_queue<pair<ll, int>> q;
  FOR(i, 1, n) q.emplace(a[i], i);
  cout << "YES\n";
  REP(_, n - 1) {
    int u;
    while (true) {
      u = q.top()._2;
      if (par[u] != u || a[u] != q.top()._1) q.pop();
      else break;
    }
    while (Find(e[G[u].back()]._1) == Find(e[G[u].back()]._2)) G[u].pop_back();
    cout << G[u].back() << '\n';
    int v; tie(u, v) = e[G[u].back()];
    u = Find(u), v = Find(v);
    if (G[u].size() < G[v].size()) swap(u, v);
    a[u] = a[u] + a[v] - x;
    q.emplace(a[u], u);
    par[v] = u;
    while (!G[v].empty()) {
      G[u].eb(G[v].back());
      G[v].pop_back();
    }
  }
}