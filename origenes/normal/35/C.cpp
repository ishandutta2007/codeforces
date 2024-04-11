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

const int maxn = 2123;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool vis[maxn][maxn];
int n, m, k;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d", &n, &m);
  scanf("%d", &k);
  queue<pii> q;
  REP(i, k) {
    int x, y; scanf("%d%d", &x, &y);
    q.emplace(x, y);
    vis[x][y] = true;
  }
  int px = -1, py = -1;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    px = x, py = y;
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !vis[nx][ny]) {
        q.emplace(nx, ny);
        vis[nx][ny] = true;
      }
    }
  }
  printf("%d %d", px, py);
  fclose(stdout);
}