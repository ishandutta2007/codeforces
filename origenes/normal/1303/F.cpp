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

const int maxn = 312;
const int maxq = 2123456;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, q;
int a[maxn][maxn], ans[maxq], par[maxn * maxn];
vector<tuple<int, int, int>> add[maxq], del[maxq];

inline int get(int x, int y) {
  return (x - 1) * m + y;
}

int Find(int x) {
  return par[x] ? par[x] = Find(par[x]) : x;
}

void update(const vector<tuple<int, int, int>> &vec, int d) {
  if (vec.empty()) return;
  FOR(i, 1, n) FOR(j, 1, m) a[i][j] = 0;
  REP(i, n * m + 1) par[i] = 0;
  for (auto [x, y, i] : vec) {
    a[x][y] = 1;
    int delta = 1;
    REP(j, 4) {
      int nx = x + dx[j], ny = y + dy[j];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny]) {
        int u = Find(get(x, y)), v = Find(get(nx, ny));
        if (u != v) {
          delta--;
          par[u] = v;
        }
      }
    }
    ans[i] += delta * d;
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  int C = 1;
  FOR(i, 1, q) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    if (a[x][y] == c) continue;
    add[c].eb(x, y, i);
    del[a[x][y]].eb(x, y, i);
    C = a[x][y] = c;
  }
  FOR(i, 1, n) FOR(j, 1, m) del[a[i][j]].eb(i, j, 0);
  REP(i, C + 1) reverse(all(del[i]));
  REP(i, C + 1) update(add[i], 1);
  REP(i, C + 1) update(del[i], -1);
  ans[0] = 1;
  FOR(i, 1, q) printf("%d\n", ans[i] += ans[i - 1]);
}