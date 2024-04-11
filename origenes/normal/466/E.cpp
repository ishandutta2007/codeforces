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

const int maxn = 112345;

vector<pii> ch[maxn];
vector<pii> q;
int n, m, tot, cc[maxn], dep[maxn], anc[maxn][17], clk[maxn][17], bit[17];
pii evt[maxn];
bool nr[maxn];

void dfs(int u, int par, int t) {
  dep[u] = dep[par] + 1;
  cc[u] = cc[par];
  anc[u][0] = par;
  clk[u][0] = t;
  FOR(i, 1, 16) {
    anc[u][i] = anc[anc[u][i - 1]][i - 1];
    clk[u][i] = max(clk[u][i - 1], clk[anc[u][i - 1]][i - 1]);
  }
  for (auto _ : ch[u]) {
    int v = _._1, tt = _._2;
    dfs(v, u, tt);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      ch[v].eb(u, i);
      nr[u] = true;
    } else if (op == 2) {
      int u;
      scanf("%d", &u);
      evt[++tot] = {u, i};
    } else {
      int u, idx;
      scanf("%d%d", &u, &idx);
      q.eb(u, idx);
    }
  }
  REP(i, 17) bit[i] = 1 << i;
  int ncc = 0;
  FOR(i, 1, n) if (!nr[i]) {
    cc[0] = ++ncc;
    dfs(i, 0, 0);
  }
  for (auto it : q) {
    int u = it._1, v = evt[it._2]._1, lim = evt[it._2]._2;
    if (cc[u] != cc[v] || dep[u] > dep[v]) {
      puts("NO");
      continue;
    }
    int last = 0;
    ROF(i, 16, 0) if (dep[v] - dep[u] >= bit[i]) {
      chkmax(last, clk[v][i]);
      v = anc[v][i];
    }
    puts(u == v && last <= lim ? "YES" : "NO");
  }
}