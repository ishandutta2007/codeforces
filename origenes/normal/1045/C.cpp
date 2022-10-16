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

int n, m, q, clk;
int in[maxn], out[maxn], st[maxn][19], dep[maxn];
bool vis[maxn];
vector<int> G[maxn];

void dfs(int u) {
  in[u] = ++clk;
  vis[u] = true;
  st[u][0] = u;
  for (auto v : G[u]) {
    if (!vis[v]) {
      dep[v] = dep[u] + 1;
      dfs(v);
    } else if (dep[v] < dep[st[u][0]]) st[u][0] = v;
  }
  out[u] = clk;
}

inline bool check(int u, int v) {
  return in[u] <= in[v] && out[v] <= out[u];
}

int dis(int u, int v) {
  int ans = 0;
  if (!check(u, v)) {
    ROF(i, 18, 0) if (!check(st[u][i], v)) {
      u = st[u][i];
      ans += 1 << i;
    }
    u = st[u][0];
    ans++;
  }
  if (!check(v, u)) {
    ROF(i, 18, 0) if (!check(st[v][i], u)) {
      v = st[v][i];
      ans += 1 << i;
    }
    ans++;
  }
  return ans;
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1);
  FOR(j, 1, 18) FOR(i, 1, n) st[i][j] = st[st[i][j - 1]][j - 1];
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", min(dis(u, v), dis(v, u)));
  }
}