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

int n, m, c, q;
int par[maxn];
set<int> adj[maxn];
map<int, int> rec[maxn];
char op[5];

int Find(int x) {
  return x == par[x] ? x : par[x] = Find(par[x]);
}

void add(int u, int v, int w) {
  int pu = Find(u), pv = Find(v);
  adj[pu].emplace(v);
  adj[pv].emplace(u);
  if (!rec[u][w]) {
    rec[u][w] = v;
    return;
  }
  int pp = Find(rec[u][w]), qq = Find(v);
  if (pp == qq) return;
  if (adj[pp].size() < adj[qq].size()) swap(pp, qq);
  par[qq] = pp;
  for (auto it : adj[qq]) adj[pp].emplace(it);
  adj[qq].clear();
}

int main() {
  scanf("%d%d%d%d", &n, &m, &c, &q);
  FOR(i, 1, n) par[i] = i;
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  while (q--) {
    scanf("%s", op);
    if (op[0] == '+') {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add(u, v, w);
      add(v, u, w);
    } else {
      int u, v;
      scanf("%d%d", &u, &v);
      int pu = Find(u), pv = Find(v);
      puts(pu == pv || adj[pu].count(v) ? "Yes" : "No");
    }
  }
}