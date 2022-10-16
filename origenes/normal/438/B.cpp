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

int n, m;
vector<int> G[maxn];
int par[maxn], sz[maxn], a[maxn], id[maxn];
bool en[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  iota(id + 1, id + n + 1, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, n) sz[i] = 1;
  sort(id + 1, id + n + 1, [](int x, int y) { return a[x] > a[y]; });
  ll ans = 0;
  FOR(i, 1, n) {
    int u = id[i];
    en[u] = true;
    ll tot = 0;
    set<int> roots;
    for (auto v : G[u]) if (en[v]) {
      int r = Find(v);
      roots.emplace(r);
    }
    for (auto r : roots) tot += sz[r];
    for (auto r : roots) {
      ans += (tot - sz[r]) * sz[r] * a[u];
      par[r] = u;
      sz[u] += sz[r];
    }
    ans += tot * 2 * a[u];
  }
  cout << fixed << setprecision(10) << double(ans) / n / (n - 1);
}