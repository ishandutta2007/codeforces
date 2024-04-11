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

int n, k, need[maxn];
vector<int> G[maxn], ans;
bool vis[maxn], Lock[maxn];

void dfs(int u) {
  if (Lock[u]) {
    puts("-1");
    exit(0);
  }
  if (vis[u]) return;
  Lock[u] = vis[u] = true;
  for (auto v : G[u]) dfs(v);
  ans.eb(u);
  Lock[u] = false;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, k) scanf("%d", need + i);
  FOR(i, 1, n) {
    int t; scanf("%d", &t);
    while (t--) {
      int j; scanf("%d", &j);
      G[i].eb(j);
    }
  }
  FOR(i, 1, k) dfs(need[i]);
  printf("%d\n", int(ans.size()));
  for (auto x : ans) printf("%d ", x);
}