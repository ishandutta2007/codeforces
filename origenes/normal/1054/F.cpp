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
const int inf = 0x3f3f3f3f;

struct Seg {
  int x, y1, y2;

  Seg (int x, int y1, int y2) : x(x), y1(y1), y2(y2) {}
};

int n, x[maxn], y[maxn], nxtx[maxn], nxty[maxn], match[maxn];
bool vis[maxn], X[maxn], Y[maxn], visx[maxn], visy[maxn];
pii pts[maxn];
vector<int> G[maxn];
vector<Seg> ansx, ansy;

bool dfs(int u) {
  if (u == -1) return true;
  if (vis[u]) return false;
  vis[u] = true;
  for (auto v : G[u]) if (dfs(match[v])) {
    match[v] = u;
    return true;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d",&pts[i]._1, &pts[i]._2);
  sort(pts + 1, pts + n + 1);
  FOR(i, 1, n) x[i] = pts[i]._1, y[i] = pts[i]._2;
  x[n + 1] = y[n + 1] = inf;
  FOR(i, 1, n) {
    nxtx[i] = nxty[i] = n + 1;
    FOR(j, 1, n) {
      if (x[j] == x[i] && y[j] > y[i] && y[j] < y[nxtx[i]]) nxtx[i] = j;
      if (y[j] == y[i] && x[j] > x[i] && x[j] < x[nxty[i]]) nxty[i] = j;
    }
  }
  FOR(i, 1, n) if (nxtx[i] != n + 1) {
    FOR(j, 1, n)
      if (nxty[j] != n + 1 && y[i] < y[j] && x[j] < x[i] && y[nxtx[i]] > y[j] && x[nxty[j]] > x[i]) G[i].eb(j);
  }
  reset(match, -1);
  FOR(i, 1, n) {
    reset(vis, false);
    if (!dfs(i)) {
      FOR(j, 1, n) if (vis[j]) {
        X[j] = true;
        for (auto u : G[j]) Y[u] = true;
      }
    }
  }
  FOR(i, 1, n) {
    if (!visx[i]) {
      int now = i;
      while (nxtx[now] != n + 1 && X[now]) now = nxtx[now], visx[now] = true;
      ansx.eb(x[i], y[i], y[now]);
    }
    if (!visy[i]) {
      int now = i;
      while (nxty[now] != n + 1 && !Y[now]) now = nxty[now], visy[now] = true;
      ansy.eb(y[i], x[i], x[now]);
    }
  }
  printf("%d\n", int(ansy.size()));
  for (auto it : ansy) printf("%d %d %d %d\n", it.y1, it.x, it.y2, it.x);
  printf("%d\n", int(ansx.size()));
  for (auto it : ansx) printf("%d %d %d %d\n", it.x, it.y1, it.x, it.y2);
}