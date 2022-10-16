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

const int maxn = 5123;

vector<pii> G[maxn];
int ans = 1, c[maxn], n, m;
bool anc[maxn], vis[maxn];

void dfs(int u) {
  vis[u] = anc[u] = true;
  for (auto _ : G[u]) {
    int v = _._1, i = _._2;
    if (!vis[v]) dfs(v);
    else if (anc[v]) ans = c[i] = 2;
  }
  anc[u] = false;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v, i);
    c[i] = 1;
  }
  FOR(i, 1, n) if (!vis[i]) dfs(i);
  printf("%d\n", ans);
  FOR(i, 1, m) printf("%d ", c[i]);
}