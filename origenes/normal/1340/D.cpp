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

const int maxn = 112345;

vector<int> G[maxn];
int n, mx;
vector<pii> ans;

void dfs(int u, int par, int t) {
  bool flip = false;
  int T = t;
  ans.eb(u, t);
  for (auto v : G[u]) if (v != par) {
    if (t == mx) {
      flip = true;
      t = mx - G[u].size();
      ans.eb(u, t);
    }
    t++;
    dfs(v, u, t);
    ans.eb(u, t);
  }
  if (!flip && u != 1) ans.eb(u, T - 1);
}

int main() {
  scanf("%d", &n);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    G[v].eb(u);
  }
  FOR(i, 1, n) chkmax(mx, int(G[i].size()));
  dfs(1, 0, 0);
  printf("%d\n", int(ans.size()));
  for (auto [u, t] : ans) printf("%d %d\n", u, t);
}