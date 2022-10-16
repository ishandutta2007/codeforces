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

int w[maxn], req[maxn];
bool vis[2 * maxn];
vector<pii> G[maxn];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", w + i);
  FOR(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].eb(y, i);
    G[y].eb(x, i);
    req[x]++, req[y]++;
  }
  queue<int> q;
  FOR(i, 1, n) if (req[i] <= w[i]) q.emplace(i);
  vector<int> ans;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto [v, i] : G[u]) if (!vis[i]) {
      vis[i] = true;
      ans.eb(i);
      if (--req[v] <= w[v]) q.emplace(v);
    }
  }
  if (ans.size() != m) {
    puts("DEAD");
    return 0;
  }
  puts("ALIVE");
  reverse(all(ans));
  for (auto x : ans) printf("%d ", x);
}