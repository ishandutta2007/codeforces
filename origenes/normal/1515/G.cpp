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

vector<pii> G1[maxn], G2[maxn];
int n, m, q, scc;
ll f[maxn], g[maxn];
int comp[maxn], vis[maxn];
vector<int> seq;

void dfs1(int u) {
  vis[u] = 1;
  for (auto [v, _] : G1[u]) if (!vis[v]) dfs1(v);
  seq.eb(u);
}

void dfs2(int u) {
  vis[u] = 2;
  for (auto [v, l] : G2[u]) {
    if (vis[v] != 2) {
      comp[v] = scc;
      f[v] = f[u] + l;
      dfs2(v);
    } else if (comp[v] == comp[u]) {
      g[scc] = gcd(g[scc], f[u] - f[v] + l);
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  while (m--) {
    int a, b, l;
    cin >> a >> b >> l;
    G1[a].eb(b, l);
    G2[b].eb(a, l);
  }
  FOR(i, 1, n) if (!vis[i]) dfs1(i);
  reverse(all(seq));
  for (auto i : seq) if (vis[i] != 2) {
    comp[i] = ++scc;
    dfs2(i);
  }
  cin >> q;
  while (q--) {
    int v, s, t;
    cin >> v >> s >> t;
    if (s % gcd(g[comp[v]], t) == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}