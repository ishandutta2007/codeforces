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

const int maxn = 2123;

int n, clk, sccno;
int a[maxn][maxn], dfn[maxn], lowlink[maxn], comp[maxn];
bool vis[maxn];
stack<int> s;

void dfs(int u) {
  dfn[u] = lowlink[u] = ++clk;
  s.emplace(u);
  vis[u] = true;
  FOR(v, 1, n) if (a[u][v]) {
    if (!dfn[v]) {
      dfs(v);
      chkmin(lowlink[u], lowlink[v]);
    } else if (vis[v]) chkmin(lowlink[u], dfn[v]);
  }
  if (dfn[u] == lowlink[u]) {
    ++sccno;
    int pre;
    do {
      pre = s.top();
      comp[pre] = sccno;
      s.pop();
      vis[pre] = false;
    } while (pre != u);
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
  dfs(1);
  puts(count(comp + 1, comp + n + 1, 1) == n ? "YES" : "NO");
}