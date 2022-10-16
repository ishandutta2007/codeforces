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
set<int> G[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].emplace(v);
    G[v].emplace(u);
  }
  set<int> rem;
  FOR(i, 1, n) if (G[i].empty() || *G[i].rbegin() < i) rem.emplace(i);
  int q; cin >> q;
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int u, v;
      cin >> u >> v;
      G[u].emplace(v);
      G[v].emplace(u);
      if (*G[u].rbegin() > u) rem.erase(u);
      if (*G[v].rbegin() > v) rem.erase(v);
    } else if (op == 2) {
      int u, v;
      cin >> u >> v;
      G[u].erase(v);
      G[v].erase(u);
      if (G[u].empty() || *G[u].rbegin() < u) rem.emplace(u);
      if (G[v].empty() || *G[v].rbegin() < v) rem.emplace(v);
    } else cout << rem.size() << '\n';
  }
}