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

const int maxn = 512345;

vector<int> G[maxn], ord[maxn];
int n, m, last[maxn], clk[maxn];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) {
    int t; scanf("%d", &t);
    ord[t].eb(i);
  }
  vector<int> ans;
  FOR(i, 1, n) for (auto u : ord[i]) {
    for (auto v : G[u]) last[clk[v]] = u;
    clk[u] = 1;
    while (last[clk[u]] == u) clk[u]++;
    if (clk[u] != i) {
      puts("-1");
      return 0;
    }
    ans.eb(u);
  }
  for (auto u : ans) printf("%d ", u);
}