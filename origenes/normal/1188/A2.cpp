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

const int maxn = 1123;

vector<int> G[maxn];
vector<pair<pii, int>> edges;
int n;

int dfs(int u, int par) {
  for (auto id : G[u]) if ((edges[id]._1._1 ^ edges[id]._1._2 ^ u) != par)
    return dfs(edges[id]._1._1 ^ edges[id]._1._2 ^ u, u);
  return u;
}

pii go(int u, int v) {
  if (G[u].size() == 1) return {u, u};
  vector<int> have;
  for (auto id : G[u]) if ((edges[id]._1._1 ^ edges[id]._1._2 ^ u) != v) {
    have.eb(dfs(edges[id]._1._1 ^ edges[id]._1._2 ^ u, u));
    if (have.size() == 2) return {have[0], have[1]};
  }
}

int main() {
  scanf("%d", &n);
  edges.resize(n - 1);
  REP(i, n - 1) {
    auto &x = edges[i];
    scanf("%d%d%d", &x._1._1, &x._1._2, &x._2);
    G[x._1._1].eb(i); G[x._1._2].eb(i);
  }
  FOR(i, 1, n) if (G[i].size() == 2) {
    puts("NO");
    return 0;
  }
  puts("YES");
  vector<pair<pii, int>> ans;
  REP(i, n - 1) {
    int u = edges[i]._1._1, v = edges[i]._1._2, w = edges[i]._2;
    auto st = go(u, v), en = go(v, u);
    ans.eb(mp(st._1, en._1), w / 2); ans.eb(mp(st._2, en._2), w / 2);
    if (st._1 != st._2) ans.eb(st, -w / 2);
    if (en._1 != en._2) ans.eb(en, -w / 2);
  }
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d %d %d\n", x._1._1, x._1._2, x._2);
}