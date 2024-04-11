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

const int maxn = 512;
const int maxm = maxn * maxn;

vector<int> G[maxn];
int n, m, deg[maxn], cur[maxn];
bool ok[maxn], vis[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].eb(v);
    deg[v]++;
  }
  queue<int> q;
  FOR(i, 1, n) if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    ok[u] = true;
    for (int v : G[u]) if (!(--deg[v])) q.push(v);
  }
  FOR(i, 1, n) if (!ok[i] && deg[i] == 1) {
      memcpy(cur, deg, sizeof(deg));
      reset(vis, 0);
      q.push(i);
      vis[i] = true;
      bool good = true;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = true;
        for (int v : G[u]) if (!vis[v] && !(--cur[v])) q.push(v);
      }
      FOR(j, 1, n) if (!ok[j] && !vis[j]) {
          good = false;
          break;
        }
      if (good) {
        puts("YES");
        return 0;
      }
    }
  FOR(i, 1, n) if (!ok[i]) {
      puts("NO");
      return 0;
    }
  puts("YES");
}