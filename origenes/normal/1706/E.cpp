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

int par[maxn], f[maxn][17];
set<int> ver[maxn];

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int query(int l, int r) {
  int k = 0;
  while ((1 << k + 1) <= r - l + 1) k++;
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  iota(par + 1, par + n + 1, 1);
  FOR(i, 1, n) ver[i] = {i};
  FOR(i, 1, m) {
    int u, v;
    cin >> u >> v;
    u = Find(u), v = Find(v);
    if (u == v) continue;
    if (size(ver[u]) > size(ver[v])) swap(u, v);
    par[u] = v;
    for (auto x : ver[u]) {
      auto it = ver[v].lower_bound(x);
      if (it != ver[v].end() && *it == x + 1) f[*it][0] = i;
      if (it != ver[v].begin()) {
        --it;
        if (*it == x - 1) f[x][0] = i;
      }
    }
    for (auto x : ver[u]) ver[v].emplace(x);
    ver[u].clear();
  }
  FOR(j, 1, 16) FOR(i, 2, n - (1 << j) + 1) f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << "0 ";
      continue;
    }
    cout << query(l + 1, r) << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}