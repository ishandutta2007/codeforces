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

int n, m, s;
vector<int> G[maxn];
int desc[maxn], f[maxn];

void print(int i, int last) {
  vector<int> ans;
  for (; i != s; i = f[i]) ans.eb(i);
  cout << size(ans) + 2 << '\n';
  cout << s;
  reverse(all(ans));
  for (auto x : ans) cout << ' ' << x;
  cout << ' ' << last << '\n';
}

void dfs(int u, int par, int st) {
  if (desc[u]) {
    cout << "Possible\n";
    print(par, u);
    print(f[u], u);
    exit(0);
  }
  f[u] = par;
  desc[u] = st;
  for (auto v : G[u]) if (v != s && desc[v] != st) dfs(v, u, st);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m >> s;
  while (m--) {
    int u, v; cin >> u >> v;
    G[u].eb(v);
  }
  for (auto u : G[s]) dfs(u, s, u);
  cout << "Impossible";
}