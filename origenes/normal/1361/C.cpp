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

int n, a[maxn], mask;
bool vis[maxn];
vector<int> G[maxn], ans;

void dfs(int u) {
  while (!G[u].empty()) {
    int v = G[u].back(); G[u].pop_back();
    if (vis[v]) continue;
    vis[v] = vis[v ^ 1] = true;
    dfs(a[v ^ 1] & mask);
    ans.eb(v ^ 1); ans.eb(v);
  }
}

bool check(int bit) {
  mask = (1 << bit) - 1;
  REP(i, 1 << bit) G[i].clear();
  REP(i, n << 1) {
    G[a[i] & mask].eb(i);
    vis[i] = false;
  }
  REP(i, 1 << bit) if (G[i].size() & 1) return false;
  ans.clear();
  dfs(a[0] & mask);
  return ans.size() == 2 * n;
}

int main() {
  scanf("%d", &n);
  REP(i, n << 1) scanf("%d", a + i);
  ROF(i, 20, 0) if (check(i)) {
    printf("%d\n", i);
    for (auto x : ans) printf("%d ", x + 1);
    return 0;
  }
}