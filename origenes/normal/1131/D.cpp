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

const int maxn = 1123;

int n, m, p[maxn * 2], deg[maxn * 2], ans[maxn * 2], res[2][maxn];
char s[maxn][maxn];
bool adj[maxn * 2][maxn * 2];

int Find(int x) {
  return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int u, int v) {
  int pu = Find(u), pv = Find(v);
  if (pu == pv) return;
  p[pu] = pv;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n + m) p[i] = i;
  FOR(i, 1, n) {
    scanf("%s", s[i] + 1);
    FOR(j, 1, m) if (s[i][j] == '=') Union(i, j + n);
  }
  FOR(i, 1, n) FOR(j, 1, m) {
      if (s[i][j] == '<') {
        int pi = Find(i), pj = Find(j + n);
        if (!adj[pi][pj]) {
          deg[pj]++;
          adj[pi][pj] = true;
        }
      } else if (s[i][j] == '>') {
        int pi = Find(i), pj = Find(j + n);
        if (!adj[pj][pi]) {
          adj[pj][pi] = true;
          deg[pi]++;
        }
      }
    }
  queue<pii> q;
  FOR(i, 1, n + m) if (Find(i) == i && !deg[i]) q.push(mp(i, 1));
  while (!q.empty()) {
    auto now = q.front(); q.pop();
    int u = now._1, a = now._2;
    ans[u] = a;
    FOR(v, 1, n + m) if (adj[u][v] && !(--deg[v])) q.push(mp(v, a + 1));
  }
  FOR(i, 1, n) {
    res[0][i] = ans[Find(i)];
    if (!res[0][i]) {
      puts("No");
      return 0;
    }
  }
  FOR(i, 1, m) {
    res[1][i] = ans[Find(i + n)];
    if (!res[1][i]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  FOR(i, 1, n) printf("%d ", res[0][i]);
  puts("");
  FOR(i, 1, m) printf("%d ", res[1][i]);
}