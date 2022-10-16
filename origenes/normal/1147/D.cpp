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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 1123;
const int MOD = 998244353;

int n, ans;
char s[maxn];

vector<pii> G[maxn << 1];
vector<int> adj[maxn << 1];
int vis[maxn << 1], par[maxn << 1], tab[maxn << 1], rec[maxn << 1], cc[maxn << 1], pw[maxn << 1];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline void add(int u, int v, int c) {
  G[u].eb(v, c);
  G[v].eb(u, c);
}

void build(int m) {
  FOR(i, 1, n + m + 2) G[i].clear();
  FOR(i, 1, m) {
    if (s[i] == '0') add(i, i + n, 0);
    else if (s[i] == '1') add(i + n, i, 1);
    if (m - i + 1 != i) G[i + n].eb(n + m + 1 - i, 0);
  }
  add(n + 1, m + n + 1, 1);
  add(n + 1, m + n + 2, 0);
  FOR(i, 1, n) if (i != n - i + 1) G[i].eb(n + 1 - i, 0);
  add(m + n + 1, n + m + 2, 1);
  FOR(i, m + 1, n) {
    if (s[i] == '0') {
      add(i, n + m + 1, 0);
      add(i, n + m + 2, 1);
    } else if (s[i] == '1') {
      add(i, n + m + 1, 1);
      add(i, n + m + 2, 0);
    }
  }
}

void dfs(int u, int clk, int fa) {
  vis[u] = clk;
  for (auto _ : G[u]) {
    int v = _._1, c = _._2;
    if (!c && vis[v] != clk) {
      par[v] = u;
      dfs(v, clk, fa);
    }
    if (c) adj[fa].eb(v);
  }
}

bool check(int id, int c) {
  cc[id] = c;
  int u = tab[id];
  bool ret = true;
  for (auto v : adj[u]) {
    if (cc[v] == -1) ret &= check(v, c ^ 1);
    else if (cc[v] == c) ret = false;
  }
  return ret;
}

int Find(int x) {
  return par[x] == x ? x : par[x] = Find(par[x]);
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  reverse(s + 1, s + n + 1);
  pw[0] = 1;
  FOR(i, 1, 2 * n) pw[i] = add(pw[i - 1], pw[i - 1]);
  FOR(i, 1, n - 1) {
    build(i);
    FOR(j, 1, n + i + 2) {
      par[j] = j;
      adj[j].clear();
    }
    FOR(j, 1, n + i + 2) if (vis[j] != i) dfs(j, i, j);
    int sz = 0;
    FOR(j, 1, n + i + 2) {
      if (Find(j) != j) continue;
      tab[++sz] = j;
      rec[j] = sz;
      for (auto &it : adj[j]) it = Find(it);
      sort(all(adj[j]));
      uni(adj[j]);
    }
    FOR(j, 1, n + i + 2) for (auto &it : adj[j]) it = rec[it];
    reset(cc, -1);
    int ncc = 0;
    bool flag = true;
    FOR(j, 1, sz) if (cc[j] == -1) {
      flag &= check(j, 0);
      ncc++;
    }
    if (flag) ans = add(ans, pw[ncc - 1]);
  }
  printf("%d", ans);
}