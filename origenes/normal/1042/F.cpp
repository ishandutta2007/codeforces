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

const int maxn = 1123456;

int n, k, ans = 1;
vector<int> G[maxn], dep[maxn];

int dfs(int u, int par) {
  if (G[u].size() == 1) return 0;
  for (auto v : G[u]) if (v != par) dep[u].eb(dfs(v, u) + 1);
  sort(all(dep[u]));
  while (dep[u].size() >= 2 && dep[u].back() + dep[u][dep[u].size() - 2] > k) {
    ans++;
    dep[u].pop_back();
  }
  return dep[u].back();
}

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) if (G[i].size() > 1) {
    dfs(i, 0);
    break;
  }
  printf("%d", ans);
}