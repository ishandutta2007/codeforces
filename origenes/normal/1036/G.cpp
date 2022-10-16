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

const int maxn = 1123456;
const int maxc = 20;

vector<int> G[maxn], s, t;

int indeg[maxn], outdeg[maxn], reach[1 << maxc], vis[maxn];
int n, m, c;

void dfs(int u, int now) {
  if (vis[u] == now) return;
  vis[u] = now;
  for (int v : G[u]) dfs(v, now);
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    indeg[v]++;
    outdeg[u]++;
  }
  FOR(i, 1, n) {
    if (!indeg[i]) s.eb(i);
    if (!outdeg[i]) t.eb(i);
  }
  assert(s.size() == t.size());
  c = s.size();
  REP(i, c) {
    dfs(s[i], i + 1);
    REP(j, c) if (vis[t[j]] == i + 1) reach[1 << i] |= 1 << j;
  }
  FOR(mask, 1, (1 << c) - 2) {
    if (!reach[mask]) {
      REP(i, c) if (mask & (1 << i)) {
        reach[mask] = reach[1 << i] | reach[mask ^ (1 << i)];
        break;
      }
    }
    if (__builtin_popcount(reach[mask]) <= __builtin_popcount(mask)) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}