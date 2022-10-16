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

const int maxn = 18;

int n, m;
int f[maxn + 1][maxn + 1][1 << maxn], reach[maxn], s[maxn], a[maxn];
vector<int> G[maxn], seq;
bool vis[maxn], trace[maxn + 1][maxn + 1][1 << maxn];

void dfs1(int u) {
  vis[u] = true;
  for (auto v : G[u]) if (!vis[v]) dfs1(v);
  seq.eb(u);
}

void dfs2(int u) {
  vis[u] = true;
  for (auto v : G[u]) if (!vis[v]) dfs2(v);
}

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--, y--;
    G[x].eb(y);
    s[x] += w, s[y] -= w;
  }
  REP(i, n) if (!vis[i]) dfs1(i);
  REP(i, n) {
    reset(vis, 0);
    dfs2(i);
    REP(j, n) if (j != i && vis[j]) reach[i] |= 1 << j;
  }
  reverse(all(seq));
  reset(f, 0x3f);
  f[0][0][0] = 0;
  REP(i, n) REP(j, n + 1) REP(mask, 1 << n) if (f[i][j][mask] < 1e9) {
    if (j == n) {
      if (f[i + 1][0][mask] > f[i][j][mask]) {
        f[i + 1][0][mask] = f[i][j][mask];
        trace[i + 1][0][mask] = false;
      }
    } else {
      if (f[i][j + 1][mask] > f[i][j][mask]) {
        f[i][j + 1][mask] = f[i][j][mask];
        trace[i][j + 1][mask] = false;
      }
      int u = seq[j];
      if ((mask & (1 << u)) == 0 && (reach[u] & mask) == reach[u]) {
        int nmask = mask | (1 << u);
        if (f[i][j + 1][nmask] > f[i][j][mask] + i * s[u]) {
          f[i][j + 1][nmask] = f[i][j][mask] + i * s[u];
          trace[i][j + 1][nmask] = true;
        }
      }
    }
  }
  int i = n, j = 0, mask = (1 << n) - 1;
  while (i > 0 || j > 0) {
    if (!j) {
      j = n;
      i--;
    } else {
      if (trace[i][j][mask]) {
        int u = seq[j - 1];
        a[u] = i;
        mask ^= 1 << u;
      }
      j--;
    }
  }
  REP(i, n) printf("%d ", a[i]);
}