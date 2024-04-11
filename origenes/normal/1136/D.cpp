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

int p[maxn], vis[maxn], clk = 1, n, m, ans;
vector<int> G[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", p + i);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[v].eb(u);
  }
  for (int u : G[p[n]]) vis[u] = 1;
  ROF(i, n - 1, 1) {
    if (vis[p[i]] == clk) {
      ans++;
      continue;
    }
    for (int u : G[p[i]]) vis[u]++;
    clk++;
  }
  printf("%d", ans);
}