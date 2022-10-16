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

const int maxn = 1123456;

vector<int> G[maxn], adj[maxn];
int in[maxn], out[maxn], c[maxn], f[2][maxn];
int clk, flip, cnt, r;

int desc(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

void dfs(int u) {
  in[u] = ++clk;
  for (auto v : G[u]) {
    if (c[v] == -1) {
      c[v] = c[u] ^ 1;
      adj[u].eb(v);
      dfs(v);
    } else if (in[v] < in[u]) {
      int d = c[v] ^ c[u];
      if (d == 0) {
        flip = c[u] ^ 1;
        cnt++;
      }
      f[d][v]--;
      f[d][u]++;
    }
  }
  out[u] = clk;
}

void dfs2(int u) {
  for (auto v : adj[u]) {
    dfs2(v);
    if (f[0][v] == cnt && f[1][v] == 1) {
      r = v;
      flip = c[u] ^ 1;
    }
    REP(i, 2) f[i][u] += f[i][v];
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) {
    G[i].clear();
    adj[i].clear();
    c[i] = -1;
    f[0][i] = f[1][i] = 0;
  }
  while (m--) {
    int u, v; cin >> u >> v;
    G[u].eb(v);
    G[v].eb(u);
  }
  c[1] = clk = flip = cnt = 0;
  dfs(1);
  if (cnt <= 1) {
    cout << "YES\n";
    FOR(i, 1, n) cout << (c[i] ^ flip);
    cout << '\n';
    return;
  }
  r = -1;
  dfs2(1);
  if (r == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  FOR(i, 1, n) cout << (c[i] ^ desc(r, i) ^ flip);
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