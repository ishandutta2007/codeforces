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

const int maxn = 312345;

vector<int> G[maxn], tab[maxn];
int n, m, ans = 1, s;
int c[maxn];
bool vis[maxn];

void dfs(int u, int par) {
  for (auto it : tab[u]) if (c[it]) vis[c[it]] = true;
  int now = 0;
  for (auto it : tab[u]) if (!c[it]) {
    while (vis[++now]);
    c[it] = now;
  }
  for (auto it : tab[u]) vis[c[it]] = false;
  for (auto v : G[u]) if (v != par) dfs(v, u);
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) {
    scanf("%d", &s);
    chkmax(ans, s);
    while (s--) {
      int u;
      scanf("%d", &u);
      tab[i].eb(u);
    }
  }
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(1, 0);
  printf("%d\n", ans);
  FOR(i, 1, m) printf("%d ", c[i] ? c[i] : 1);
}