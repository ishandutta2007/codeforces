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

const int maxn = 312345;

int n, ans;
vector<int> G[maxn];

int dfs(int u, int par) {
  int mx1 = 0, mx2 = 0, deg = par != 0;
  for (auto v : G[u]) if (v != par) {
    int cur = dfs(v, u);
    deg++;
    if (cur > mx1) {
      mx2 = mx1;
      mx1 = cur;
    } else if (cur > mx2) mx2 = cur;
  }
  chkmax(ans, mx1 + mx2 + deg - 1);
  return mx1 + deg - 1;
}

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) G[i].clear();
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v); G[v].eb(u);
  }
  ans = 0;
  dfs(1, 0);
  printf("%d\n", ans + 2);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}